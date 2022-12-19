### 解题思路
题目要求很有规律，先打印foo，再打印bar，再打印foo...也就是说，foo和bar打印前都需要在对方打印后获取许可。常规可以通过两个信号量来操作，但明显foo和bar是一一对应的关系，所以可以通过一个信号量来实现交替打印。
感谢@YUCONG提醒，信号获取和打印间不是原子的，foo和bar在获取信号和打印之间有可能交叉执行，解决方法是将信号获取放到打印完成之后。正确答案见 代码（修改）

### 代码（错误）

```java
class FooBar {
    private int n;

    private Semaphore semaphore = new Semaphore(1);

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            
            semaphore.acquire();

            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            while (semaphore.availablePermits() != 0) {
                
            }
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            semaphore.release();
        }
    }

}
```
上面打印bar前需要用while循环等待信号量为0，通过这个特殊状态代替一个信号量的判断。

### 代码（修改）

```java
class FooBar {

    private int n;

    private Semaphore semaphore = new Semaphore(1);

    private volatile boolean foo = false;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            semaphore.acquire();
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            foo = true;
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            while (!foo) {
            }
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            foo = false;
            semaphore.release();
        }
    }

}
```