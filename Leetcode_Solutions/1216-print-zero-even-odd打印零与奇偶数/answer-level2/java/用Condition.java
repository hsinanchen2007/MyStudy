`

    class ZeroEvenOdd {

        private int n;
        private int flag = 0;
        private Lock lock = new ReentrantLock();
        private Condition zero = lock.newCondition();
        private Condition even = lock.newCondition();
        private Condition odd = lock.newCondition();


        public ZeroEvenOdd(int n) {
            this.n = n;
        }

        // printNumber.accept(x) outputs "x", where x is an integer.
        public void zero(IntConsumer printNumber) throws InterruptedException {
            try {
                lock.lock();
                for(int i = 1;i <= n;i++){
                    if(flag != 0){
                        zero.await();
                    }
                    printNumber.accept(0);
                    if((i & 1) == 0){
                        flag = 2;
                        even.signal();

                    }else{
                        flag = 1;
                        odd.signal();
                    }
                }
            }finally {
                lock.unlock();
            }

        }

        public void even(IntConsumer printNumber) throws InterruptedException {
            try {
                lock.lock();
                for(int i = 2;i <= n;i=i+2){
                    if(flag != 2){
                        even.await();
                    }
                    printNumber.accept(i);
                    flag = 0;
                    zero.signal();
                }
            }finally {
                lock.unlock();
            }

        }

        public void odd(IntConsumer printNumber) throws InterruptedException {
            try {
                lock.lock();
                for(int i = 1;i <= n;i=i+2){
                    if(flag != 1){
                        odd.await();
                    }
                    printNumber.accept(i);
                    flag = 0;
                    zero.signal();
                }
            }finally {
                lock.unlock();
            }

        }
    }

`