### 解题思路
读不懂题，就当复习一下队列的知识点了。

### 代码

```java
class RecentCounter {
    Queue <Integer> queue;
    public RecentCounter() {
        queue=new LinkedList<Integer>();
    }
    
    public int ping(int t) {
        queue.add(t);
        while(queue.peek()<t-3000)
            queue.poll();
        return queue.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
```