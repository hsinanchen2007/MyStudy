还是使用condition_variable，注意要让所有的线程在执行完之后顺利推出。否则会时间超限。

```
class FizzBuzz {
private:
    int n;
    int num;
    condition_variable cv;
    mutex m;
public:
    FizzBuzz(int n) {
        this->n = n;
        num = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lk(m);
        for ( ; num <= n ; )
        {
            if (num % 3 == 0 && num % 5 != 0)
            {
                printFizz();
                ++num;
                cv.notify_all();
            }
            cv.wait(lk, [this] {return (num > n) || num % 3 == 0 && num % 5 != 0; });
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lk(m);
        for (; num <= n;)
        {
            if (num % 5 == 0 && num % 3 != 0)
            {
                printBuzz();
                ++num;
                cv.notify_all();
            }
            cv.wait(lk, [this] {return (num > n) || num % 5 == 0 && num % 3 != 0; });
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lk(m);
        for (; num <= n;)
        {
            if (num % 3 == 0 && num % 5 == 0)
            {
                printFizzBuzz();
                ++num;
                cv.notify_all();
            }
            cv.wait(lk, [this] {return (num > n) || num % 3 == 0 && num % 5 == 0; });
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lk(m);
        for (; num <= n;)
        {
            if (num % 3 != 0 && num % 5 != 0)
            {
                printNumber(num);
                ++num;
                if (num > n)
                {
                    cv.notify_all();
                    break;
                }
                if (num % 3 != 0 && num % 5 != 0)
                {
                    continue;
                }
                else
                {
                    cv.notify_all();
                }
            }
            cv.wait(lk, [this] {return (num > n) || num % 3 != 0 && num % 5 != 0; });
        }
    }
};
```

附上测试用主函数

```
int main(int argc, void** argv)
{
    FizzBuzz fz(1);

    function<void()> fizz = []() {
        cout << "fizz" << endl;
    };

    function<void()> buzz = []() {
        cout << "buzz" << endl;
    };

    function<void()> fizzbuzz = []() {
        cout << "fizzbuzz" << endl;
    };

    function<void(int)> num = [](int n) {
        cout << n << endl;
    };

    thread th1([&]() {
        fz.fizz(fizz);
    });
    thread th2([&]() {
        fz.buzz(buzz);
    });
    thread th3([&]() {
        fz.fizzbuzz(fizzbuzz);
    });
    thread th4([&]() {
        fz.number(num);
    });
    th1.join();
    th2.join();
    th3.join();
    th4.join();

    return 0;
}
```

