### 解题思路
蛮办法，定义同步变量

### 代码

```java
class Foo {
    private volatile int flag = 1;
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        flag = 2;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while(flag != 2);//flag为2时才往下执行
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        flag = 3;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while(flag != 3);//flag为3时才往下执行
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```