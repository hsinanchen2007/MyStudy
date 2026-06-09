
firstCondition 和 firstFinished 看似重复，其实不然：
firstFinished用来标记前一个线程是否执行完成，如果还没执行完成，则执行firstCondition的等待动作（second函数不能无条件等待，如果在first函数已经完成的情况下等待，那firstCondition将没法被唤醒）

```cs
class Foo {

    Lock lock = new ReentrantLock();
    Condition firstCondition = lock.newCondition();
    Condition secondCondition = lock.newCondition();
    private boolean firstFinished = false;
    private boolean secondFinished = false;

    public Foo() {

    }

    public void first(Runnable printFirst) throws InterruptedException {
        lock.lock();
        try {
            // printFirst.run() outputs "first". Do not change or remove this line.
            printFirst.run();
            firstFinished = true;
            firstCondition.signal();
        }finally{
            lock.unlock();
        }


    }

    public void second(Runnable printSecond) throws InterruptedException {
        lock.lock();
        try {
            while (!firstFinished){
                firstCondition.await();
            }
            // printSecond.run() outputs "second". Do not change or remove this line.
            printSecond.run();
            secondFinished = true;
            secondCondition.signal();
        }finally{
            lock.unlock();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        lock.lock();
        try{
            while (!secondFinished){
                secondCondition.await();
            }
            // printThird.run() outputs "third". Do not change or remove this line.
            printThird.run();
        }finally{
            lock.unlock();
        }
    }
}
```
