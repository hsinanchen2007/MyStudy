### 解题思路
![{DX@WF\]L9BA$73817EVO05A.png](https://pic.leetcode-cn.com/8e90669eb3c609a4eae6e34ca1104cbba6f22634a5b233820649355a69125517-%7BDX@WF%5DL9BA$73817EVO05A.png)
利用三个信号量分别控制三个方法，让其依次打印
### 代码

```java
class ZeroEvenOdd {
    private int n;
    private Semaphore zeroSemaphore = new Semaphore(0);
    private Semaphore evenSemaphore = new Semaphore(0);
    private Semaphore oddSemaphore = new Semaphore(1);
    private int i = 1;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        while (true) {
            zeroSemaphore.acquire();
            if (i > n) {
                return;
            }
            printNumber.accept(0);
            oddSemaphore.release();// 打印完0后继续执行odd方法
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        while (true) {
            evenSemaphore.acquire();
            if (i > n) {
                return;
            }
            printNumber.accept(i);
            oddSemaphore.release();// 打印完偶数后继续执行odd方法
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        while (i <= n) {
            oddSemaphore.acquire();          
            zeroSemaphore.release();// 打印0
            oddSemaphore.acquire();// 阻塞当前线程，等待0打印完成
            if ((i & 1) != 0) {
                printNumber.accept(i);// 打印奇数
            } else {
                evenSemaphore.release();// 打印偶数
                oddSemaphore.acquire();// 阻塞当前线程，等待偶数打印完成
            }
            i++;    
            oddSemaphore.release();
        }
        // 释放最后遗留的锁
        zeroSemaphore.release();
        evenSemaphore.release();
    }
}
```