执行用时 :7 ms,在所有 Java 提交中击败了99.76%的用户,内存消耗 :35.9 MB,在所有 Java 提交中击败了100.00%的用户
```
class ZeroEvenOdd {
	private int n;
	private int num = 0;

	public ZeroEvenOdd(int n) {
		this.n = n;
	}

	// printNumber.accept(x) outputs "x", where x is an integer.
	public void zero(IntConsumer printNumber) throws InterruptedException {
		for (int i = 0; i < n; i++) {
			synchronized (this) {
				while (num % 2 != 0) {
					this.wait();
				}
				printNumber.accept(0);
				num++;
				this.notifyAll();
			}
		}

	}

	public void even(IntConsumer printNumber) throws InterruptedException {
		for (int j = 2; j <= n; j = j + 2) {
			synchronized (this) {
				while (num % 2 == 0 || num % 4 != 3) {
					this.wait();
				}
				printNumber.accept(j);
				num++;
				this.notifyAll();
			}
		}

	}

	public void odd(IntConsumer printNumber) throws InterruptedException {
		for (int j = 1; j <= n; j = j + 2) {
			synchronized (this) {
				while (num % 2 == 0 || num % 4 != 1) {
					this.wait();
				}
				printNumber.accept(j);
				num++;
				this.notifyAll();
			}
		}
	}
}
```
测试主函数如下:(注:只支持10以内)
```
public static void main(String[] args) {
		try {
			char integer = (char) System.in.read();
			System.out.println("传入n: " + integer);
			int input = (char) integer - (char) '0';
			ZeroEvenOdd zeroEvenOdd = new ZeroEvenOdd(input);
			IntConsumer intConsumer = value -> System.out.println(value);
			new Thread(new Runnable() {
				@Override
				public void run() {
					try {
						zeroEvenOdd.zero(intConsumer);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}).start();
			new Thread(new Runnable() {
				@Override
				public void run() {
					try {
						zeroEvenOdd.odd(intConsumer);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}).start();
			new Thread(new Runnable() {
				@Override
				public void run() {
					try {
						zeroEvenOdd.even(intConsumer);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}).start();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
```
其实也可以延续上题思路,继续使用条件变量控制锁
```
class ZeroEvenOdd {
	private int n;
	private boolean ifZeroDone = false;
	private boolean ifEvenOddDone = false;
	public ZeroEvenOdd(int n) {
		this.n = n;
	}

	// printNumber.accept(x) outputs "x", where x is an integer.
	public void zero(IntConsumer printNumber) throws InterruptedException {
		for (int i = 0; i < n; i++) {
			synchronized (this) {
				while (ifZeroDone) {
					this.wait();
				}
				printNumber.accept(0);
				ifZeroDone = true;
				this.notifyAll();
			}
		}

	}

	public void even(IntConsumer printNumber) throws InterruptedException {
		for (int j = 2; j <= n; j = j + 2) {
			synchronized (this) {
				while (!ifZeroDone || !ifEvenOddDone) {
					this.wait();
				}
				printNumber.accept(j);
				ifZeroDone = false;
				ifEvenOddDone = false;
				this.notifyAll();
			}
		}

	}

	public void odd(IntConsumer printNumber) throws InterruptedException {
		for (int j = 1; j <= n; j = j + 2) {
			synchronized (this) {
				while (!ifZeroDone || ifEvenOddDone) {
					this.wait();
				}
				printNumber.accept(j);
				ifZeroDone = false;
				ifEvenOddDone = true;
				this.notifyAll();
			}
		}
	}

}
```
