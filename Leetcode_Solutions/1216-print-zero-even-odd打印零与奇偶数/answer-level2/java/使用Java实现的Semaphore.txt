### 解题思路
此处撰写解题思路

### 代码

```java
class ZeroEvenOdd {
    private int n;

    /**
     * 思路：
     * Java提供的Semaphore，Semaphore的实现直接通过继承AQS的方式，有公平和非公平的方式
     * 每次acquire时，将permit-1，release时+1
     * 这里使用三个信号量实例，每个permits都是1
     * 在每个方法执行前获取许可，否则阻塞等待，执行完后释放后续需要执行的许可
     * semaphoreZero semaphoreEven semaphoreOdd
     * 三个线程启动后，并不会知道谁先被执行，而我们又需要顺序行，就要使得Zero线程先执行输出
     * 其他两个被阻塞，待Zero执行后再选择执行
     * 于是 初始化semaphoreZero时许可为1 其他两个许可为0
     * 在Zero执行后，需要输出Odd的线程从获取许可的阻塞状态恢复，这里无论Odd线程是否已经被阻塞在acquire还是在处于Runnable但是并未真正执行的情况
     * 都不会影响Odd线程顺序执行输出，因为semaphoreZero并没有release，而Even线程即使获取到执行机会也会被阻塞在acquire
     * 
     * 使用信号量的实现方式，比使用ReentrantLock更加的简洁易懂，但是耗时却多了些
     * 可能原因是因为线程await时是会立马unpark，而Semaphore的acquire则是进行CAS直至success
     */

    private Semaphore semaphoreZero = new Semaphore(1);
    private Semaphore semaphoreOdd = new Semaphore(0);
    private Semaphore semaphoreEven = new Semaphore(0);

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {

        for (int i = 1; i <= n; i++) {

            semaphoreZero.acquire();
            printNumber.accept(0);
            if ((i & 1) == 1) {
                semaphoreOdd.release();
            } else {
                semaphoreEven.release();
            }

        }

    }

    public void even(IntConsumer printNumber) throws InterruptedException {

        for (int i = 2; i <= n; ) {
            semaphoreEven.acquire();
            printNumber.accept(i);
            i += 2;
            semaphoreZero.release();
        }

    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; ) {
            semaphoreOdd.acquire();
            printNumber.accept(i);
            i += 2;
            semaphoreZero.release();
        }
    }

}
```