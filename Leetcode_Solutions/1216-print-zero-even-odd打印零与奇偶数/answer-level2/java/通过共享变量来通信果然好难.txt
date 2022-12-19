```java
import java.io.IOException;
import java.util.concurrent.atomic.AtomicInteger;

class ZeroEvenOdd {
    private int n;
    private volatile boolean start;
    private volatile boolean done;
    private volatile int number = 0;
    private volatile int zeroEvent = 0;
    private volatile int evenEvent = 0;
    private volatile int oddEvent = 0;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero() {
        for (int i = 1; i <= n; i++) {
            zeroEvent = 0;//消息接收者重置
            System.out.print(0);
            number = i;
            if (!start) {start = true;};
            if (number % 2 == 1) {
                oddEvent = 1;//发送消息
            } else {
                evenEvent = 1;//发送消息
            }
            for (; zeroEvent == 0; ) {}//等待消息
        }
        done = true;
    }

    public void even() {
        for (; !start; ) {}
        for (; !done; ) {
            for (; evenEvent == 0; ) {//等待消息
                if (done) break;
                Thread.yield();
            }
            evenEvent = 0; //消息接收者重置
            if (done) break;
            System.out.print(number);
            zeroEvent = 1; //发送消息
        }
    }

    public void odd() {
        for (; !start; ) {}
        for (; !done; ) {
            for (; oddEvent == 0; ) {//等待消息
                if (done) break;
                Thread.yield();
            }
            oddEvent = 0;//消息接收者重置
            if (done) break;
            System.out.print(number);
            zeroEvent = 1;//发送消息
        }
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        var obj = new ZeroEvenOdd(10);
        new Thread(obj::zero).start();
        new Thread(obj::odd).start();
        new Thread(obj::even).start();
    }
}
```