### 解题思路
无需加锁，定义int类型flag，使用0，1，2代表3种状态即可实现

### 代码

```java
public class ZeroEvenOdd {
    //定义flag，为0代表执行zero，为1代表执行odd（奇数），为2代表执行even（偶数）
     private volatile int flag = 0;

    private int n;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            while (flag != 0){
                Thread.yield();
            }
            printNumber.accept(0);
            if (i % 2 != 0){
                flag = 2;
            }else {
                flag = 1;
            }

        }

    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i=i+2) {
            while (flag != 2){
                Thread.yield();
            }
            printNumber.accept(i);
            flag = 0;
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i=i+2) {
            while (flag != 1){
                Thread.yield();
            }
            printNumber.accept(i);
            flag = 0;
        }


    }
}
```