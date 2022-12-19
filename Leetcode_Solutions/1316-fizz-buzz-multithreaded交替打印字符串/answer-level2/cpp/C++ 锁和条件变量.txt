
法1：使用锁 
```
class FizzBuzz {
private:
	int n;
	atomic<int> i;//x效率提高了一点点
	mutex m;
public:
	FizzBuzz(int n) {
		this->n = n;
		this->i = 1;
	}

	// printFizz() outputs "fizz".
	void fizz(function<void()> printFizz) {
		while (i <= n)
		{
			std::lock_guard<std::mutex> lk(m);
			if (i % 3 == 0 && i % 15 != 0 && i <= n) {
				printFizz();
				i++;
			}
		}
	}

	// printBuzz() outputs "buzz".
	void buzz(function<void()> printBuzz) {
		while (i <= n)
		{
			std::lock_guard<std::mutex> lk(m);
			if (i % 5 == 0 && i % 15 != 0 && i <= n) {
				printBuzz();
				i++;
			}
		}
	}

	// printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
		while (i <= n)
		{
			std::lock_guard<std::mutex> lk(m);
			if (i % 15 == 0 && i <= n) { //i<=n 不能省略
				printFizzBuzz();
				i++;
			}
		}
	}

	// printNumber(x) outputs "x", where x is an integer.
	void number(function<void(int)> printNumber) {
		while (i <= n)
		{
			std::lock_guard<std::mutex> lk(m);
			if (i % 3 != 0 && i % 5 != 0&&i<=n) {
				printNumber(i);
				i++;
			}
		}
	}
};```

class FizzBuzz {
private:
	int n;
	atomic<int> i;//x效率提高了一点点
	mutex m;
public:
	FizzBuzz(int n) {
		this->n = n;
		this->i = 1;
	}

	// printFizz() outputs "fizz".
	void fizz(function<void()> printFizz) {
		while (i <= n)
		{
			std::lock_guard<std::mutex> lk(m);
			if (i % 3 == 0 && i % 15 != 0 && i <= n) {
				printFizz();
				i++;
			}
		}
	}

	// printBuzz() outputs "buzz".
	void buzz(function<void()> printBuzz) {
		while (i <= n)
		{
			std::lock_guard<std::mutex> lk(m);
			if (i % 5 == 0 && i % 15 != 0 && i <= n) {
				printBuzz();
				i++;
			}
		}
	}

	// printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
		while (i <= n)
		{
			std::lock_guard<std::mutex> lk(m);
			if (i % 15 == 0 && i <= n) {
				printFizzBuzz();
				i++;
			}
		}
	}

	// printNumber(x) outputs "x", where x is an integer.
	void number(function<void(int)> printNumber) {
		while (i <= n)
		{
			std::lock_guard<std::mutex> lk(m);
			if (i % 3 != 0 && i % 5 != 0&&i<=n) {
				printNumber(i);
				i++;
			}
		}
	}
};
```
法2：使用条件变量
```
//wait里的条件要增加i>n的退出条件，否则，至少有两个线程无法正常退出了，一直在wait那里阻塞着呢，到不了while那里

class FizzBuzz {
private:
	int n;
	condition_variable cv;
	mutex m;
	atomic<int> i;
public:
	FizzBuzz(int n) {
		this->n = n;
		this->i = 1;
	}

	// printFizz() outputs "fizz".
	void fizz(function<void()> printFizz) {
		while (i <= n)
		{
			std::unique_lock<std::mutex> lk(m);
			cv.wait(lk, [this] {return (i > n || i % 3 == 0 && i % 15 != 0); });
			if (i > n)break;
			printFizz();
			i++;
			lk.unlock();
			cv.notify_all();
		}
	}

	// printBuzz() outputs "buzz".
	void buzz(function<void()> printBuzz) {
		while (i <= n)
		{
			std::unique_lock<std::mutex> lk(m);
			cv.wait(lk, [this] {return (i > n || i % 5 == 0 && i % 15 != 0); });
			if (i > n)break;
			printBuzz();
			i++;
			lk.unlock();
			cv.notify_all();
		}
	}

	// printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
		while (i <= n)
		{
			std::unique_lock<std::mutex> lk(m);
			cv.wait(lk, [this] {return (i > n || i % 15 == 0); });
			if (i > n)break;
			printFizzBuzz();
			i++;
			lk.unlock();
			cv.notify_all();
		}
	}

	// printNumber(x) outputs "x", where x is an integer.
	void number(function<void(int)> printNumber) {
		while (i <= n)
		{
			std::unique_lock<std::mutex> lk(m);
 			cv.wait(lk, [this] {return (i > n||i % 3 != 0 && i % 5 != 0); });
			if (i > n)break;
			printNumber(i);
			i++;
			lk.unlock();
			cv.notify_all();
		}
	}
};
```
