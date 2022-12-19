### 解题思路
我一开始的思路是一个人一个人轮流吃，但是感觉这样就浪费了叉子，而且违背了多线程的初衷。既然是多线程，有5个叉子，就说明可以同时有两个人吃东西。
每个人都可以尝试去吃东西，吃东西前尝试去拿左边的叉子和右边的叉子，这样就可以想到使用信号量Semaphore的tryAcquire方法。
这里竞争的资源是叉子，所以定义代表5个叉子的信号量即可。


### 代码

```java
class DiningPhilosophers {
    int num = 5;
    //五个叉子的信号量
    private Semaphore[] semaphores = new Semaphore[5];

    public DiningPhilosophers() {
        for (int i = 0; i < num; i++) {
            //每只叉子只有1个
            semaphores[i] = new Semaphore(1);
        }

    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        //左边叉子的位置
        int left = philosopher;
        //右边叉子的位置
        int right = (philosopher + 1) % num;
        while (true) {
            if (semaphores[left].tryAcquire()) {
                //先尝试获取左边叉子，如果成功再尝试获取右边叉子
                if (semaphores[right].tryAcquire()) {
                    //两个叉子都得到了，进餐
                    pickLeftFork.run();
                    pickRightFork.run();
                    eat.run();
                    putLeftFork.run();
                    //释放左边叉子
                    semaphores[left].release();
                    putRightFork.run();
                    //释放右边边叉子
                    semaphores[right].release();

                    //吃完了，就跳出循环
                    break;
                } else {
                    //如果拿到了左边的叉子，但没拿到右边的叉子： 就释放左边叉子
                    semaphores[left].release();
                    //让出cpu等一会
                    Thread.yield();
                }
            } else {
                //连左边叉子都没拿到，就让出cpu等会吧
                Thread.yield();
            }
        }

    }

}
```

比较奇怪的是偶尔会报超时。