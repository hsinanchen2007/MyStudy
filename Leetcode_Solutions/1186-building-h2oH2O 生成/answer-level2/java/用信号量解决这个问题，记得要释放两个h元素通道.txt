### 解题思路
此处撰写解题思路

### 代码

```java
class H2O {

	//屏障
   public CyclicBarrier barriar = new CyclicBarrier(3, new Runnable() {
	@Override
	public void run() {
		// TODO Auto-generated method stub
	//	System.out.println("当产生完一个水分子释放");
		oSemaphore.release();
		//要释放两个H元素通道
		hSemaphore.release(2);
		
	}
});
   public Semaphore oSemaphore;
   public Semaphore hSemaphore;
   public Object object = new Object();
    public H2O() {
    	oSemaphore = new Semaphore(1);
    	hSemaphore = new Semaphore(2);
    }

    public  void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
    	hSemaphore.acquire();
	  try {
          //  System.out.println("产生一个H");
            releaseHydrogen.run() ;
		//  System.out.println("H等待氧气线程产生氧气");
		  //设置屏障
		barriar.await();
	} catch (BrokenBarrierException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	} finally {
		//System.out.println("最终执行了h");
	}
    }

    public  void oxygen(Runnable releaseOxygen) throws InterruptedException {
    	oSemaphore.acquire();
        
		  try {
			 // System.out.println("产生一个O");
			  releaseOxygen.run();
			//  System.out.println("O等待氧气线程产生氧气");
				barriar.await();
			} catch (BrokenBarrierException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}finally {
				
				//barriar.reset();
			}
        
    }
}
```