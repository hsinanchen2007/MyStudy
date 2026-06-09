### 解题思路
模仿一个生产者，一个消费者的情形

### 代码

```java
class FooBar {
    private int n;
    private Lock lock=new ReentrantLock();
    private Condition condition=lock.newCondition();
    //模拟生产者消费者模式，用于判断共享变量是否为空
    private boolean isEmpty=true;

    public FooBar(int n) {
        this.n = n;
    }

    //类似生产者offer数据
    public void foo(Runnable printFoo) throws InterruptedException {

        lock.lock();

        for (int i = 0; i < n; i++) {

            while(!isEmpty){
                condition.await();
            }
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            isEmpty=false;
                
            condition.signal();
           
        }
        lock.unlock();
        
    }

    //类似消费者take数据
    public void bar(Runnable printBar) throws InterruptedException {
        lock.lock();

        for (int i = 0; i < n; i++) {

            while(isEmpty){
                condition.await();
            }
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            isEmpty=true;
                
            condition.signal();
           
        }
        lock.unlock();

    }
}
```