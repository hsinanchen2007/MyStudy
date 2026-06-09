
执行用时 :19 ms, 在所有 Java 提交中击败了67.57%的用户内存消耗 :36.3 MB, 在所有 Java 提交中击败了100.00%的用户


运用JAVA ReentrantLock 锁 以及Condition状态，并通过state变量避免死锁以及保证执行的顺序。
```
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

class Foo {
    ReentrantLock lock = new ReentrantLock();
    Condition firstCondition = lock.newCondition();
    Condition secondCondition = lock.newCondition();
    Condition thirdCondition = lock.newCondition();
    int state = 1;
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        lock.lock();
        try{
            // printFirst.run() outputs "first". Do not change or remove this line.
            if(state!=1){
                firstCondition.await();
            }
            state = 2;
            printFirst.run();
            secondCondition.signal();
        }finally {
            lock.unlock();
        }
        
    }

    public void second(Runnable printSecond) throws InterruptedException {
        lock.lock();
        try{
            if(state!=2){
                secondCondition.await();
            }
            state = 3;
            printSecond.run();

            thirdCondition.signal();
             // printSecond.run() outputs "second". Do not change or remove this line. 
        }finally{
            lock.unlock();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        lock.lock();
        try{
            if(state!=3){
                thirdCondition.await();
            }
         // printThird.run() outputs "third". Do not change or remove this line.
             printThird.run();
        }finally{
            lock.unlock();
        }
    }
}
```
