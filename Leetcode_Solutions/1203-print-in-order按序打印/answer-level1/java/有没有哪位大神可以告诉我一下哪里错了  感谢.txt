class Foo {
    private static final CountDownLatch countDownLatch = new CountDownLatch(1);

    private static final CountDownLatch countDownLatch2 = new CountDownLatch(1);
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
       
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        countDownLatch.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        countDownLatch.await();
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        countDownLatch2.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
         countDownLatch2.await();
        
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        
    }
}