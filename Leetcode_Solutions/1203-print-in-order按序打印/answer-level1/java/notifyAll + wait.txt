### 解题思路
直接使用wait和notifyAll解决了。最近刚看了Think in Java的并发章节，里面大量这样的代码，把书上的代码照着敲一遍真的能让自己充分理解其中的思路。

### 代码

```java
class Foo {

    public Foo() {
        
    }

    byte status = 1;

    public void first(Runnable printFirst) throws InterruptedException {
        synchronized (this) {
            printFirst.run();
            status = 2;
            notifyAll();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized (this) {
            while (status < 2) {
                wait();
            }
        }
        synchronized (this) {
            printSecond.run();
            status = 3;
            notifyAll();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized (this) {
            while (status < 3) {
                wait();
            }
        }
        synchronized (this) {
            printThird.run();
            notifyAll();
        }
    }
}
```