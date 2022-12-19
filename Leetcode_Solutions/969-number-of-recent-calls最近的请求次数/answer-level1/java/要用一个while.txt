### 解题思路
用一个while,移除所有大于3000的。

### 代码

```java
class RecentCounter {

    Deque<Integer> deque;

    public RecentCounter() {
        deque = new LinkedList<>();
    }

    public int ping(int t) {
        deque.addLast(t);
        while (!deque.isEmpty() && t - deque.peekFirst() > 3000) {
            deque.pollFirst();
        }
        return deque.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
```