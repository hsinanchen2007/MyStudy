核心是线程数据共享也就是volatile，增加一个参数即可完成
```
class FooBar {
    private int n;
    volatile boolean isfoo = true;
    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            while (!isfoo){}
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            isfoo = false;
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            while (isfoo){}
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            isfoo = true;
        }
    }
}
```


