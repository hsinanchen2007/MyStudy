```
class Foo {
    public Foo() {

    }
    private volatile int a = 2;

    public void first(Runnable printFirst) throws InterruptedException {

        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        a--;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while(true){
            if(a ==1){
                printSecond.run();
                a--;
                break;
            }
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        while(true){
            if(a ==0){
                 // printThird.run() outputs "third". Do not change or remove this line.
                printThird.run();
                break;
            }
        }
    }
}
```
