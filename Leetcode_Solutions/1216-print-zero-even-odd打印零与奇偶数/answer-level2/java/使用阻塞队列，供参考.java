执行用时 :10 ms, 在所有 Java 提交中击败了78.22%的用户
内存消耗 :36.6 MB, 在所有 Java 提交中击败了100.00%的用户
```
import java.util.concurrent.*;    
    class ZeroEvenOdd {
        private int n;
        private int count;
        private BlockingQueue<Integer> blockingQueue1 = new ArrayBlockingQueue<>(1);
        private BlockingQueue<Integer> blockingQueue2 = new ArrayBlockingQueue<>(1);
        private BlockingQueue<Integer> blockingQueue3 = new ArrayBlockingQueue<>(1);
        public ZeroEvenOdd(int n) {
            this.n = n;
            count = 2*n;
        }

        // printNumber.accept(x) outputs "x", where x is an integer.
        public void zero(IntConsumer printNumber) throws InterruptedException {
          for (int i = 1,j=1;i<=count;i=i+2,j++){
              blockingQueue1.put(i);
              printNumber.accept(0);
              if (j%2==1){
                  blockingQueue3.put(j);
              }else {
                  blockingQueue2.put(j);
              }
           }
        }

        public void even(IntConsumer printNumber) throws InterruptedException {
            int i = (n)/2;
            for (int j = 1;j<=i;j++){
                Integer integer =  blockingQueue2.take();
                printNumber.accept(integer);
                blockingQueue1.take();
            }
        }

        public void odd(IntConsumer printNumber) throws InterruptedException {
            int i = (n+1) / 2;
            for (int j = 1; j <= i; j++) {
              Integer integer =  blockingQueue3.take();
                printNumber.accept(integer);
                blockingQueue1.take(); 
            }
        }

        }
```
