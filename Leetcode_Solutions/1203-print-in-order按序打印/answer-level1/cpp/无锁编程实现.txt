### 解题思路
使用atomic<int>,循环检测是否满足条件。

### 代码

```cpp
class Foo {
public:
    Foo() {
        counter = 0;
    }

    void first(function<void()> printFirst) {
        while(counter != 0) {}
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        counter++;
    }

    void second(function<void()> printSecond) {
        while(counter != 1) {}
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        counter++;
    }

    void third(function<void()> printThird) {
        while(counter != 2) {}
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        counter++;
    }
private:
    std::atomic<int> counter;
};
```