```
class FizzBuzz {
private:
	int n;
	int i;
	mutex myLock;
	condition_variable cv;
	
public:
	FizzBuzz(int n)
	{
		this->n = n;
        i = 1;
	}

	// printFizz() outputs "fizz".
	void fizz(function<void()> printFizz)
	{
		unique_lock<mutex> lock(myLock);
		while(i <= n)
		{
			cv.wait(lock, [&]()->bool {
				return i % 3 == 0 && i % 5 != 0 || i > n;
			});
			if (i <= n)
				printFizz();
			i++;
			cv.notify_all();
		}
		cv.notify_all();
	}

	// printBuzz() outputs "buzz".
	void buzz(function<void()> printBuzz)
	{
		unique_lock<mutex> lock(myLock);
		while (i <= n)
		{
			cv.wait(lock, [&]()->bool {
				return i % 3 != 0 && i % 5 == 0 || i > n;
			});
			if (i <= n)
				printBuzz();
			i++;
			cv.notify_all();
		}
		cv.notify_all();
	}

	// printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz)
	{
		unique_lock<mutex> lock(myLock);
		while (i <= n)
		{
			cv.wait(lock, [&]()->bool {
				return i % 3 == 0 && i % 5 == 0 || i > n;
			});
			if (i <= n)
				printFizzBuzz();
			i++;
			cv.notify_all();
		}
		cv.notify_all();
	}

	// printNumber(x) outputs "x", where x is an integer.
	void number(function<void(int)> printNumber)
	{
		unique_lock<mutex> lock(myLock);
		while (i <= n)
		{
			cv.wait(lock, [&]()->bool {
				return i % 3 != 0 && i % 5 != 0 || i > n;
			});
			if (i <= n)
				printNumber(i);
			i++;
			cv.notify_all();
		}
		cv.notify_all();
	}
};
```
