### 解题思路
麻蛋，看了人家的代码才明白啥意思，这个t，一次输入一次。
每次进去一个t，出几个就不一定了，用循环出，有不符合条件的就出一个，
最后返回的是队列剩余符合条件的ping。
//但我还是不明白这个RecentCounter到底代表了啥，写成ping不行吗？

### 代码

```java
class RecentCounter {
    Queue<Integer> queue = new LinkedList<Integer>();
    public RecentCounter() {
        
    }
    
    public int ping(int t) {
        queue.offer(t);
        while(queue.peek()<t-3000){
            queue.poll();
        }
    return queue.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
```