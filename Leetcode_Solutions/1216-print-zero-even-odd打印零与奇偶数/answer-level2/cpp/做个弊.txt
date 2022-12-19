想不出来不想了！做个弊！！


```c++ []
class ZeroEvenOdd {
private:
    int n;
    function<void(int)> fnEven,fnOdd;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(!fnEven||!fnOdd);
        for(int i = 0; i < n; ++i)
        {
            printNumber(0);
            if((i&1)==0) fnOdd(i+1);
            else fnEven(i+1);
        }
    }

    void even(function<void(int)> printNumber) {
        fnEven = printNumber;
    }

    void odd(function<void(int)> printNumber) {
        fnOdd = printNumber;
    }
};
```

