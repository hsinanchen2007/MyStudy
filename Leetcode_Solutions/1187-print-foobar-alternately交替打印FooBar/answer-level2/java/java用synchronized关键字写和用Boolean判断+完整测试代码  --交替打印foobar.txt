### 解题思路
此处撰写解题思路
		有两种思路，第一个用synchronized关键字，这种比较容易想到吧，学过javase就能想到了；然后通过代码分析可以想出来：我们只通过一个boolean变量可以么，然后就演变出来了另外一种；
### 代码

```java
class FooBar {
	    private int n;
	    private boolean fooTurn = true;
	    private Object lock = new Object();
	    public FooBar(int n) {
	        this.n = n;
	    }

	    public void foo(Runnable printFoo) throws InterruptedException {
	        
	        for (int i = 0; i < n; i++) {
	            
	            synchronized(lock) {
	                if (!fooTurn) lock.wait();
	                fooTurn = false;
	                // printFoo.run() outputs "foo". Do not change or remove this line.
	                printFoo.run();
	                lock.notifyAll();
	            }
	        }
	    }

	    public void bar(Runnable printBar) throws InterruptedException {
	        
	        for (int i = 0; i < n; i++) {
	            
	            synchronized(lock) {
	                if (fooTurn) lock.wait();
	                fooTurn = true;
	                // printBar.run() outputs "bar". Do not change or remove this line.
	        	    printBar.run();
	                lock.notifyAll();
	            }
	        }
	    }
	}
```

测试用例：
```java
public class Test{
public static void main(String[] args) {
	    	Print_n_FooBar p = new Print_n_FooBar(2);
	    		new Thread( ){
	    			public void run() {
	    			try {
						p.foo(new Print_Foo());
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
	    			}
	    		}.start();
	    		new Thread( ){
	    			public void run() {
	    			try {
						p.bar(new Print_Bar());
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
	    			}
	    		}.start();
		}
	}
}
	class Print_Bar implements Runnable{

		@Override
		public void run() {
			System.out.print("Bar");
		}
	}
	
	
	class FooBar {
	    private int n;
	    private boolean fooTurn = true;
	    private Object lock = new Object();
	    public FooBar(int n) {
	        this.n = n;
	    }

```
然后是只用一个Boolean来作为判断线程notify或者wait的标志（第一次拿错代码了，又改了）
```java
class FooBar {
     private int              n;
	    private volatile boolean isFoo;

	    public FooBar(int n) {
	        this.n = n;
	    }

	    public synchronized void foo(Runnable printFoo) throws InterruptedException {

	        for (int i = 0; i < n; i++) {
	            // printFoo.run() outputs "foo". Do not change or remove this line.
	            printFoo.run();
	            isFoo = true;
	            this.notify();
	            if (i < n - 1) {
	                this.wait();
	            }
	            //            }
	        }
	    }

	    public synchronized void bar(Runnable printBar) throws InterruptedException {
	        if (!isFoo) {
	            this.wait();
	        }
	        for (int i = 0; i < n; i++) {
	            //            synchronized (lock) {
	            // printBar.run() outputs "bar". Do not change or remove this line.
	            printBar.run();
	            this.notify();
	            if (i < n - 1) {
	                this.wait();
	            }
	            //            }
	        }
	    }
}
```
