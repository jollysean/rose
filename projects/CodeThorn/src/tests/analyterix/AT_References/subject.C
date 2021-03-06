struct A18;

struct A18 {
  int val;
  A18& next;
  A18() : next(*this) { }
  A18(A18& _next) : next(_next) { }
};

struct E {
  E() : next2(*this) { }
  E(E _next2, int i) : next2(_next2) {
    // next2 is usable in ctor only
  }
private:
  E& next2;
};

struct A {

};

struct B : A {
  int m;
  B() : B(1) {

  }
  B(int i) {

  }

  B(int a, int b);
};

B::B(int a, int b) : A(), m(1) {

}

class A27
{
public:
    int i;
    static float& f;
};

float f1 = 1.0;

float& A27::f = f1;

void foo18() {
  A18 last;
  A18 list(last);
  list.next.val = list.val;
  
  float* f_ptr = &A27::f;
}

int global = 1;

int& getRef() {
  return global;
}

template<typename A>
class C {
public:
  A& templRef;
  C(A& templParam) : templRef(templParam) {}
};

class D {
  int& unused; // should not be in the address taken set!
};

int main() {
  int i = 0;
  C<int> c(i);
}
