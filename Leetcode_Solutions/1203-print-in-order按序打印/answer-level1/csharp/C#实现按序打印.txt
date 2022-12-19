### 解题思路
这是一个典型的线程间通信的。第一种使用AutoResetEvent实现，第二种方式通过自旋锁实现。

### 代码

```csharp
using System.Threading;
public class Foo
    {
        /*
         * 第一种方式
        private AutoResetEvent _second = new AutoResetEvent(false);
        private AutoResetEvent _three = new AutoResetEvent(false);
        

        public Foo()
        {

        }

        public void First(Action printFirst)
        {
            printFirst();
            _second.Set();//通知第二个可以执行了
        }

        public void Second(Action printSecond)
        {
            _second.WaitOne();//等待通知
            printSecond();
            _three.Set();//通知第三个可以执行了

        }

        public void Third(Action printThird)
        {
            _three.WaitOne();//等待通知
            printThird();
        }
        */
        //第二种方式，使用自旋锁
        private SpinWait _spinWait = new SpinWait();
        private int _continueCondition = 1;
        
        public Foo()
        {

        }
        public void First(Action printFirst)
        {
            printFirst();
            Thread.VolatileWrite(ref _continueCondition,2);//写栅栏
        }

        public void Second(Action printSecond)
        {
            
            while (Thread.VolatileRead(ref _continueCondition)!=2)
            {
                _spinWait.SpinOnce();
            }
            printSecond();
            Thread.VolatileWrite(ref _continueCondition, 3);//写栅栏
        }

        public void Third(Action printThird)
        {
            while (Thread.VolatileRead(ref _continueCondition) != 3)
            {
                _spinWait.SpinOnce();
            }
            printThird();
            Thread.VolatileWrite(ref _continueCondition, 1);//写栅栏
        }
    }
```