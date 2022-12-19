### 解题思路
此处撰写解题思路

### 代码

```csharp
public class FizzBuzz {
    private int n;

    public FizzBuzz(int n) {
        this.n = n;
    }

     // printFizz() outputs "fizz".
        public void Fizz(Action printFizz)
        {
            
            for (var i = 1; i <= n; i++)
            {

                while (!CheckRun(1))
                {
                    System.Threading.Thread.Sleep(10);
                }

                if (i % 3 == 0 && i % 5 != 0)
                    printFizz();
                

            }
        }

        // printBuzzz() outputs "buzz".
        public void Buzz(Action printBuzz)
        {
            for (var i = 1; i <= n; i++)
            {
                while (!CheckRun(2))
                {
                    System.Threading.Thread.Sleep(10);
                }
                if (i % 5 == 0 && i % 3 != 0)
                    printBuzz();
                
            }
        }

        // printFizzBuzz() outputs "fizzbuzz".
        public void Fizzbuzz(Action printFizzBuzz)
        {
            for (var i = 1; i <= n; i++)
            {
                while (!CheckRun(3))
                {
                    System.Threading.Thread.Sleep(10);
                }
                if (i % 5 == 0 && i % 3 == 0)
                    printFizzBuzz();
                
            }
        }

        // printNumber(x) outputs "x", where x is an integer.
        public void Number(Action<int> printNumber)
        {
            for (var i = 1; i <= n; i++)
            {
                while (!CheckRun(4))
                {
                    System.Threading.Thread.Sleep(10);
                }
                if (i % 5 != 0 && i % 3 != 0)
                    printNumber(i);
                
            }
        }

        private static  List<int> runThread=new List<int>();
        private readonly object _lckObj=new object();

        private bool CheckRun(int threadId)
        {
            if (runThread.Contains(threadId) )
                return false;
            lock (_lckObj)
            {
                runThread.Add(threadId);
                if (runThread.Count == 4)
                {
                    runThread = new List<int>();
                }
                return true;
            }
        }
}
```