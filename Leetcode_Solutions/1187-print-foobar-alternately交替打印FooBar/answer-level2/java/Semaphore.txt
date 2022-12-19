### 解题思路
简单信号量即可解决

### 代码

```java
class FooBar {
    private int n;
        Semaphore s1 = new Semaphore(1); 
        Semaphore s2 = new Semaphore(1);   
    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
       
        for (int i = 0; i < n; i++) {
       	// printFoo.run() outputs "foo". Do not change or remove this line.
        try {
            s1.acquire();
            	printFoo.run();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }finally{
            s2.release();
        }
        
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
              try {
            s2.acquire();
            	printBar.run();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }finally{
            s1.release();
        }
    }
}
}
```