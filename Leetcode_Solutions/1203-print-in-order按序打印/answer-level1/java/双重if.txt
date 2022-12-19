### 解题思路保证执行，不用while  空间换取时间
此处撰写解题思路

### 代码

```java
class Foo {
    private  int flag=1;
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        synchronized(this){
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        flag=2;
        notifyAll();}
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized(this){
        if(flag != 2){wait();}
                if(flag != 2){wait();}

        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        flag=3;
        notifyAll();
    }}

    public void third(Runnable printThird) throws InterruptedException {
        synchronized(this){if(flag !=3){wait();}
                if(flag != 3){wait();}

        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }}
}
```