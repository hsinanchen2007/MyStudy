### 解题思路
简单的事情简单做

### 代码

```java
class Foo {
    private boolean LockA = false;
    private boolean LockB = false;

    public Foo() {
    }

    public void first(Runnable printFirst) throws InterruptedException {
        printFirst.run();
        LockA = true;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while(!LockA) {
            try {
                Thread.sleep(0);
            } catch (InterruptedException IE) {
                IE.printStackTrace();
            }
        }
        printSecond.run();
        LockB = true;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while(!LockB) {
            try {
                Thread.sleep(0);
            } catch (InterruptedException IE) {
                IE.printStackTrace();
            }
        }
        printThird.run();
    }
}
```