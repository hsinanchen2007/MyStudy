### 解题思路
此处撰写解题思路

### 代码

```java
class DiningPhilosophers {
	Semaphore [] sList;

    public DiningPhilosophers() {
    	sList=new Semaphore[5];
    	for(int i=0;i<5;i++) {
    		sList[i]=new Semaphore(1);
    	}
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        if(philosopher%2==0) {
            sList[philosopher].acquire();
            sList[(philosopher+1)%5].acquire();
            pickLeftFork.run();
            pickRightFork.run();
        } 
        else {
            sList[(philosopher+1)%5].acquire();
            sList[philosopher].acquire();
            pickRightFork.run();
            pickLeftFork.run();
        }
        eat.run();
        if(philosopher%2==0) {
            putLeftFork.run();
            putRightFork.run();
            sList[philosopher].release();
            sList[(philosopher+1)%5].release();
        } 
        else {
            putRightFork.run();
            putLeftFork.run();
            sList[(philosopher+1)%5].release();
            sList[philosopher].release();
        }
    }
}
```