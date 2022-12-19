执行用时 :23 ms,  java 中击败了79.58%的用户；内存消耗 :36.4 MB, java 中击败了100.00%的用户


`class FooBar {
    private int n;

    public FooBar(int n) {
        this.n = n;
    }
    
    private int flag = 1;
    private Object lock = new Object();
    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            synchronized (lock){
                if (flag%2==0){// 如果是偶数则等待
                    lock.wait();
                }
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                flag++;
                lock.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            synchronized (lock){
                if (flag%2!=0){// 如果是奇数，则等待
                    lock.wait();
                }
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                flag++;
                lock.notifyAll();
            }
        }
    }
}`