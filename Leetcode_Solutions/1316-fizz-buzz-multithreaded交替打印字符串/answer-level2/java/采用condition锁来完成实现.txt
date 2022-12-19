@Data
public class FizzBuzz {

    private int n;

    private int index;

    /**
     * 定义全局锁
     */
    Lock lock = new ReentrantLock();

    /**
     * 用于唤醒线程A
     */
    Condition conditionA;
    Condition conditionB;
    Condition conditionC;
    Condition conditionD;



    public FizzBuzz(int n) {
        this.n = n;
        this.index = 1;
        conditionA = lock.newCondition();
        conditionB = lock.newCondition();
        conditionC = lock.newCondition();
        conditionD = lock.newCondition();

    }

    // 主线程执行
    public static void main(String[] args) {
        final FizzBuzz fizzBuzz = new FizzBuzz(15);
        // 线程D首先获取锁
        ThreadFactory threadFactory = new ThreadFactory();

        Thread threadD = threadFactory.creatThread(() -> fizzBuzz.number(), "线程D");
        threadD.start();
        // 启动线程A
        Thread threadA = threadFactory.creatThread(() -> fizzBuzz.fizz(), "线程A");
        threadA.start();
        // 启动线程B
        Thread threadB = threadFactory.creatThread(() -> fizzBuzz.buzz(), "线程B");
        threadB.start();
        // 启动线程C
        Thread threadC = threadFactory.creatThread(() -> fizzBuzz.fizzBuzz(), "线程C");
        threadC.start();

    }

    // 线程D执行方法
    public void number() {
        while (index <= n) {
            lock.lock();
            try {
                if (index % 3 != 0 && index % 5 != 0) {
                    System.out.print(index + " ");
                    index++;
                } else {
                    conditionA.signal();
                    conditionD.await();
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                lock.unlock();
            }
        }
    }


    // 线程A执行方法
    public void fizz() {
        while (index <= n) {
            lock.lock();
            try {
                // 线程A获取锁，没获取到则阻塞，底层是会被加入到一个阻塞队列中排队
                if (index % 3 == 0 && index % 5 != 0) {
                    System.out.print("fizz ");
                    index++;
                } else {
                    conditionB.signal();
                    conditionA.await();
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                lock.unlock();
            }
        }
   }


    // 线程2执行方法
    public void buzz() {
       while (index <= n) {
           lock.lock();
            try {
                if (index % 5 == 0 && index % 3 != 0) {
                    System.out.print("buzz ");
                    index++;
                } else {
                    conditionC.signal();
                    conditionB.await();
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
   }

    // 线程3执行方法
    public void fizzBuzz() {
        while (index <= n) {
            lock.lock();
            try {
                if (index % 5 == 0 && index % 3 == 0) {
                    System.out.print("fizzBuzz ");
                    index++;
                } else {
                    conditionD.signal();
                    conditionC.await();
                }


            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                lock.unlock();
            }
        }
    }

}

class ThreadFactory {

    public Thread creatThread(Runnable runnable, String threadName) {
        return new Thread(runnable, threadName);
    }
}