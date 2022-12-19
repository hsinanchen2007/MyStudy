public class ZeroEvenOdd {

    private int n;

    private boolean flag = false; //是否零阻塞

    private int count = 0;


    Lock lock = new ReentrantLock();
    private Condition zero = lock.newCondition();
    private Condition even = lock.newCondition();
    private Condition odd = lock.newCondition();


    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        lock.lock();
        try {
            for (int i = 1; i <= n; i++) {
                while (flag) {
                    zero.await();
                }
                printNumber.accept(0);
                count++;
                flag = !flag;
                if (i % 2 == 0) {
                    even.signalAll();//偶数
                } else {
                    odd.signalAll();//奇数
                }

            }
            System.out.println("0解锁");


        } finally {

            lock.unlock();

        }

    }

    /**
     * 偶数
     *
     * @param printNumber
     * @throws InterruptedException
     */
    public void even(IntConsumer printNumber) throws InterruptedException {
        lock.lock();
        try {
            for (; count < n; ) {
                if(n==1){
                    break;
                }
                if (n > 1) {
                    if (n % 2 != 0 && count == n - 1) {
                        break;
                    }
                }
                while (!flag||count%2!=0) {
                    even.await();
                }

                printNumber.accept(count);
                flag = !flag;
                zero.signalAll();

            }
        } finally {

            lock.unlock();
            System.out.println("解锁偶数");

        }

    }

    /**
     * 奇数
     *
     * @param printNumber
     * @throws InterruptedException
     */
    public void odd(IntConsumer printNumber) throws InterruptedException {
        lock.lock();
        try {

            if(count==1&&n==1){
                printNumber.accept(count);

            }
            for (; count <n; ) {
                if (n > 2) {
                    if (n % 2 == 0 && count == n - 1) {
                        break;
                    }
                }
                while (!flag||count%2==0) {
                    odd.await();
                }
                printNumber.accept(count);
                flag = !flag;
                zero.signalAll();
                if (n == 2) {
                    break;
                }
            }

        } finally {
            lock.unlock();
            System.out.println("解锁奇数");
        }
    }

    public static void main(String[] args) {

        ZeroEvenOdd zeroEvenOdd = new ZeroEvenOdd(2);
        new Thread(() -> {
            try {
                zeroEvenOdd.zero((x) -> {
                    System.out.println(x + " " + Thread.currentThread().getName());
                });
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }, "1").start();
        new Thread(() -> {
            try {
                zeroEvenOdd.even((x) -> {
                    System.out.println(x + " " + Thread.currentThread().getName());
                });
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }, "2").start();
        new Thread(() -> {
            try {
                zeroEvenOdd.odd((x) -> {
                    System.out.println(x + " " + Thread.currentThread().getName());
                });
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }, "3").start();


    }


}
最主要的思路还是,互相唤醒时,比如偶数队列那么,最后一个奇数进入条件队列后,无法再被其他的线程唤醒,因为zero线程,和偶数线程都已经死亡,而这时作为判断依据的count任然是偶数,剩下考虑的情况就是1和2的特殊情况