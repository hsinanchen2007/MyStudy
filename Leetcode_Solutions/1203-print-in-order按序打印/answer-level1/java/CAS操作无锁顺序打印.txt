定义一个Atomic类型共享变量作为状态,假定初始状态值为1
```
private AtomicInteger status = new AtomicInteger(1);
```

各个线程打印前通过一个cas操作更新状态，自选的方式获取锁后执行打印，打印完再更新锁的状态

```
    while(true) {
        if(lock.compareAndSet(1,-1)) {
            // printFirst.run() outputs "first". Do not change or remove this line.
            printFirst.run();
            lock.compareAndSet(-1,2);
            break;
        }
    }
```

**完整示例**

```
class Foo {

    private AtomicInteger lock = new AtomicInteger(1);

    public Foo() {
        
    }
    

    public void first(Runnable printFirst) throws InterruptedException {
        
        while(true) {
            if(lock.compareAndSet(1,-1)) {
                // printFirst.run() outputs "first". Do not change or remove this line.
                printFirst.run();
                lock.compareAndSet(-1,2);
                break;
            }
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        while(true) {
            if(lock.compareAndSet(2,-1)) {
                // printSecond.run() outputs "second". Do not change or remove this line.
                printSecond.run();
                lock.compareAndSet(-1,3);
                break;
            }
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        while(true) {
            if(lock.compareAndSet(3,-1)) {
                // printThird.run() outputs "third". Do not change or remove this line.
                printThird.run();
                lock.compareAndSet(-1,1);
                break;
            }
        }
    }
}
```
