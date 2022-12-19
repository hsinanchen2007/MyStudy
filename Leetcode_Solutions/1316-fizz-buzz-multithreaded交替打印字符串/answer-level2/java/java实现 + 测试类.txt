# **JAVA代码块**
```
class FizzBuzz {
	private int n;
	private volatile int m = 1; //累加器

	public FizzBuzz(int n) {
		this.n = n;
	}

	// printFizz.run() outputs "fizz".
	public void fizz(Runnable printFizz) throws InterruptedException {
		for (int i = 3; i <= n; i += 3) {// 只循环 3 的倍数
			synchronized (this) {
				if (i % 5 == 0) {//能被 5 整除的放出
					notifyAll();
					continue;
				}
				while (i != m) {//为了打印顺序不乱, m 累加器就是顺序,不相等的都暂停
					wait();
				}
				printFizz.run();//执行打印
				m++;
				notifyAll();//全体狂欢
			}
		}
	}

	// printBuzz.run() outputs "buzz".
	public void buzz(Runnable printBuzz) throws InterruptedException {
		for (int i = 5; i <= n; i += 5) {// 只循环 5 的倍数
			synchronized (this) {
				if (i % 3 == 0) {//能被 3 整除的放出
					notifyAll();
					continue;
				}
				while (i != m) {//为了打印顺序不乱, m 累加器就是顺序,不相等的都暂停
					wait();
				}
				printBuzz.run();//执行打印
				m++;
				notifyAll();//全体狂欢
			}
		}
	}

	// printFizzBuzz.run() outputs "fizzbuzz".
	public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
		for (int i = 15; i <= n; i += 15) {// 只循环 15 的倍数
			synchronized (this) {
				while (i != m) {//为了打印顺序不乱, m 累加器就是顺序,不相等的都暂停
					wait();
				}
				printFizzBuzz.run();//执行打印
				m++;
				notifyAll();//全体狂欢
			}
		}
	}

	// printNumber.accept(x) outputs "x", where x is an integer.
	public void number(IntConsumer printNumber) throws InterruptedException {
		for (int i = 1; i <= n; i++) {
			synchronized (this) {
				if (i % 3 == 0 || i % 5 == 0) {//能被 3 和 5 整除的放出
					notifyAll();
					continue;
				}
				while (i != m) {//为了打印顺序不乱, m 累加器就是顺序,不相等的都暂停
					wait();
				}
				printNumber.accept(m);//执行打印
				m++;
 				notifyAll();//全体狂欢
			}
		}
	}
}

```


# **附上测试类**
```
// 7 个Runnable, 1个IntConsumer, 4个线程, 1个普通实例
public class D1195_交替打印字符串 {
	public static void main(String[] args) {
		FizzBuzz fizzBuzz = new FizzBuzz(16);
		Runnable rFizz = () -> System.out.println("fizz");
		Runnable rBuzz = () -> System.out.println("buzz");
		Runnable rFizzBuzz = () -> System.out.println("fizzbuzz");
		IntConsumer pNumber = x -> System.out.println(x);

		Runnable rFBFizz = () -> {
			try {
				fizzBuzz.fizz(rFizz);
			} catch (InterruptedException e1) {
				e1.printStackTrace();
			}
		};
		Runnable rFBBuzz = () -> {
			try {
				fizzBuzz.buzz(rBuzz);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		};
		Runnable rFBFizzBuzz = () -> {
			try {
				fizzBuzz.fizzbuzz(rFizzBuzz);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		};
		Runnable rNumber = () -> {
			try {
				fizzBuzz.number(pNumber);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		};
		Thread t1 = new Thread(rFBFizz);
		Thread t2 = new Thread(rFBBuzz);
		Thread t3 = new Thread(rFBFizzBuzz);
		Thread t4 = new Thread(rNumber);
		t4.start();
		t1.start();
		t2.start();
		t3.start();

	}

}
```
