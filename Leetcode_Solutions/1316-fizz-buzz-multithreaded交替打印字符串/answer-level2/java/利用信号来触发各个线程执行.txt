### 解题思路
利用信号来触发各个线程执行

### 代码

```java
class FizzBuzz {
   
     private int n;

    public FizzBuzz(int n) {
        this.n = n;
    }

    /**
     * 利用信号来触发各个线程执行
     * 初始情况 只有number有信号
     */
    private Semaphore fizz = new Semaphore(0);
    private Semaphore buzz = new Semaphore(0);
    private Semaphore fizzbuzz = new Semaphore(0);
    private Semaphore number = new Semaphore(1);


    /**
     * 该方法等待 fizz 信号输出3的倍数 ，输出完了给number传信号
     * @param printFizz
     * @throws InterruptedException
     */
    public void fizz(Runnable printFizz) throws InterruptedException {
        for (int j = 3; j <= n; j = j + 3 ) {
            //如果是3和5的公倍数 跳过
            if (j % 5 == 0) {
                continue;
            }

            fizz.acquire(1);
            printFizz.run();
            number.release(1);
        }


    }

    /**
     * 该方法等待 buzz 信号输出5的倍数 ，输出完了给number传信号
     * @param printFizz
     * @throws InterruptedException
     */
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for (int j = 5; j <= n; j = j + 5) {
            //如果是3和5的公倍数 跳过
            if (j % 3 == 0) {
                continue;
            }

            buzz.acquire(1);
            printBuzz.run();
            number.release(1);
        }

    }

    /**
     * 该方法等待 fizzbuzz 信号输出15的倍数 ，输出完了给number传信号
     * @param printFizzBuzz
     * @throws InterruptedException
     */
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for (int j = 15; j <= n; j = j + 15) {
            fizzbuzz.acquire(1);
            printFizzBuzz.run();
            number.release(1);
        }
    }

    /**
     * 该方法可以负责1到n的输出信号控制
     * @param printNumber
     * @throws InterruptedException
     */
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int j = 1; j <= n; j++) {
            //等待number信号
            number.acquire(1);

            //如果是15的公倍数 发信号给 fizzbuzz 然后跳到下一轮
            if (j % 3 == 0 && j % 5 == 0) {
                fizzbuzz.release(1);
                continue;
            }

            //如果是3的倍数 发信号给 fizz 然后跳到下一轮
            if(j % 3 == 0){
                fizz.release(1);
                continue;
            }

            //如果是5的倍数 发信号给 buzz 然后跳到下一轮
            if(j % 5 == 0){
                buzz.release(1);
                continue;
            }

            //不满足上述条件，执行printNumber
            printNumber.accept(j);
            //释放number信号
            number.release(1);
        }
        }
   
}
```