### 解题思路
此处撰写解题思路

### 代码

```java
 public class H2O {
    private volatile int h = 0;
    private volatile int o = 0;
    private CyclicBarrier cyclicBarrier = new CyclicBarrier(2,()->{h = 0;o = 0;});

    private final static String H_LOCK = "java";
    private final static String O_LOCK = "class";

    public H2O() {}

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException{
        try {
            synchronized (H_LOCK) {
                if (h == 2) {
                    cyclicBarrier.await();
                }
            }
        }catch (BrokenBarrierException e){
            e.printStackTrace();
        }
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        h++;
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {

        try {
            synchronized (O_LOCK) {
                if (o == 1)
                    cyclicBarrier.await();
            }
        } catch (BrokenBarrierException e) {
            e.printStackTrace();
        }
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        releaseOxygen.run();
        o++;
    }
 }
```