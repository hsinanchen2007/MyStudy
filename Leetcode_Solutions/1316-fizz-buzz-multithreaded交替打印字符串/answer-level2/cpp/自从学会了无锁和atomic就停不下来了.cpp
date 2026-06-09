```
class FizzBuzz {
private:
    enum class Status {
        NUM, FIZZ, BUZZ, FIZZBUZZ
    };
    int n;
    int idx;
    atomic<Status> s;
    Status getNext(int i)
    {
        ++i;
        if (i % 3 == 0 && i % 15 != 0)
            return Status::FIZZ;
        else if (i % 5 == 0 && i % 15 != 0)
            return Status::BUZZ;
        else if (i % 15 == 0)
            return Status::FIZZBUZZ;
        else
            return Status::NUM;
    }
public:
    FizzBuzz(int n) {
        this->n = n;
        idx = 1;
        s.store(Status::NUM, memory_order_relaxed);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (idx <= n)
        {
            if (Status::FIZZ == s.load(memory_order_relaxed))
            {
                printFizz();
                s.store(getNext(idx++), memory_order_relaxed);
            }
            this_thread::yield();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (idx <= n)
        {
            if (Status::BUZZ == s.load(memory_order_relaxed))
            {
                printBuzz();
                s.store(getNext(idx++), memory_order_relaxed);
            }
            this_thread::yield();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (idx <= n)
        {
            if (Status::FIZZBUZZ == s.load(memory_order_relaxed))
            {
                printFizzBuzz();
                s.store(getNext(idx++), memory_order_relaxed);
            }
            this_thread::yield();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (idx <= n)
        {
            if (Status::NUM == s.load(memory_order_relaxed))
            {
                printNumber(idx);
                s.store(getNext(idx++), memory_order_relaxed);
            }
            this_thread::yield();
        }
    }
};
```
