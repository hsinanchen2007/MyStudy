### 解题思路
此处撰写解题思路

### 代码

```java
class MovingAverage {

    /** Initialize your data structure here. */
    int window=0, max=0;
    double sum=0.0;
    LinkedList<Integer> nums=new LinkedList<>();
    public MovingAverage(int size) {
        max=size;
    }
    
    public double next(int val) {
        if(window<max)
            ++window;
        else
            sum=sum-nums.removeFirst();
        nums.addLast(val);
        sum+=val;
        return sum/window;
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
```