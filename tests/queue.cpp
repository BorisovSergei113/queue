#include <catch.hpp>
#include <sstream>
#include "queue.hpp"

TEST_CASE("testing pop,push,throw")
{
    queue_t<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    std::ostringstream output;
    s.pop();
    s.show_queue(output);
    REQUIRE ("12" == output.str());
    s.pop();
    s.pop();
    REQUIRE_THROWS (s.pop());
}

TEST_CASE("copy consruct")
{ queue_t<int> s1;
    s1.push(0);
    s1.push(1);
    s1.push(2);
    queue_t<int> s2 (s1);
    std::ostringstream output;
    s2.show_queue(output);
    string srav {"012"};
    REQUIRE(srav == output.str() );
}
