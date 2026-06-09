```核心思想是如何避免死锁
复习死锁的条件:
1. 互斥条件<这里是叉子>
2. 一个任务持有另一个任务需要的资源，这个两个叉子才能吃饭
3. 资源不能抢占，必须等待释放，哲学家不会强叉子
4. 必须有循环等待，这里是可以设计的，所有事核心

只要破坏这4个条件种的一个，死锁就不会发生，所以选择破坏第4个，在第4个哲学家拿叉子的时候，不依次循环，其他都是从左边开始拿叉子，从左边开始放叉子，而第4人选择从右边开始拿叉子，从右边放，这样就不存在循环等待，死锁也就能够避免。
public class DiningPhilosophers {

    private Semaphore zeroHalf = new Semaphore(1);
    private Semaphore oneHalf = new Semaphore(1);
    private Semaphore twoHalf = new Semaphore(1);
    private Semaphore threeHalf = new Semaphore(1);
    private Semaphore fourHalf = new Semaphore(1);

    public DiningPhilosophers() {

    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        if(philosopher == 0){
            fourHalf.acquire();
            pickLeftFork.run();
        }else if(philosopher == 1){
            zeroHalf.acquire();
            pickLeftFork.run();
        }else if(philosopher == 2){
            oneHalf.acquire();
            pickLeftFork.run();
        }else if(philosopher == 3){
            twoHalf.acquire();
            pickLeftFork.run();
        }else if(philosopher == 4){
            fourHalf.acquire();
            pickRightFork.run();
        }else {
            throw new RuntimeException(philosopher+"");
        }


        if(philosopher == 0) {
            zeroHalf.acquire();
            pickRightFork.run();
        }else if(philosopher == 1){
            oneHalf.acquire();
            pickRightFork.run();
        }else if(philosopher == 2){
            twoHalf.acquire();
            pickRightFork.run();
        }else if(philosopher == 3){
            threeHalf.acquire();
            pickRightFork.run();
        }else {
            threeHalf.acquire();
            pickLeftFork.run();
        }
        eat.run();
        if(philosopher == 0){
            putLeftFork.run();
            fourHalf.release();
        }else if(philosopher == 1){
            putLeftFork.run();
            zeroHalf.release();
        }else if(philosopher == 2){
            putLeftFork.run();
            oneHalf.release();
        }else if(philosopher == 3){
            putLeftFork.run();
            twoHalf.release();
        }else {
            putRightFork.run();
            fourHalf.release();
        }
        if(philosopher == 0) {
            putRightFork.run();
            zeroHalf.release();
        }else if(philosopher == 1){
            putRightFork.run();
            oneHalf.release();
        }else if(philosopher == 2){
            putRightFork.run();
            twoHalf.release();
        }else if(philosopher == 3){
            putRightFork.run();
            threeHalf.release();
        }
        else {
            putLeftFork.run();
            threeHalf.release();
        }

    }
}

```
