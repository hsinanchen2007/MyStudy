只有两个线程之间的同步用AutoResetEvent或者ManualResetEvent很方便

```
using System.Threading;

public class FooBar {
    private int n;

    public FooBar(int n) {
        this.n = n;
    }
    
    private AutoResetEvent _fooEvent = new AutoResetEvent(false);
    private AutoResetEvent _barEvent = new AutoResetEvent(true);

    public void Foo(Action printFoo) {
        
        for (int i = 0; i < n; i++) {
            _barEvent.WaitOne();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            _fooEvent.Set();
        }
    }

    public void Bar(Action printBar) {
        
        for (int i = 0; i < n; i++) {
            _fooEvent.WaitOne();
            // printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            _barEvent.Set();
        }
    }
}
```
