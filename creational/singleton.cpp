#include <iostream>

class Singleton {
private:
  static bool flag;
  static Singleton *single;
  Singleton() {}
public:
  static Singleton *getInstance();
  void Run();
  ~Singleton() { flag = false; }
};

bool Singleton::flag = false;
Singleton *Singleton::single = nullptr;
Singleton *Singleton::getInstance() {
  if(!flag) {
    single = new Singleton();
    flag = true;
  }
  return single;
}

void Singleton::Run() {
  std::cout<<"Running singleton"<<std::endl;
}

int main() {
  Singleton *s1, *s2;
  s1 = Singleton::getInstance();
  s1->Run();
  s2 = Singleton::getInstance();
  s2->Run();
}
