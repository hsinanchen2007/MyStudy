#  AutoResetEvent _z=new AutoResetEvent(true);同理
```
using System.Threading;

public class ZeroEvenOdd
        {
            private int n;

            private volatile int iVolatile = 0;
            private Semaphore _z = new Semaphore(1, 1);
            private Semaphore _e = new Semaphore(0, 1);
            private Semaphore _o = new Semaphore(0, 1);

            public ZeroEvenOdd(int n)
            {
                this.n = n;
            }

            // printNumber(x) outputs "x", where x is an integer.
            public void Zero(Action<int> printNumber)
            {
                while (iVolatile < 2 * n - 1)
                {
                    _z.WaitOne();
                    printNumber(0);
                    iVolatile++;
                    if (iVolatile % 2 != 0)
                    {
                        if ((iVolatile / 2) % 2 == 0)
                        {
                            _o.Release();
                        }
                        else if ((iVolatile / 2) % 2 == 1)
                        {
                            _e.Release();
                        }
                    }
                    else
                    {
                        _z.Release();
                    }
                }
            }

            public void Even(Action<int> printNumber)
            {
                while (iVolatile < 2 * n - 1)
                {
                    _e.WaitOne();
                    printNumber((iVolatile + 1) / 2);
                    iVolatile++;
                    _z.Release();
                }
            }

            public void Odd(Action<int> printNumber)
            {
                while (iVolatile < 2 * n - 1)
                {
                    _o.WaitOne();
                    printNumber((iVolatile + 1) / 2);
                    iVolatile++;
                    _z.Release();
                }
            }
        }
```
