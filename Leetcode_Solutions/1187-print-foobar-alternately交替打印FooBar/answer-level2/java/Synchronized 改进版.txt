### 解题思路
   synchronized(this)的用法是对象锁，在for循环内部使用，相当于n把锁。或许这是提高速度的密码所在~

### 代码

```java
class FooBar {
    private int n;

    // foo() is no running.
    private boolean flag = false;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
        synchronized(this){
            if(flag){
                wait();       
            }
            flag = true;
            // printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            notifyAll();

        }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
       synchronized(this){
            if(!flag){
                wait();
            }
            flag = false;
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            notifyAll();
        }
       }
    }
}
```