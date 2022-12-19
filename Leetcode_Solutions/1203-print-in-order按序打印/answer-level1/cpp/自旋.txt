### 解题思路
呵，自旋;

### 代码

```cpp
class Foo {
public:
    bool lock2=true,lock3=true;
    Foo() {
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        lock2 = false;
    }

    void second(function<void()> printSecond) {
        // printSecond() outputs "second". Do not change or remove this line.
        while(lock2) continue;
        printSecond();lock3 = false;
    }

    void third(function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        while(lock3) continue;
        printThird();
    }
};
```