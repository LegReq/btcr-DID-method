#include <gtest/gtest.h>

#include "satoshis.h"


TEST(SatoshisTest, test_b2s) {
    double b = 1;
    EXPECT_EQ(btc2satoshi(b), SATOSHIS_PER_BTC);

    b = 10;
    EXPECT_EQ(btc2satoshi(b), SATOSHIS_PER_BTC * 10);

    b = 0.1;
    EXPECT_EQ(btc2satoshi(b), SATOSHIS_PER_BTC / 10);

    b = 12.34567;
    EXPECT_EQ(btc2satoshi(b), 1234567000);

    b = 0.00000001;
    EXPECT_EQ(btc2satoshi(b), 1);
}


TEST(SatoshisTest, test_s2b) {
    int64_t s = 1;
    EXPECT_DOUBLE_EQ(satoshi2btc(s), 0.00000001);

    s = 1234567000;
    EXPECT_DOUBLE_EQ(satoshi2btc(s), 12.34567);

    s = 1154000;
    EXPECT_DOUBLE_EQ(satoshi2btc(s), 0.01154);

    s = 1164026;
    EXPECT_DOUBLE_EQ(satoshi2btc(s), 0.01164026);

    s = SATOSHIS_PER_BTC / 10;
    EXPECT_DOUBLE_EQ(satoshi2btc(s), 0.1);

    s = SATOSHIS_PER_BTC * 10;
    EXPECT_DOUBLE_EQ(satoshi2btc(s), 10);

    s = SATOSHIS_PER_BTC;
    EXPECT_DOUBLE_EQ(satoshi2btc(s), 1);
}

TEST(SatoshisTest, test_s2b_stringconversions) {
    int64_t s = 1;
    EXPECT_EQ(btc_to_string(satoshi2btc(s)), "0.00000001");

    s = 1154000;
    EXPECT_EQ(btc_to_string(satoshi2btc(s)), "0.01154000");

    s = 1164026;
    EXPECT_EQ(btc_to_string(satoshi2btc(s)), "0.01164026");

    s = SATOSHIS_PER_BTC / 10;
    EXPECT_EQ(btc_to_string(satoshi2btc(s)), "0.10000000");

    s = SATOSHIS_PER_BTC * 10;
    EXPECT_EQ(btc_to_string(satoshi2btc(s)), "10.00000000");

    s = SATOSHIS_PER_BTC;
    EXPECT_EQ(btc_to_string(satoshi2btc(s)), "1.00000000");
}


