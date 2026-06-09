
class Foo {
    
    private int flag=1;//控制执行顺序的标志

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        synchronized (this) //线程同步关键词
		{
			while(flag!=1)
				this.wait();  //条件不满足就等待
        
        // printFirst.run() outputs "first". Do not change or remove this line.
            printFirst.run();
            
            flag=2;
			this.notifyAll();	//通知其他线程执行			
		}			
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized (this) 
		{
			while(flag!=2)
				this.wait();
        
        // printSecond.run() outputs "second". Do not change or remove this line.
            printSecond.run();
            flag=3;
			this.notifyAll();				
		}			
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized (this) 
		{
			while(flag!=3)
				this.wait();
        
        // printThird.run() outputs "third". Do not change or remove this line.
            printThird.run();
            flag=1;
			this.notifyAll();				
		}			
    }
}