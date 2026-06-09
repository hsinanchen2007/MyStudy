执行用时 : 29 ms, 在所有 Java 提交中击败了 99.11% 的用户
内存消耗 : 38.9 MB, 在所有 Java 提交中击败了 100.00% 的用户

```
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

class FooBar {

    private CyclicBarrier foo;
    private CyclicBarrier bar;
    private int n;

    public FooBar(int n) {
        this.n = n;
        foo = new CyclicBarrier(2, null);
        bar = new CyclicBarrier(2, null);
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            try {
                bar.await();
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                foo.await();
            } catch (BrokenBarrierException e) {
                e.printStackTrace();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            try {
                bar.await();
                foo.await();
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
            } catch (BrokenBarrierException e) {
                e.printStackTrace();
            }
        }
    }
}
```
