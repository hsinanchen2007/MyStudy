### 解题思路

题目最开始想到的就是用一个变量限制线程的执行顺序，然后就加了volatile的变量a，在循环中判断a的值然后进行打印，实际运行的时候发现这种情况很容易超时，这时候判断是线程在循环中占用资源，另一线程无法执行导致，所以想到了用线程的join方法当不满足打印条件时把资源释放出来，然后另一线程被调用，循环交替就成功了
![image.png](https://pic.leetcode-cn.com/94800379e435f055bd745fa4646af98bd929c7c8ebb7ba8ef2485b63b33f34c4-image.png)


### 代码

```java
class FooBar {
    private int n;
    private volatile int a = 0;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            if (a == 0){
        	    // printFoo.run() outputs "foo". Do not change or remove this line.
        	    printFoo.run();
                a = 1;
            } else {
                i--;
                Thread.currentThread().join(1);
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            if (a == 1){
                // printBar.run() outputs "bar". Do not change or remove this line.
        	    printBar.run();
                a = 0;
            } else {
                i--;
                Thread.currentThread().join(1);
            }
        }
    }
}
```