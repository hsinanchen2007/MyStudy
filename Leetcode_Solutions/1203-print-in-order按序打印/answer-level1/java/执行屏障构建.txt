多线程中执行设置执行屏障的问题.说白了,就是保证线程内部的可见性.在java中,解决这一题有如下几种方式
1. 两个`volatile`变量
```
    class Foo {
        volatile boolean firstFinished = false;
        volatile boolean secondFinished = false;

        public Foo() {

        }

        public void first(Runnable printFirst) throws InterruptedException {

            // printFirst.run() outputs "first". Do not change or remove this line.
            printFirst.run();
            firstFinished = true;
        }

        public void second(Runnable printSecond) throws InterruptedException {

            // printSecond.run() outputs "second". Do not change or remove this line.

            if (!firstFinished) {
                while (!firstFinished) {
                }
            }
            printSecond.run();
            secondFinished = true;
        }

        public void third(Runnable printThird) throws InterruptedException {

            // printThird.run() outputs "third". Do not change or remove this line.
            if (!secondFinished) {
                while (!secondFinished) {
                }
            }
            printThird.run();
        }
```
2. 在程序运行期间,由于有两个线程在死循环,这一点对CPU不是特别友好,使用两个`CountDownLatch`也能搞定
```
    class Foo {

        private CountDownLatch count1=new CountDownLatch(1);
        private CountDownLatch count2=new CountDownLatch(1);

        public Foo() {

        }

        public void first(Runnable printFirst) throws InterruptedException {

            printFirst.run();
            count1.countDown();
        }

        public void second(Runnable printSecond) throws InterruptedException {

            count1.await();
            printSecond.run();
            count2.countDown();

        }

        public void third(Runnable printThird) throws InterruptedException {
            count2.await();
            printThird.run();
        }
    }
```
3. 如果使用最原始的`wait`和`notify`呢?
```
    class Foo {

        final private Object lock1 = new Object();
        final private Object lock2 = new Object();

        public Foo() {

        }

        public void first(Runnable printFirst) throws InterruptedException {

            synchronized (lock1) {
                printFirst.run();
                lock1.notify();
            }
        }

        public void second(Runnable printSecond) throws InterruptedException {
            synchronized (lock1) {
                lock1.wait();
                printSecond.run();
                synchronized (lock2){
                    lock2.notify();
                }
            }
        }

        public void third(Runnable printThird) throws InterruptedException {
            synchronized (lock2) {
                lock2.wait();
                printThird.run();
            }

        }
    }
```
其实吧,运行过才知道,`wait`会自动释放锁,但是`notify`却是不会释放锁.虽然自己写的测试工具能通过,但是在这里却超出时间限制了.水平有点菜,不可取.

