### 解题思路
解法三: Semaphore
注意，要先初始化为0。然后先release到1，再acquire。

### 代码

```java
import java.util.concurrent.*;

class Foo {

	public Foo() {

	}

	Semaphore s1 = new Semaphore(0);
	Semaphore s2 = new Semaphore(0);

	public void first(Runnable printFirst) throws InterruptedException {
		printFirst.run();
		s1.release();
	}

	public void second(Runnable printSecond) throws InterruptedException {
		s1.acquire();
		printSecond.run();
		s2.release();
	}

	public void third(Runnable printThird) throws InterruptedException {
		s2.acquire();
		printThird.run();
	}
}
```