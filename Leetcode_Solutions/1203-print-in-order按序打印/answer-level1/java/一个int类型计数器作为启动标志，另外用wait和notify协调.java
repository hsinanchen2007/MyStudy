### 解题思路
此处撰写解题思路

### 代码

```java
class Foo {
    private volatile int counter = 0;
    public Foo() {
        
    }

    public synchronized void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        counter++;
        notifyAll();
    }

    public synchronized void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        while(!Thread.interrupted()){
            if(counter != 1){
                wait();
            }else{
                break;
            }
        }
        printSecond.run();
        counter++;
        notifyAll();
    }

    public synchronized void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
        while(!Thread.interrupted()){
            if(counter != 2){
                wait();
            }else{
                break;
            }
        }
        printThird.run();
    }
}
```