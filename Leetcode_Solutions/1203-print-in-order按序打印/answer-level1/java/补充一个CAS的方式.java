使用CAS实现。
```java
class Foo {
    
    volatile boolean mWaitFirst = true;
    volatile boolean mWaitSecond = true;

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        mWaitFirst = false;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while (mWaitFirst) ;
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        mWaitSecond = false;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while (mWaitSecond) ;
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```

