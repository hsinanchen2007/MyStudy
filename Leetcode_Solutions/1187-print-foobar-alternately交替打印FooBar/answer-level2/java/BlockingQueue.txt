```java []
import java.util.ArrayList;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

public class FooBar {
    private int n;
    private BlockingQueue<Integer> barQueue;
    private BlockingQueue<Integer> fooQueue;

    public FooBar(int n) {
        this.n = n;
        barQueue = new LinkedBlockingQueue<>();
        ArrayList<Integer> arrayList = new ArrayList();
        arrayList.add(0);
        fooQueue = new LinkedBlockingQueue<>(arrayList);
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            fooQueue.take();
            printFoo.run();
            barQueue.put(i);
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            barQueue.take();
            printBar.run();
            fooQueue.put(i);
        }
    }
}
```
