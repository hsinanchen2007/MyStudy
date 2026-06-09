### 解题思路
此处撰写解题思路

### 代码

```java
class Foo {
    private Object lock = new Object();
    private volatile int count = 0;
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        synchronized(lock){
            while(count!=0){
                 lock.wait();   
            }
            count=1;
            printFirst.run();
            lock.notifyAll();
        }
        // printFirst.run() outputs "first". Do not change or remove this line.
        
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized(lock){
            while(count!=1){
                  lock.wait();  
            }
            count=2;
            printSecond.run();
            lock.notifyAll();
        }
        // printSecond.run() outputs "second". Do not change or remove this line.
        
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized(lock){
            while(count!=2){
                lock.wait();
            }
            printThird.run();
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        
    }
}
```