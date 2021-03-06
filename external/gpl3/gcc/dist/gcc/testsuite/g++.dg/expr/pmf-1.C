// C++ PR/2521
// Copyright (C) 2002 Free Software Foundation
// Contributed by Gabriel Dos Reis <gdr@integrable-solutions.net>

// { dg-do compile }

struct A 
{
  void f();
  void foo(void (A::*)(int));       // { dg-message "candidate" "" }
  template<typename T>
    void g(T);
  void h()
  {
    void (A::*p)() = &A::f;
    void (A::*q)() = &(A::f);       // { dg-error "parenthesized" "" }
    foo(&g<int>);                   // { dg-error "no matching" "" }
  }
};
