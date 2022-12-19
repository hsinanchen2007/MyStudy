执行用时 :35 ms, 在所有 Java 提交中击败了87.82%的用户
内存消耗 :38.8 MB, 在所有 Java 提交中击败了100.00%的用户

```
    import java.util.concurrent.*;
    class FooBar {
        private int n;
        private BlockingQueue<Integer> queue2 = new ArrayBlockingQueue(1);
        private BlockingQueue<Integer> queue1 = new ArrayBlockingQueue(1);
        public FooBar(int n)  {
            this.n = n;
        }
        public void foo(Runnable printFoo) throws InterruptedException {
            for (int i = 0; i < n; i++) {
                queue1.put(1);
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                queue2.put(1);
            }
        }

        public void bar(Runnable printBar) throws InterruptedException {
            for (int i = 0; i < n; i++) {
                queue2.take();
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                queue1.take();
            }
        }
    }
```



