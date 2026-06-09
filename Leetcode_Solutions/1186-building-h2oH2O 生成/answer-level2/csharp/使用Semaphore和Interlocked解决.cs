``` c#
using System;
using System.Threading;
public class H2O {

    public H2O() {
        
    }
    
    private Semaphore _hydrogenSema = new Semaphore(2, 2);
    private Semaphore _oxygenSema = new Semaphore(0, 1);
    private int _hydrogenCount = 0;

    public void Hydrogen(Action releaseHydrogen) {
		_hydrogenSema.WaitOne();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        // 原子操作 将H的数量+1 也可以使用lock方式
        Interlocked.Increment(ref _hydrogenCount);
        // 两个H都输出了 才输出O
        if (_hydrogenCount % 2 == 0) {
            _oxygenSema.Release();
        }
    }

    public void Oxygen(Action releaseOxygen) {
        // 等待其他两个H到达 就可以输出O了
        _oxygenSema.WaitOne();
        // releaseOxygen() outputs "O". Do not change or remove this line.
		releaseOxygen();
        // 可以开始接收H了
        _hydrogenSema.Release(2);
    }
}
```
