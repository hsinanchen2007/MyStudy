一、分析题意：
  1、（问题一）首先是两条线程异步调用，两条线程不能确定他们谁先谁有，也就是有序性
  2、（问题二）在线程执行的时候需要保证foo每次循环都在bar前，这样的话肯定是需要线程不能往下执行。
  3、 解决以上两个问题基本就解决了，所以联想到以下两个关键字解决，volatile 可见性且有序，yield()让线程暂停。
二、首先解释两个用到的关键字 volatile yield();
     yield ：暂停当前正在执行的线程对象，yield()只是使当前线程重新回到可执行状态，所以执行yield()的线程有可能在进入到可执              行状态后马上又被执行。
   volatile：保证了不同线程对这个变量进行操作时的可见性，即一个线程修改了某个变量的值，这新值对其他线程来说是立即可见的。              （实现可见性）
             禁止进行指令重排序。（实现有序性）
             volatile 只能保证对单次读/写的原子性。i++ 这种操作不能保证原子性。
三、解题过程
            循环执行两次，首先确认目前的flag的状态以确保一定是foo执行（为了解决问题一，关键词volatile），来判断是否往下执             行，如果不是那么让当前不往下执行（关键词yield()）
            优化：可以在 yield() 时增限制，避免无限的循环。
# 代码

```
class FooBar {
    
    private int n;
    private volatile int flag = 0;
	public FooBar(int n) {
		this.n = n;
	}

	public void foo(Runnable printFoo) throws InterruptedException {
         for (int i = 0; i < n; i++) {
			while(flag != 0){
				Thread.yield();
			}
			printFoo.run();
			flag = 1;
		}
	}

	public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
			while(flag != 1){
				Thread.yield();
			}
			printBar.run();
			flag = 0;
		}
	}
    
}
```

