利用volatile关键字的特性，简单暴力解决问题
class Foo {

    private volatile int nums = 0;

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        while(nums!=0){
            continue;
        }
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        nums = nums+1;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while(nums!=1){
            continue;
        }
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        nums = nums+1;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while(nums!=2){
            continue;
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        nums = nums+1;
    }
}