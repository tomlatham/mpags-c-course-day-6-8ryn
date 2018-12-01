#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

// Standard library includes
#include <string>

// Our project headers
#include "CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the purely abstract Cipher base class and the InvalidKey exception
 */

/**
 * \class Cipher
 * \brief Defines the interface for a cipher
 *
 * A purely abstract base class that defines the interface for a cipher
 *
 * It can be used as follows:
 * \code{.cpp}
 * class MyCipher : public Cipher {...};
 * \endcode
 */
class Cipher {
  public:
    /**
     * Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    virtual std::string applyCipher( const std::string& inputText, const CipherMode cipherMode ) const = 0;

    /// Default constructor
    Cipher() = default;
    /// Default copy constructor
    Cipher(const Cipher& rhs) = default;
    /// Default move constructor
    Cipher(Cipher&& rhs) = default;
    /// Default copy assignment operator
    Cipher& operator=(const Cipher& rhs) = default;
    /// Default move assignment operator
    Cipher& operator=(Cipher&& rhs) = default;
    /// Make the default destructor virtual
    virtual ~Cipher() = default;
};

/**
 * \exception InvalidKey
 * \brief An exception thrown when an invalid key is provided to a cipher
 */
class InvalidKey : public std::invalid_argument {
public:
  /**
   * Create a new InvalidKey exception
   *
   * \param msg a message conveying the details of the invalid key
   */
  InvalidKey( const std::string& msg) :
    std::invalid_argument(msg){}
};

#endif
