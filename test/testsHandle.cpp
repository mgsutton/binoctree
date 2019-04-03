#include "catch.hpp"
#include "padt/octree/octree.h"


TEST_CASE("Octree empty creation", "[octree]") { padt::Octree<int> otree1; }