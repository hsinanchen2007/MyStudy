```
class Foo {
public:
    int AF = 0;
    int BF = 0;
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        printFirst();
        AF = 1;
    }

    void second(function<void()> printSecond) {
        while(!AF);
        printSecond();
        BF = 1;
    }

    void third(function<void()> printThird) {
        while(!BF);
        printThird();
    }
};
```
