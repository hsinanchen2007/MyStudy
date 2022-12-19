### 解题思路
一组有顺序依赖关系的runnable（函数），只要判断是否轮到自己就行了。

这里写了一个template，可以应用到任意个不同task的runnable，只要他们是前后顺序紧挨的。

### 代码

```java
class Foo {

    private Object lock = new Object();
    private volatile AtomicInteger sn = new AtomicInteger();
    private final int TotalCOUNT = 3;

    public Foo() {
        sn.set(0);
    }

    protected void procTemplate(Runnable runObj, int myIndex) throws InterruptedException {
        synchronized(lock){
            while(this.sn.get()!= myIndex){
                lock.wait();
            }
            
            runObj.run();

            sn.getAndIncrement();
            if(sn.get()>=TotalCOUNT)
                sn.set(0);

            lock.notifyAll();
        }
    }

    public void first(Runnable printFirst) throws InterruptedException {
        this.procTemplate(printFirst, 0);
    }

    public void second(Runnable printSecond) throws InterruptedException {
        this.procTemplate(printSecond, 1);
    }

    public void third(Runnable printThird) throws InterruptedException {
        this.procTemplate(printThird, 2);
    }
}
```