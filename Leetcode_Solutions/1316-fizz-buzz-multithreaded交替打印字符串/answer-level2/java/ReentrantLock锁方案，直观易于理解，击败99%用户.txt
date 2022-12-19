### 解题思路

执行用时 :5 ms, 在所有 java 提交中击败了99.41%的用户
内存消耗 :36.2 MB, 在所有 java 提交中击败了100.00%的用户

只使用ReentrantLock锁，加上一个Condition用于线程间通信。*try..finally..*是模板写法；其中while(!条件)中的条件是判断四种情况，当不满足情况时就*condition.await();*线程阻塞；满足情况就跳出while循环执行输出，输出结束后将num加一，并且*condition.signalAll();*通知被阻塞的线程；特别注意的是，由于使用while循环判断，当输出的个数到达n时，需要额外的判断num>n来退出方法，不然线程会一直阻塞，程序无法结束。在代码中是每个方法的两处if(num>n)判断。

    

### 代码

```java
class FizzBuzz {
    private int n;
    ReentrantLock lock=new ReentrantLock();
    Condition condition=lock.newCondition();
    private volatile int num=1;
    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for(;num<=n;){
            //加锁的模板代码
            lock.lock();
            try{
                //while循环判断，不符合条件就挂起线程
                while(!(num%3==0 && num%5!=0)){
                    if(num>n){
                        return;
                    }
                    condition.await();
                }
                //对结束条件的判断，用于退出方法
                if(num>n){
                        return;
                }

                printFizz.run();
                num++;
                condition.signalAll();
            }finally{
                lock.unlock();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for(;num<=n;){
            lock.lock();
            try{
                while(!(num%3!=0 && num%5==0)){
                    if(num>n){
                        return;
                    }
                    condition.await();
                }
                if(num>n){
                            return;
                }
                printBuzz.run();
                num++;
                condition.signalAll();
            }finally{
                lock.unlock();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for(;num<=n;){
            lock.lock();
            try{
                while(!(num%3==0 && num%5==0)){
                    if(num>n){
                        return;
                    }
                    condition.await();
                }
                if(num>n){
                            return;
                }
                printFizzBuzz.run();
                num++;
                condition.signalAll();
            }finally{
                lock.unlock();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for(;num<=n;){
            lock.lock();
            try{
                while(num%3==0 || num%5==0){
                    if(num>n){
                        return;
                    }
                    condition.await();
                }
                if(num>n){
                            return;
                }
                printNumber.accept(num);
                num++;
                condition.signalAll();
            }finally{
                lock.unlock();
            }
        }
    }
}
```