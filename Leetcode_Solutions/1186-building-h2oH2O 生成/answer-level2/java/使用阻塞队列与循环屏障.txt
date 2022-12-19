
执行用时 :29 ms, 在所有 Java 提交中击败了93.97%的用户
内存消耗 :38.7 MB, 在所有 Java 提交中击败了100.00%的用户
题目很容易误导人，让人以为只有两条线程分别两个方法，实际上有很多个线程分别调用两个方法。

```
import java.util.concurrent.*;
    class H2O {

        private BlockingQueue<String> h = new ArrayBlockingQueue<>(2);
        private BlockingQueue<String> o = new ArrayBlockingQueue<>(1);
        private CyclicBarrier cyclicBarrier = new CyclicBarrier(3);
        public H2O() {

        }
        public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
                h.put("H");
                // releaseHydrogen.run() outputs "H". Do not change or remove this line.
                releaseHydrogen.run();
            try {
                cyclicBarrier.await();
            } catch (BrokenBarrierException e) {
            }
            h.take();
        }
        public void oxygen(Runnable releaseOxygen) throws InterruptedException {
                o.put("O");
                // releaseOxygen.run() outputs "H". Do not change or remove this line.
                releaseOxygen.run();
            try {
                cyclicBarrier.await();
            } catch (BrokenBarrierException e) {
            }
                o.take();
        }
    }
```
