### 解题思路
简单的自旋操作

### 代码

```java
class Foo {

    volatile boolean fFin = false;
    volatile boolean sFin = false;

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        fFin = true;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while (!fFin) {

        }
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        sFin = true;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while (!sFin) {

        }
        
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```