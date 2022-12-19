`class FooBar {
private:
	int n;
	condition_variable cv;
	mutex mlock;
	bool flag;
public:
	FooBar(int n) {
		this->n = n;
        flag = 1;
	}

	void foo(function<void()> printFoo) {

		for (int i = 0; i < n; i++) {
			unique_lock<mutex> ulock(mlock);
			cv.wait(ulock, [this]() {return flag; });
			flag = !flag;
			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();
			cv.notify_all();
		}
	}

	void bar(function<void()> printBar) {

		for (int i = 0; i < n; i++) {
			unique_lock<mutex> ulock(mlock);
			cv.wait(ulock, [this]() {return !flag; });
			flag = !flag;
			// printFoo() outputs "foo". Do not change or remove this line.
			printBar();
			cv.notify_all();
			// printBar() outputs "bar". Do not change or remove this line.
		}
	}
};
`


