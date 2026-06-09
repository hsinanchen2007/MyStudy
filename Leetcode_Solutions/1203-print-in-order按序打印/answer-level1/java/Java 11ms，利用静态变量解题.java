```
class Foo {
    private static int i = 0;
    
    public Foo() {
    }

    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        i = 1;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while(i != 1){
            Thread.sleep(0);
        }
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        i = 2;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while(i != 2){
            Thread.sleep(0);
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        i = 3;
    }
}
```
