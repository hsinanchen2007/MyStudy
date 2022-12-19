### 解题思路
就是依次靠变量控制即可

### 代码

```java
class Foo {

    boolean isMethod1Executed = false;
    boolean isMethod2Executed = false;

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        isMethod1Executed = true;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while(!isMethod1Executed) {
            try {
                Thread.sleep(20);
            }catch (InterruptedException i){

            }
        }
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        isMethod2Executed = true;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while(!isMethod2Executed) {
            try {
                Thread.sleep(20);
            }catch (InterruptedException i){

            }
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```