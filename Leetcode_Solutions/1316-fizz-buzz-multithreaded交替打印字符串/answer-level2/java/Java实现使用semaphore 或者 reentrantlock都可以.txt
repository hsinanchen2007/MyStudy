慢慢总结出一些套路：
1.凡是可以用semaphore解决的问题，大多都可以使用管程（也就是lock）来解决，但使用lock需要增加一个变量来标记起始条件
2.凡是可以使用多个condition可以解决的问题，都可以使用一个condition和一个volatile变量来解决

下面分别给出使用semaphore和lock的实现，lock的方案使用了多个condition，这其实也是可以使用一个condition外加一个volatile变量来实现的

class PrintFizzBuzz {
    private int n;

    public PrintFizzBuzz(int n) {
        this.n = n;
    }

    private Semaphore fSema = new Semaphore(0);
    private Semaphore bSema = new Semaphore(0);
    private Semaphore fbSema = new Semaphore(0);
    private Semaphore nSema = new Semaphore(1);

    private ReentrantLock lock = new ReentrantLock();
    private Condition fCond = lock.newCondition();
    private Condition bCond = lock.newCondition();
    private Condition fbCond = lock.newCondition();
    private Condition nCond = lock.newCondition();
    private volatile Boolean state = false;

    /**
     * use semaphore
     * @param printFizz
     * @throws InterruptedException
     */
    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for (int i = 3; i <= n; i = i + 3) {
            if (i % 5 != 0) {
                fSema.acquire();
                printFizz.run();
                nSema.release();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for (int i = 5; i <= n; i = i + 5) {
            if (i % 3 != 0) {
                bSema.acquire();
                printBuzz.run();
                nSema.release();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for (int i = 15; i <= n; i = i + 15) {
            fbSema.acquire();
            printFizzBuzz.run();
            nSema.release();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            nSema.acquire();
            if (i % 3 == 0 && i % 5 == 0) {
                fbSema.release();
            }else if (i % 3 == 0) {
                fSema.release();
            }else if (i % 5 == 0) {
                bSema.release();
            }else {
                printNumber.accept(i);
                nSema.release();
            }
        }
    }


    /**
     * use lock
     * @param printFizz
     * @throws InterruptedException
     */
    // printFizz.run() outputs "fizz".
    public void fizz1(Runnable printFizz) throws InterruptedException {
        for (int i = 3; i <= n; i = i + 3) {
            lock.lock();
            try {
                if (i % 5 != 0) {
                    while (!state) {
                        fCond.await();
                    }
                    printFizz.run();
                    state = false;
                    nCond.signal();
                }
            }finally {
                lock.unlock();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz1(Runnable printBuzz) throws InterruptedException {
        for (int i = 5; i <= n; i = i + 5) {
            lock.lock();
            try {
                if (i % 3 != 0) {
                    while (!state) {
                        bCond.await();
                    }
                    printBuzz.run();
                    state = false;
                    nCond.signal();
                }
            }finally {
                lock.unlock();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz1(Runnable printFizzBuzz) throws InterruptedException {
        for (int i = 15; i <= n; i = i + 15) {
            lock.lock();
            try {
                while (!state) {
                    fbCond.await();
                }
                printFizzBuzz.run();
                state = false;
                nCond.signal();
            }finally {
                lock.unlock();
            }

        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number1(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            lock.lock();
            try {
                while (state) {
                    nCond.await();
                }
                if (i % 3 == 0 && i % 5 == 0) {
                    fbCond.signal();
                    state = true;
                }else if (i % 3 == 0) {
                    fCond.signal();
                    state = true;
                }else if (i % 5 == 0) {
                    bCond.signal();
                    state = true;
                }else {
                    printNumber.accept(i);
                    nCond.signal();
                }
            }finally {
                lock.unlock();
            }
        }
    }

    public static void main(String[] args) {
        PrintFizzBuzz pfb = new PrintFizzBuzz(15);
        Thread t1 = new Thread(() -> {
            try {
                pfb.fizz1(() -> System.out.print("fizz"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread t2 = new Thread(() -> {
            try {
                pfb.buzz1(() -> System.out.print("buzz"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread t3 = new Thread(() -> {
            try {
                pfb.fizzbuzz1(() -> System.out.print("fizzbuzz"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread t4 = new Thread(() -> {
            try {
                pfb.number1(value -> System.out.print(value));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        t1.start();
        t2.start();
        t3.start();
        t4.start();

    }
}