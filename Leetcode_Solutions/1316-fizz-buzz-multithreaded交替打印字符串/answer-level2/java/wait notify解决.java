### 解题思路
当不满足条件时线程wait，满足时notify所有其他线程、输出及计数器加1

### 代码

```java
class FizzBuzz {
    private int n;
    private int c=1;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        synchronized(this){
            while(n>=c){
                if(c%3==0&&c%5!=0){
                    printFizz.run();
                    c++;
                    notifyAll();
                }else{
                    wait();
                }
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        synchronized(this){
            while(n>=c){
                if(c%5==0&&c%3!=0){
                    printBuzz.run();
                    c++;
                    notifyAll();
                }else{
                    wait();
                }
        }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        synchronized(this){
            while(n>=c){
                if(c%3==0&&c%5==0){
                    printFizzBuzz.run();
                    c++;
                    notifyAll();
                }else{
                    wait();
                }
            }
        }
    }   

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        synchronized(this){
            while(n>=c){
                if(c%3!=0&&c%5!=0){
                    printNumber.accept(c);
                    c++;
                    notifyAll();
                }
                else{
                    wait();
                }
            }
        }
    }
}
```