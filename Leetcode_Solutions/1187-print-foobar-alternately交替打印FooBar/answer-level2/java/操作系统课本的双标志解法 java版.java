用foo和bar 两个标志位控制双方互斥进入缓冲区， 因为是volatile修饰， 所以需要两个标志位， 大家可以试试把foo和bar换成一个变量。
用turn标志位控制双方交替进入缓冲区。
```
import java.util.concurrent.locks.ReentrantLock;

class FooBar {
    private ReentrantLock lock = new ReentrantLock();

    private volatile int turn = 0;
    private volatile int foo = 0;
    private volatile int bar = 0;
    private int n;
    
    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            while (bar == 1 || turn == 1){}
            foo = 1;
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            turn = 1;
            foo = 0;
            
            
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            while (foo == 1 || turn == 0){}
            bar = 1;
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            turn = 0;
            bar = 0;
        }
    }
}

```
