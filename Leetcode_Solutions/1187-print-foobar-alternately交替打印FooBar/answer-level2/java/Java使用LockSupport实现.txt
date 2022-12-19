public class FooBar {

    private  int n ;
    private volatile  int flag = 1;
    private  Thread t1 = new Thread(this::foo);
    private  Thread t2 = new Thread(this::bar);

    FooBar(int n) {
        this.n = n;
    }


    public  void foo() {
        for (int i = 0; i < n; i++) {
            while (flag != 1) {
                LockSupport.park();
            }
            print("foo");
            flag = 0;
            LockSupport.unpark(t2);
        }
    }

    public  void bar() {
        for (int i = 0; i < n; i++) {
            while (flag != 0) {
                LockSupport.park();
            }
            print("bar");
            flag = 1;
            LockSupport.unpark(t1);
        }
    }

    public  void print(String s) {
        System.out.printf(s);
    }
}