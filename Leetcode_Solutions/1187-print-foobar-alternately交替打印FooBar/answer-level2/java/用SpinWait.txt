### 解题思路 
运气成分，占多数

### 代码

```csharp
using System.Threading;
public class FooBar {
    private int n;
    private bool next;
    public FooBar(int n) {
        this.n = n;
    }

    public void Foo(Action printFoo) {
        for (int i = 0; i < n; i++) {            
            SpinWait.SpinUntil(() => !next);
            next=true;
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
        }
    }

    public void Bar(Action printBar) {
        for (int i = 0; i < n; i++) {
            SpinWait.SpinUntil(() => next);
            next=false;
            // printBar() outputs "bar". Do not change or remove this line.
        	printBar();
        }
    }
}
```