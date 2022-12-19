一个氧消耗两个氢。两个氢供给一个氧。
信号量定义，有点tricky：
//表示供给给氧的氢数量
Semaphore oxygen = new Semaphore(2);
//表示供给给氢的氢数量
Semaphore hydrogen = new Semaphore(0);
代码：
```
import java.util.concurrent.Semaphore;
class H2O {

    Semaphore oxygen = new Semaphore(2);
    Semaphore hydrogen = new Semaphore(0);

    public H2O() {

    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        hydrogen.acquire();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        oxygen.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        oxygen.acquire(2);
        // releaseOxygen.run() outputs "H". Do not change or remove this line.
        releaseOxygen.run();
        hydrogen.release(2);
    }
}
```


