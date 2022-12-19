### 解题思路
此处撰写解题思路

### 代码

```java
class FooBar {
    private int n;
    private CountDownLatch countFoo;
    private CountDownLatch countBar;

    public FooBar(int n) {
        this.n = n;
        countFoo = new CountDownLatch(0);
        countBar = new CountDownLatch(1);
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo.run() outputs "foo". Do not change or remove this line.
            countFoo.await();
        	printFoo.run();
            countFoo = new CountDownLatch(1);
            countBar.countDown();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            // printBar.run() outputs "bar". Do not change or remove this line.
            countBar.await();
        	printBar.run();
            countBar = new CountDownLatch(1);
            countFoo.countDown();
        }
    }
}
```