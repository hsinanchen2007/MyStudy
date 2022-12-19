执行用时 :10 ms, 在所有 Java 提交中击败了85.71%的用户
内存消耗 :36.9 MB, 在所有 Java 提交中击败了100.00%的用户
`   
    
    class ZeroEvenOdd {

        private int n;
        private int flag = 0;
        private volatile int tempN = 1;
        private Object object = new Object();

        public ZeroEvenOdd(int n) {
            this.n = n;
        }

        // printNumber.accept(x) outputs "x", where x is an integer.
        public void zero(IntConsumer printNumber) throws InterruptedException {

            while (tempN <= n){
                synchronized (object){
                    while(flag != 0){
                        object.wait();
                    }
                    if(tempN <= n){
                        printNumber.accept(0);
                    }
                    if((tempN&1) == 1){
                        flag = 1;
                    }else{
                        flag = 2;
                    }
                    object.notifyAll();
                }
            }
        }

        public void even(IntConsumer printNumber) throws InterruptedException {

            while (tempN <= n){
                synchronized (object){
                    while(flag != 2){
                        object.wait();
                    }
                    if(tempN <= n){
                        printNumber.accept(tempN);
                    }
                    flag = 0;
                    tempN++;
                    object.notifyAll();
                }
            }

        }

        public void odd(IntConsumer printNumber) throws InterruptedException {
            while (tempN <= n){
                synchronized (object){
                    while (flag != 1){
                        object.wait();
                    }
                    if(tempN <= n){
                        printNumber.accept(tempN);
                    }
                    flag = 0;
                    tempN++;
                    object.notifyAll();
                }
            }

        }
    }
`