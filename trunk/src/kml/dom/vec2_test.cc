// Copyright 2008, Google Inc. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice, 
//     this list of conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//  3. Neither the name of Google Inc. nor the names of its contributors may be
//     used to endorse or promote products derived from this software without
//     specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
// EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "kml/dom/vec2.h"
#include "kml/util/unit_test.h"

namespace kmldom {

class Vec2Test : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(Vec2Test);
  CPPUNIT_TEST(TestType);
  CPPUNIT_TEST(TestDefaults);
  CPPUNIT_TEST(TestSetToDefaultValues);
  CPPUNIT_TEST(TestSetGetHasClear);
  CPPUNIT_TEST_SUITE_END();

 public:
  // Called before all tests.
  void setUp() {
    vec2_ = new TestVec2();
  }

  // Called after all tests.
  void tearDown() {
    delete vec2_;
  }


 protected:
  void TestType();
  void TestDefaults();
  void TestSetToDefaultValues();
  void TestSetGetHasClear();

 private:
  // Vec2 is abstract, hence its constructor is protected.
  class TestVec2 : public Vec2 {};
  TestVec2* vec2_;
};

CPPUNIT_TEST_SUITE_REGISTRATION(Vec2Test);

void Vec2Test::TestType() {
  CPPUNIT_ASSERT(true == vec2_->IsA(Type_Vec2));
}

// Verify proper defaults:
void Vec2Test::TestDefaults() {
  CPPUNIT_ASSERT(1.0 == vec2_->x());
  CPPUNIT_ASSERT(1.0 == vec2_->y());
  CPPUNIT_ASSERT(UNITS_FRACTION == vec2_->xunits());
  CPPUNIT_ASSERT(UNITS_FRACTION == vec2_->yunits());
}

// Verify setting default makes has_xxx() true:
void Vec2Test::TestSetToDefaultValues() {
  TestDefaults();
  vec2_->set_x(vec2_->x());
  CPPUNIT_ASSERT(true == vec2_->has_x());
  vec2_->set_y(vec2_->y());
  CPPUNIT_ASSERT(true == vec2_->has_y());
  vec2_->set_xunits(vec2_->xunits());
  CPPUNIT_ASSERT(true == vec2_->has_xunits());
  vec2_->set_yunits(vec2_->yunits());
  CPPUNIT_ASSERT(true == vec2_->has_yunits());
}

// Verify set, get, has, clear:
void Vec2Test::TestSetGetHasClear() {
  // Non-default values:
  double x = 0.1;
  double y = 0.2;
  UnitsEnum xunits = UNITS_PIXELS;
  UnitsEnum yunits = UNITS_PIXELS;

  // Set all fields:
  vec2_->set_x(x);
  vec2_->set_y(y);
  vec2_->set_xunits(xunits);
  vec2_->set_yunits(yunits);

  // Verify getter and has_xxx():
  CPPUNIT_ASSERT(true == vec2_->has_x());
  CPPUNIT_ASSERT(x = vec2_->x());
  CPPUNIT_ASSERT(true == vec2_->has_y());
  CPPUNIT_ASSERT(y = vec2_->y());
  CPPUNIT_ASSERT(true == vec2_->has_xunits());
  CPPUNIT_ASSERT(xunits == vec2_->xunits());
  CPPUNIT_ASSERT(true == vec2_->has_yunits());
  CPPUNIT_ASSERT(yunits == vec2_->yunits());

  // Clear all fields:
  vec2_->clear_x();
  vec2_->clear_y();
  vec2_->clear_xunits();
  vec2_->clear_yunits();

  // Verify now in default state:
  TestDefaults();
}

}  // end namespace kmldom

TEST_MAIN

