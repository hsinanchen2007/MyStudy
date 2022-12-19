### 解题思路
题目可这样理解：ping()方法传入的参数t为一个时间值，这个时间值代表了某次ping的时刻。现在要求出$[t-3000,t]$的时间段内ping的次数。
可用Queue解题作为队列的练习：创建一个队列，存储每次ping的时刻，即每次调用方法的参数t。每传入一次ping的时刻，就将其加入队尾，并检查队首元素的值，如果小于$t-3000$，说明不在要求的时间段内，清除出队，循环此操作，直至队首元素的值大于等于$t-3000$。
则此时，队列的所有元素都是在时间段$[t-3000,t]$内发出的ping的时刻（因为t值严格递增），显然，此时队列元素的数量就是符合要求的ping的次数。

### 代码

```java
class RecentCounter {
    private Queue<Integer> q;

    public RecentCounter() {
        q = new LinkedList<Integer>();    
    }
    
    public int ping(int t) {
        q.offer(t);
        while(q.peek() < t-3000)
            q.poll();
        return q.size();
    }
}
```