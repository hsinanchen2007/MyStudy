### 说明
这道难度中等的题目，竟把我想了好久，事后看大家的题解，发现是我自己陷到题目中去了，题目说HHO随便什么顺序都可以，我硬是整成了：哪个线程先到，只要不违反规则，一定不拦着它，我看了好多其他人的实现，均不是按这思路来的，有些是一律按固定顺序打印，比如HHO，O如果先到了，也得先等着。

### 解题思路
一个线程能不能继续执行，必须知道当前的状态，故考虑用一个int的不同比特位来表示各种状态，
* 将第1,2位(00000011)用来表示H的坑位，实际00000010时就表示占满了，因为只有两个H
* 将第3位(00000100)用来表示O的坑位，
* 将第4，5位(00011000)用来表示H打印完成标志，实际00010000时就表示占满了，因为只有两个H
* 将第6位(00100000)表示O打印完成标志。

执行逻辑为，打印前先占坑，如果占不到坑，则表示当前不能打印，得等，打印完后，也要进行一次同步（让别的线程知晓你完成占坑对应的工作了，别人可以安全地执行后续逻辑，这也是为什么一定需要第4，5，6位来记录的原因），当两个H和一个O的完成标记都被打上的时候，此时可以安全地复位了，唤醒等待者，进入下一轮


仔细分析可知，该方案严格遵循：“如果当前没有违反规则，那本线程一定不会被阻塞（不管是打印前还是打印后）”，不过该方案还是有点走偏了，因为仅用两个信号量便可达到此要求，要说区别的话，本方案能感知什么时候发生了水分子合成，即重置为0的时候，而下面的信号量的方案则不能。

从性能上来讲，信号量方案的竞争粒度更细(O线程和H线程在判断是否需要阻塞时，彼此可以不互相竞争的)，按理说应该更优（Semaphore.release在此场景也存在优化空间）

如果你对多线程及非阻塞算法感兴趣，可以搜索我的id，博客里写过一些非阻塞算法实践

### 代码(AQS方案)

```java
class H2O {
    class Sync extends AbstractQueuedSynchronizer {
        private AtomicInteger myState = new AtomicInteger();//因为原来的state没提供addAndGet方法

        @Override
        protected int tryAcquireShared(int arg) {
            int flag = arg == 1 ? 2 : 4;//arg == 1时为H，arg == 4时为O，
            int i = myState.get();//i & 3为H的标记位，但最多只能加到2，i & 4为O的标记位
            if((i & flag) != flag && myState.compareAndSet(i, i + arg)){
                return ((i + arg) & 0b0111) == 6 ? 0 : 1;//为6则表示坑位满了，故返回0
            }else{
                return -1;
            }
        }

        @Override
        protected boolean tryReleaseShared(int arg) {
            //记录完成当前工作，因为此处无竞争，故不必用cas，直接加即可
            if(myState.addAndGet(arg) == 0b110110){
                //这两行代码之间，严格保证此时打印出的是完整的水分子
                myState.set(0);//如果大家都完成了，则重置并唤醒等待者
                return true;
            }else{
                return false;
            }
        }
    }
    private Sync sync = new Sync();
    public H2O() {
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {

        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        sync.acquireShared(1);
        releaseHydrogen.run();
        sync.releaseShared(0b00001000);
        
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        sync.acquireShared(4);
        releaseOxygen.run();
        sync.releaseShared(0b00100000);
        
    }
}
```

### 信号量方案
```java
import java.util.concurrent.Semaphore;

class H2O {

    private Semaphore h = new Semaphore(2);
    private Semaphore o = new Semaphore(2);

    public H2O() {
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		h.acquire();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        o.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        o.acquire(2);
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
		releaseOxygen.run();
        h.release(2);
    }
}
```