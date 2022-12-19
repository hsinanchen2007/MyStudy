这道题直接使用自旋的方式，利用判断信号量就能解决
```
class Foo {
    private volatile int signal = 0;
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        while(signal!=0){
        }
        printFirst.run();
        ++signal;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        while(signal!=1){
        }
        printSecond.run();
        ++signal;
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
        while(signal!=2){
        }
        printThird.run();
        ++signal;
    }
}
```
