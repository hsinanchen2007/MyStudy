package leedcode;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * 描述:
 * 按序打印
 *
 * @author qia.wu
 * @create 2019-10-10 11:05
 * @see leedcode
 */
public class Test1114 {
	public static void main(String[] args) {
		Foo foo = new Foo();

		Thread t1 = new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					foo.first(new Runnable() {
						@Override
						public void run() {
							System.out.println("first");
						}
					});
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});
		Thread t2 = new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					foo.second(new Runnable() {
						@Override
						public void run() {
							System.out.println("second");
						}
					});
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});
		Thread t3 = new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					foo.third(new Runnable() {
						@Override
						public void run() {
							System.out.println("third");
						}
					});
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});
		t1.start();
		t3.start();
		t2.start();

	}

	public static class Foo {

		private AtomicInteger count = new AtomicInteger(3);

		private byte[] lock = new byte[0];

		public Foo() {

		}

		public void first(Runnable printFirst) throws InterruptedException {
			synchronized (lock){
				while (true) {
					if(count.get() == 3) {
						printFirst.run();
						count.set(2);
						lock.notifyAll();
						break;
					} else {
						lock.wait();
					}
				}

			}
			// printFirst.run() outputs "first". Do not change or remove this line.

		}

		public void second(Runnable printSecond) throws InterruptedException {
			synchronized (lock){
				while (true) {
					if(count.get() == 2) {
						// printSecond.run() outputs "second". Do not change or remove this line.
						printSecond.run();
						count.set(1);
						lock.notifyAll();
						break;
					} else {
						lock.wait();
					}
				}
			}
		}

		public void third(Runnable printThird) throws InterruptedException {
			synchronized (lock){
				while (true) {
					if(count.get() == 1) {
						// printThird.run() outputs "third". Do not change or remove this line.
						printThird.run();
						lock.notifyAll();
						break;
					} else {
						lock.wait();
					}
				}
			}

		}

	}


	public static class Foo1 {
		private CountDownLatch countDownLatchA;
		private CountDownLatch countDownLatchB;

		public Foo1() {
			countDownLatchA = new CountDownLatch(1);
			countDownLatchB = new CountDownLatch(1);
		}

		public void first(Runnable printFirst) throws InterruptedException {
			// printFirst.run() outputs "first". Do not change or remove this line.
			printFirst.run();
			countDownLatchA.countDown();
		}

		public void second(Runnable printSecond) throws InterruptedException {
			// printSecond.run() outputs "second". Do not change or remove this line.
			countDownLatchA.await();
			printSecond.run();
			countDownLatchB.countDown();
		}

		public void third(Runnable printThird) throws InterruptedException {
			// printThird.run() outputs "third". Do not change or remove this line.
			countDownLatchB.await();
			printThird.run();
		}
	}
}
