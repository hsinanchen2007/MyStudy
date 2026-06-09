思路就是用一个变量来控制打印，如果这个变量的值不等于该方法要打印的值，就等待。
class Foo {
    
   Object lock= new Object();//锁
    int curr=1;//控制打印顺序

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        synchronized(lock){
        while(curr!=1){
            lock.wait();
        }
            printFirst.run();
             curr++;
            lock.notifyAll();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
       synchronized(lock){
        while(curr!=2){
            lock.wait();
        }
            printSecond.run();
            curr++;
            lock.notifyAll();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
       synchronized(lock){
        while(curr!=3){
            lock.wait();
        }
            printThird.run();
            curr++;
            lock.notifyAll();
        }
    }
}