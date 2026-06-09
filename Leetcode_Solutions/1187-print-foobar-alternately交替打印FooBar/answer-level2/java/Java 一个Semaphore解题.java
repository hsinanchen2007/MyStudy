**解题思路**
控制循环次数，减少变量的使用
Semaphore，信号量交替增加，每次获取的信号量比前一次循环中最大Semaphore需求量多1，
循环下标index_i=：0 1 2 
线程foo请求信号量：1 3 5
线程foo释放信号量：2 4 6  ===》每次foo释放的信号量，需满足条件：够本次循环中bar的请求量，且不够foo下次的请求量
线程bar请求信号量：2 4 6
线程bar释放信号量：3 5 7	 ===》每次bar释放的信号量，需满足条件：够下次循环中foo的请求量，且不够bar下次的请求量

```
class FooBar {
    private int n;
    public FooBar(int n) {
        this.n = n;
    }
    private Semaphore semaphore = new Semaphore(1);
    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            semaphore.acquire(2 * i + 1);
            printFoo.run();
            semaphore.release(2 * i + 2);
        }
    }
    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            semaphore.acquire(2 * i + 2);
            printBar.run();
            semaphore.release(2 * i + 3);
        }
    }
}
```