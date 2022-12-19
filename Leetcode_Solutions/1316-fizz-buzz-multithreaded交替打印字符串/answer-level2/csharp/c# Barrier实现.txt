```c#
using System.Threading;

public class FizzBuzz {
    private int n;

    public FizzBuzz(int n) {
        this.n = n;
    }
    
    // 四个线程 共有n个阶段
    private Barrier _barrier = new Barrier(4);

    // printFizz() outputs "fizz".
    public void Fizz(Action printFizz) {
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 != 0) {
                printFizz();
            }
            _barrier.SignalAndWait();
        }
    }

    // printBuzzz() outputs "buzz".
    public void Buzz(Action printBuzz) {
        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0 && i % 3 != 0) {
                printBuzz();
            }
            _barrier.SignalAndWait();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    public void Fizzbuzz(Action printFizzBuzz) {
        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0 && i % 3 == 0) {
                printFizzBuzz();
            }
            _barrier.SignalAndWait();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    public void Number(Action<int> printNumber) {
        for (int i = 1; i <= n; i++) {
            if (i % 3 != 0 && i % 5 != 0) {
                printNumber(i);
            }
            _barrier.SignalAndWait();
        }
    }
}
```
