```
class Foo {

    private Object obj1 = new Object();

    private Object obj2 = new Object();

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        synchronized(obj1){
            printFirst.run();
            obj1.notify();
        }
        
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized(obj1){
        obj1.wait();
        // printSecond.run() outputs "second". Do not change or remove this line.
            printSecond.run();
            synchronized(obj2){
                obj2.notify();
            }
            
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized(obj2){
            obj2.wait();
            // printThird.run() outputs "third". Do not change or remove this line.
            printThird.run();
        }
    }
}
```
