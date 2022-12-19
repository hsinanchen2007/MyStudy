 public class FizzBuzz
    {
        private int n;
        private Semaphore FB1 = new Semaphore(1, 1);
        private Semaphore FB2 = new Semaphore(1, 1);
        private Semaphore FB3 = new Semaphore(1, 1);
        private Semaphore F = new Semaphore(0, 1);
        private Semaphore B = new Semaphore(0, 1);
        private Semaphore NUM = new Semaphore(0, 1);
    
        public FizzBuzz(int n)
        {
            this.n = n;
        }

        // printFizz() outputs "fizz".
        public void Fizz(Action printFizz)
        {
            for (int i = 1; i <= n; i++)
            {
                F.WaitOne();
                if (i % 3 == 0 && i % 5 != 0)
                {
                    //Console.WriteLine(i);
                    printFizz();
                 
                }
                lock (this)
                {

                    FB1.Release();
                }
            }

        }

        // printBuzzz() outputs "buzz".
        public void Buzz(Action printBuzz)
        {

            for (int i = 1; i <= n; i++)
            {
                B.WaitOne();
                if (i % 3 != 0 && i % 5 == 0)
                {
                    // Console.WriteLine(i);
                    printBuzz();
                  
                }
                lock (this)
                {

                    FB2.Release();
                }
            }
        }

        // printFizzBuzz() outputs "fizzbuzz".
        public void Fizzbuzz(Action printFizzBuzz)
        {

            for (int i = 1; i <= n; i++)
            {
                FB1.WaitOne();
                FB2.WaitOne();
                FB3.WaitOne();

                if (i % 3 == 0 && i % 5 == 0)
                {
                    // Console.WriteLine(i);
                    printFizzBuzz();
                }
                lock (this)
                {
                
                        F.Release();
                        B.Release();
                        NUM.Release();
                    
                }
            }

        }

        // printNumber(x) outputs "x", where x is an integer.
        public void Number(Action<int> printNumber)
        {

            for (int i = 1; i <= n; i++)
            {
                if (i == 18)
                {
                    Console.WriteLine(18);
                }
                NUM.WaitOne();
                if (i % 3 != 0 && i % 5 != 0)
                {

                    printNumber(i);
                    //  Console.WriteLine(i);
               
                }
                lock (this)
                {

                    FB3.Release();
                }

            }
        }
    }

本地可跑 提交出错。写的很差仅供参考