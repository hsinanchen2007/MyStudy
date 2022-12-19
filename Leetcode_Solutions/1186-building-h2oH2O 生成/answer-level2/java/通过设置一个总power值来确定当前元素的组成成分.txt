* 我们可以先假设一个总power=0;
* 每产生一个h或者o都会使总power变大,当总power超过屏障时候就会产生下个H2O
* 先确定h和o各种的power值
    * 需要满足的条件是
        * o的power值在达到屏障前不能由多个h的power值累加产生
            * 换句话来说o的power值不能是h的power值的倍数
    * 满足这个条件的是两个数有很多,我选择2和3
    * 为什么需要这个条件，因为有了这个条件我们就能根据总power值来确定当前有什么元素
        * 根据不同的总power值我们能得到如下的情况
            * 0 -> 无h无o       :这个时候我们既可以放h也可以放o
            * 2 -> 1个h         :这个时候我们既可以放h也可以放o
            * 3 -> 1个o         :这个时候我们只能放h
            * 4 -> 2个h         :这个时候我们只能放o
            * 5 -> 1个h和1个o   :这个时候我们只能放h
            * 7 -> 屏障突破
```
class H2O {

    private volatile int power=0;

    public H2O() {
        
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        synchronized (this){
            while(power!=0&&power!=2&&power!=3&&power!=5){
                this.wait();
            }
            // releaseHydrogen.run() outputs "H". Do not change or remove this line.
            releaseHydrogen.run();
            power=(power+2)%7;
            this.notifyAll();
        } 
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        synchronized (this){
            while(power!=0&&power!=2&&power!=4){
                this.wait();
            }
            // releaseOxygen.run() outputs "H". Do not change or remove this line.
            releaseOxygen.run();
            power=(power+3)%7;
            this.notifyAll();
        }
        
		
    }
}
```
