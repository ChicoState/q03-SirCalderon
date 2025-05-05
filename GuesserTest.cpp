/**
 * Unit Tests for the class
 **/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
	Guesser object("Secret");
	ASSERT_EQ( 1 + 1, 2 );
}

TEST(GuesserTest, firstTest)
{
	//Guesser object("test");
	Guesser marco("test");
	//EXPECT_TRUE(marco.match("test"));
	ASSERT_TRUE(marco.match("test"));
	ASSERT_EQ(marco.remaining(), 3);
}


TEST(GuesserTest, secondTest)
{
	Guesser marco("light");
	marco.match("lighs");
	ASSERT_EQ(marco.remaining(), 2);
}

TEST(GuesserTest, thirdTest)
{
	Guesser marco("orbit");
	marco.match("orbis");
	marco.match("arbit");
	marco.match("obrit");
	ASSERT_FALSE(marco.match("orbit"));
	ASSERT_EQ(marco.remaining(), 0);
}

TEST(GuesserTest, fourthTest)
{
	Guesser marco("planet");
	ASSERT_FALSE(marco.match("xxxxxx"));
	ASSERT_FALSE(marco.match("planet"));
	ASSERT_EQ(marco.remaining(), 3);
}

/*TEST(GuesserTest, VIRGINIAISTHEBESTSTATEEVER)
  {
  Guesser marco("galaxy");
  marco.match("galaxx");
  ASSERT_EQ(marco.remaining(), 2);
  ASSERT_TRUE(marco.match("galaxy"));
  ASSERT_EQ(marco.remaining(), 3);
  }*/

TEST(GuesserTest, fifthTest)
{
	Guesser marco("abcdefghijklmnopqrstuvwxyz1234567890");
	EXPECT_FALSE(marco.match("abcdefghijklmnopqrstuvwxyz1234567890"));
	EXPECT_FALSE(marco.match("abcdefghijklmnopqrstuvwxyz123456"));
}
