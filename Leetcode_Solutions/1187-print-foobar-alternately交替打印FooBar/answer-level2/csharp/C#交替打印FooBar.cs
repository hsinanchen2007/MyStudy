### 解题思路
线程间通信

### 代码

```csharp
using System.Threading;
public class FooBar
    {
        private int n;
        private AutoResetEvent _fooAutoResetEvent = new AutoResetEvent(false);
        private AutoResetEvent _barAutoResetEvent = new AutoResetEvent(false);

        public FooBar(int n)
        {
            this.n = n;
        }

        public void Foo(Action printFoo)
        {
            _fooAutoResetEvent.Set();
            for (int i = 0; i < n; i++)
            {
                _fooAutoResetEvent.WaitOne();
                printFoo();
                _barAutoResetEvent.Set();
            }
        }

        public void Bar(Action printBar)
        {

            for (int i = 0; i < n; i++)
            {
                _barAutoResetEvent.WaitOne();
                printBar();
                _fooAutoResetEvent.Set();
            }
        }
    }
```