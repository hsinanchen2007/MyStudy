### 解题思路
比较简答直观的解法：使用基于大顶堆的优先队列。

时间复杂度：$O(nlogn)$。
空间复杂度：$O(n)$。

代码：
```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxpq = new PriorityQueue<Integer>(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return b - a;
            }
        });
        for(int i : stones)
            maxpq.offer(i);
        while(maxpq.size() > 1)
        {
            int y = maxpq.poll();
            int x = maxpq.poll();
            if(x != y)  
                maxpq.offer(y - x);
        }
        if(maxpq.isEmpty()) return 0;
        return maxpq.peek();
    }
}
```

使用Lambda表达式使代码更简洁：
```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        Queue<Integer> maxpq = new PriorityQueue<>((a, b) -> b - a);
        for(int i : stones)
            maxpq.offer(i);
        while(maxpq.size() > 1)
        {
            int y = maxpq.poll();
            int x = maxpq.poll();
            if(x != y)  
                maxpq.offer(y - x);
        }
        if(maxpq.isEmpty()) return 0;
        return maxpq.peek();
    }
}
```