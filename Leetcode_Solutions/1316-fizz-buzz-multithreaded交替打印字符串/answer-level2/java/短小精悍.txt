### 解题思路
用4个信号量，来控制4种打印，每次打印完，负责唤醒下一位，超过n了则唤醒所有，以便退出，由number开始打印1，故将其信号量初始化为1。
m不需要用volatile，happens-before原则保证了其可见性，同时交替执行的特点保证了它不会发生竞争

本实现避免了不能干活的线程被唤醒，然后啥也没干，继续睡

### 代码

```java
class FizzBuzz {
    private int n, m =1;
    private Semaphore[] semaphores = new Semaphore[]{new Semaphore(1),new Semaphore(0),new Semaphore(0),new Semaphore(0)};

    public FizzBuzz(int n) {
        this.n = n;
    }

    public void fizz(Runnable printFizz) throws InterruptedException {
        doWork(1, x->printFizz.run());
    }

    public void buzz(Runnable printBuzz) throws InterruptedException {
        doWork(2, x->printBuzz.run());
    }

    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        doWork(3, x->printFizzBuzz.run());
    }

    public void number(IntConsumer printNumber) throws InterruptedException {
        doWork(0, printNumber);
    }

    public void doWork(int index, IntConsumer printer) throws InterruptedException {
        while(m<=n){
            semaphores[index].acquire();
            if(m>n) return;
            printer.accept(m);
            if(++m>n){
                for(Semaphore s:semaphores){
                    s.release();
                }
            }else{
                semaphores[(m % 3 == 0 ? 1 : 0) + (m % 5 == 0 ? 2 : 0)].release();
            }
        }
    }
}
```