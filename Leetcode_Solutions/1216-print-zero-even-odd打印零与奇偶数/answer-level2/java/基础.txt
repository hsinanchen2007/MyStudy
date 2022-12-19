### 解题思路
此处撰写解题思路

### 代码

```java
class ZeroEvenOdd {
    private int n;
    private int flag = 0;
    //private int step=0;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            synchronized (this) {
                while (flag != 0) {
                    this.wait();
                }
                printNumber.accept(0);
                if ((i + 1) % 2 == 1) {
                    flag = 2;
                } else {
                    flag = 1;
                }
                this.notifyAll();
            }

        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {

        for (int i = 2; i <= n; i += 2) {
            synchronized (this) {
                while (flag == 2||flag==0) {
                    this.wait();
                }
                printNumber.accept(i);
                flag = 0;
                this.notifyAll();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {

        for (int i = 1; i <= n; i += 2) {
            synchronized (this) {
                while (flag == 1||flag==0) {
                    this.wait();
                }
                printNumber.accept(i);
                flag = 0;
                this.notifyAll();
            }
        }
    }
}
```