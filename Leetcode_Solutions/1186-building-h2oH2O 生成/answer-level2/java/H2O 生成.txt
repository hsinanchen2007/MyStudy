```
class H2O {
    /**
    *解题思路
    *用信号量确保每次只有2个H线程或1个O线程进入
    *用synchronized确保为互斥操作
    */
    private static java.util.concurrent.Semaphore semiH,semiO;
	private static int numH,numO;
    
    public H2O() 
    {
        semiH = new java.util.concurrent.Semaphore(2); // H线程信号量
        semiO = new java.util.concurrent.Semaphore(1); // O线程信号量      
        numH=0;
        numO=0;
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        semiH.acquire(); // 保证只有2个H线程进入执行       
        
       synchronized (H2O.class)
        {
           releaseHydrogen.run();
        	numH++;
        	if(numH==2 && numO==1)
        	{
        		numH=0;
                numO=0;
                semiO.release();
                semiH.release(2);
        	}	
        }
  
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        semiO.acquire();
        
        synchronized (H2O.class)
        {
           releaseOxygen.run(); 
            numO++;
        	if(numH==2)
        	{
        		numH=0;
                numO=0;
                semiO.release();
                semiH.release(2);
        	}		
        }
          
    }
}
```
