```
class FooBar {

    private int n;
    AtomicInteger count;
    public FooBar(int n) {
        this.n = n;
        this.count = new AtomicInteger(1);
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 1; i < n*2; i+=2) {
            while (!count.compareAndSet(i,-i)) {
            }
            printFoo.run();
            while (!count.compareAndSet(-i,i+1)) {
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 2; i <= n*2; i+=2) {
            while (!count.compareAndSet(i,-i)) {
            }
            printBar.run();
            while (!count.compareAndSet(-i,i+1)) {
            }
        }
    }
}
```
