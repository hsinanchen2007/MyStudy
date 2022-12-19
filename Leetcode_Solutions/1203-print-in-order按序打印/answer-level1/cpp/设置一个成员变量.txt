### 解题思路
此处撰写解题思路

### 代码

```cpp
class Foo {
public:
    volatile int flag;
    Foo() {
     flag = 1;
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag = 2;
    }

    void second(function<void()> printSecond) {
        while (flag < 2);{} //flag<2时等待，这里是少了个括号，之前看别的题解一直被搞糊涂了
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        flag = 3;
    }

    void third(function<void()> printThird) {
        while(flag < 3);{}
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

```