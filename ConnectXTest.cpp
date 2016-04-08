/**
 * Unit Tests for ConnectX class
 **/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"

class ConnectXTest : public ::testing::Test
{
    protected:
        ConnectXTest(){}
        virtual ~ConnectXTest(){}
        virtual void SetUp(){}
        virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
    ASSERT_TRUE(true);
}

TEST(ConnectXTest, isValidValues)
{
    ConnectX ctests;
    ASSERT_EQ(2,ctests.whoseTurn());
    ctests.placePiece(2);
    ASSERT_EQ(1,ctests.whoseTurn());
    ctests.placePiece(2);
    ASSERT_EQ(2,ctests.whoseTurn());
    ctests.placePiece(2);
    ASSERT_EQ(1,ctests.whoseTurn());
    ctests.placePiece(2);
    ASSERT_EQ(2,ctests.whoseTurn());

}
TEST(ConnectXTest, isInvalidwideheight)
{
    ConnectX ConnectLine(6,5,6);
    ASSERT_EQ(-1, ConnectLine.at(-4,-4));
}


TEST(ConnectXTest, isInvalidHeight)
{
    ConnectX ConnectLine(6,5,6);
    ASSERT_EQ(-1, ConnectLine.at(4,-4));
}

// Here is the Bug!
TEST(ConnectXTest, isInvalidwidth)
{
    ConnectX ConnectLine(6,5,6);
    ASSERT_EQ(-1, ConnectLine.at(-4,4));
}


TEST(ConnectXTest, isInvalidHeight1)
{
    ConnectX ConnectLine(6,4,6);
    ASSERT_EQ(-1, ConnectLine.at(1,7));
}

TEST(ConnectXTest, isInvalidValueWidth)
{
    ConnectX ConnectLine(-8,4,6);
    ASSERT_EQ(2, ConnectLine.whoseTurn());
}

TEST(ConnectXTest, InvalidValueWidth)
{
    ConnectX ConnectLine(-6,4,6);
    ASSERT_EQ(2, ConnectLine.whoseTurn());
}

TEST(ConnectXTest, InvalidValueHeight)
{
    ConnectX ConnectLine(-6,-4,-6);
    ASSERT_EQ(2, ConnectLine.whoseTurn());
}

TEST(ConnectXTest, isInvalidValue_X)
{
    ConnectX ConnectLine(1,0,0);
    ASSERT_EQ(2, ConnectLine.whoseTurn());
}

TEST(ConnectXTest, isInvalidValue_X1)
{
    ConnectX ConnectLine(1,0,-7);
    ASSERT_EQ(2, ConnectLine.whoseTurn());
}
TEST(ConnectXTest, InvalidValueX)
{
    ConnectX ConnectLine(4,3,-4);
    ASSERT_EQ(2, ConnectLine.whoseTurn());
}
// Here is the Bug!
TEST(ConnectXTest, isInvalidWidth1)
{
    ConnectX ConnectLine(4,3,4);
    ASSERT_EQ(-1, ConnectLine.at(5,1));
}

TEST(ConnectXTest, isInvalidValueW0)
{
    ConnectX ConnectLine(0,3,4);
    ASSERT_EQ(2, ConnectLine.whoseTurn());
}

TEST(ConnectXTest, isInvalidValueW01)
{
    ConnectX ConnectLine(-11,5,7);
    ASSERT_EQ(2, ConnectLine.whoseTurn());
}

TEST(ConnectXTest, isValidToggleValue)
{
    ConnectX ConnectLine(4,3,4);
    ConnectLine.placePiece(5);
    ASSERT_EQ(1, ConnectLine.whoseTurn()); 
    ConnectLine.placePiece(1);
    ASSERT_EQ(2, ConnectLine.whoseTurn());
}


TEST(ConnectXTest, ShowBoardChecking)
{
    ConnectX ConnectLine(4,3,4);
    ConnectLine.placePiece(2);
    ConnectLine.placePiece(1);
    ConnectLine.showBoard();
    ASSERT_EQ(2, ConnectLine.whoseTurn());
}

