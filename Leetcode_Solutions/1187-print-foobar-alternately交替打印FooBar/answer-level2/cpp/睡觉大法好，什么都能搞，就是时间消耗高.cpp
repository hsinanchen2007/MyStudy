class FooBar {
private:
    int n;
    int m;  
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        chrono::microseconds dura(1);
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            m = 0;           
			while (m != 1){				
				this_thread::sleep_for(dura);
                if ((i+1) == n)break;
			}
        }
    }

    void bar(function<void()> printBar) {
        chrono::microseconds dura(1);
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            m = 1;			
			while (m != 0){
				this_thread::sleep_for(dura);
                 if ((i+1) == n)break;     
			}
        }
    }
};

在类中设置m作为标志位，当m为1时打印foo，为0时打印bar。打印完foo后，把m置1，然后等待m置0；当m等于1时，打印bar，否则一直sleep。缺点在于，有可能bar线程先执行，从而引发错误。但是我在测试的时候没有遇到这种情况。