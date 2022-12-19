### 解题思路
leetcode问题严重啊，我都写了好多个正确答案，各种出错。最后这个方案，测试用例结果还是缺失的...
本地没问题，线上各种少，目测C#bug较多...
或者有没有人能指点一下？感觉被折磨死了...

### 代码

```csharp
using System.Threading;
using System;
public class H2O {

    private Semaphore _o = new Semaphore(1, 1);
    private Semaphore _h = new Semaphore(0, 2);
    private int iH=0;

    public H2O() {
        
    }

    public void Hydrogen(Action releaseHydrogen) {
		 _h.WaitOne();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        Interlocked.Increment(ref iH);
        if(iH%2==0)
        {
            _o.Release();
        }
    }

    public void Oxygen(Action releaseOxygen) {
        _o.WaitOne();
        // releaseOxygen() outputs "O". Do not change or remove this line.
		releaseOxygen();
        _h.Release(2);
    }
}
```