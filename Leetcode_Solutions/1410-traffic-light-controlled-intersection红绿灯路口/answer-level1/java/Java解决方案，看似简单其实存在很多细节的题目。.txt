解题思路简单描述：
- 两条道路上同时只能有一条道路上为绿灯，可以用一个AtomicBoolean类型的变量（occupied）来表示绿灯是否已经被争抢，初始值为false。
- 设置两个volatile boolean类型的变量：roadAAllowed（初始值为true）和roadBAllowed（初始值为false），用于表示道路A和道路B当前是否被允许行车（绿灯）。
- 设置两个AtomicInteger类型的变量：roadACardCount和roadBCardCount，用于表示道路A和道路B上当前行进的车辆数量，同一条道路上的行车不区分方向，可以同时有多个。
- 当一条道路上车辆到达时，会尝试开启绿灯，占用道路（tryOccupyRoadX）。如果绿灯已经被另外一条道路开启，那么该道路上的车辆等待并不断尝试开启绿灯。需要注意的时：假设一条道路上同时有多辆车辆，那么一旦绿灯被开启，其它车辆无需也不能再开启绿灯，也不需要陆续通过，可以并行通过。这类似再入的概念。
- 此处的解法会优先通过同一条道路上的车辆，如果一条道路上有不间断的车辆，那么另外一条道路上的车辆会等待，这有点非公平锁的意思。仔细考虑题目要求可能会发现其它细节。

```
class TrafficLight {
    private AtomicBoolean occupied = new AtomicBoolean(false);

    private volatile boolean roadAAllowed = true;
    private AtomicInteger roadACardCount = new AtomicInteger(0);

    private volatile boolean roadBAllowed = false;
    private AtomicInteger roadBCardCount = new AtomicInteger(0);
    
    public TrafficLight() {   
    }
    
    public void carArrived(
        int carId,           // ID of the car
        int roadId,          // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,       // Direction of the car
        Runnable turnGreen,  // Use turnGreen.run() to turn light to green on current road
        Runnable crossCar    // Use crossCar.run() to make car cross the intersection 
    ) {
        if (roadId == 1 && tryOccupyRoadA(turnGreen)) {
            this.roadACardCount.incrementAndGet();
            crossCar.run();
            releaseRoadAIfNecessary();
        } else if (roadId == 2 && tryOccupyRoadB(turnGreen)) {
            this.roadBCardCount.incrementAndGet();
            crossCar.run();
            releaseRoadBIfNecessary();
        }
    }

    private boolean tryOccupyRoadA(Runnable turnGreen) {
        while (!this.roadAAllowed) {
            if (this.occupied.compareAndSet(false, true)) {
                turnGreen.run();
                this.roadAAllowed = true;
                this.roadBAllowed = false;
            } else {
                LockSupport.parkNanos(1L);
            }
        }

        return true;
    }

    private boolean tryOccupyRoadB(Runnable turnGreen) {
        while (!this.roadBAllowed) {
            if (this.occupied.compareAndSet(false, true)) {
                turnGreen.run();
                this.roadAAllowed = false;
                this.roadBAllowed = true;
            } else {
                LockSupport.parkNanos(1L);
            }
        }

        return true;
    }

    private void releaseRoadAIfNecessary() {
        if (this.roadACardCount.decrementAndGet() == 0) {
            this.occupied.set(false);
        }
    } 

    private void releaseRoadBIfNecessary() {
       if (this.roadBCardCount.decrementAndGet() == 0) {
            this.occupied.set(false);
        } 
    }
}
```
