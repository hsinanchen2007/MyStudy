### 解题思路
通过volatile的可见性，将其作为标志位。
通过自旋等待执行下一步。就是有点耗资源。
### 代码

```java
class Foo {
    private volatile boolean firstFinished = false;
    private volatile boolean secondFinished = false;
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        firstFinished = true;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        while(!firstFinished);
        printSecond.run();
        secondFinished = true;
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
        while(!secondFinished);
        printThird.run();
    }
}
```