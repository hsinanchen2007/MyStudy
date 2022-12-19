### 解题思路
解法一：用notify和wait
注意，要另外用两个bool变量来判断在我wait前我等的那个是不是已经结束了。一旦结束了我就直接print，不然我就wait
这两个bool变量可以不需要volatile。因为default是false。

### 代码

```java
class Foo {

	public Foo() {

	}
    boolean firstFinished = false;
    boolean secondFinished = false;

	Object firstlock = new Object();
	Object secondlock = new Object();

	public void first(Runnable printFirst) throws InterruptedException {
		synchronized (firstlock) {
			// printFirst.run() outputs "first". Do not change or remove this line.
			printFirst.run();
			firstlock.notify();
            firstFinished = true; 
		}

	}

	public void second(Runnable printSecond) throws InterruptedException {
		synchronized (firstlock) {
            while(firstFinished == false){
               firstlock.wait(); 
            }
			synchronized (secondlock) {
				// printSecond.run() outputs "second". Do not change or remove this line.
				printSecond.run();
				secondlock.notify();
                secondFinished = true;
			}
		}

	}

	public void third(Runnable printThird) throws InterruptedException {
		synchronized (secondlock) {
            while(secondFinished == false){
                secondlock.wait();
            }
			// printThird.run() outputs "third". Do not change or remove this line.
			printThird.run();
		}
	}
}
```