
```
//利用java的同步功能可以简单地完成。
class FooBar 
{
    private int n;
    private int flag=1;//控制执行顺序的标志

    public FooBar(int n) 
    {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException 
    {
        
        for (int i = 0; i < n; i++) 
        {
            synchronized (this) 
            {
                if(flag!=1)
                    this.wait();
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                flag=2;
                this.notify();				
            }			
        }
    }

    public void bar(Runnable printBar) throws InterruptedException 
    {
        
        for (int i = 0; i < n; i++) 
        {
            synchronized (this) 
            {
                if(flag!=2)
                    this.wait();
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                    flag=1;
                this.notify();				
            }			
        }
    }
}
```
