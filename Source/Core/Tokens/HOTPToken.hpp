#ifndef HOTPTOKEN_HPP
#define HOTPTOKEN_HPP

#include "OTPToken.hpp"

class HOTPToken final : public OTPToken
{
public:
    HOTPToken();
    HOTPToken(const Label &label);

    static const DigitType DEFAULT_DIGIT_LENGTH;
    static const ShaAlgorithm DEFAULT_ALGORITHM;

    // token validity period
    inline void setPeriod(const PeriodType &)
    { this->_period = 0U; }

    const TokenString generateToken(Error *error = nullptr) const override;

public:
    friend struct TokenData;
    friend class TokenStore;

    HOTPToken(const Label &label,
              const Icon &icon,
              const SecretType &secret,
              const DigitType &digits,
              const PeriodType &period,
              const CounterType &counter,
              const ShaAlgorithm &algorithm)
        : HOTPToken()
    {
        _label = label;
        _icon = icon;
        _secret = secret;
        this->setDigitLength(digits);
        this->setPeriod(period);
        this->setCounter(counter);
        this->setAlgorithm(algorithm);
    }
};

#endif // HOTPTOKEN_HPP