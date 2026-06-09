
执行用时 :34 ms, 在所有 Java 提交中击败了93.70%的用户
内存消耗 :38.4 MB, 在所有 Java 提交中击败了100.00%的用户

CAS一下就好了

``` java
class FooBar {
    
    private int n;
    private volatile int lock = 0;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            casGet(0);
            
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            
            lock++;
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            casGet(1);
            
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            
            lock++;
        }
    }
    
    private void casGet(int except) {
        for (;;) {
            if (lock % 2 == except)
                return;
        }
    }
}
```