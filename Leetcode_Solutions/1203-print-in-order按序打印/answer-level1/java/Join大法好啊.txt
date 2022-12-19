思路就是thread2等thread1, thread3等thread2.

```
class Foo {

    public Foo() {
        
    }

    Thread t1, t2;

    public void first(Runnable printFirst) throws InterruptedException {
        
        t1 = Thread.currentThread();
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while(t1 == null);
        t1.join();
        t2 = Thread.currentThread();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
    }

    public void third(Runnable printThird) throws InterruptedException {
        while(t2 == null);
        t2.join();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```
