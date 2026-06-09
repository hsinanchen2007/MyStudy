### 解题思路
太难了，比赛的时候我一直在想回溯怎么写，结果写完超时了，赛后看大佬们的做法才知道原来可以倒着往前推，这真是怎么也想不到啊
### 代码

```java
class Solution {
    
    public boolean isPossible(int[] target) {
        Queue<Long> q = new PriorityQueue<>(target.length, Comparator.reverseOrder());
        long sum = 0;
        for (int i = 0; i < target.length; i++) {
            sum += target[i];
            if (target[i] > 1) q.offer((long)target[i]);
        }
        while (!q.isEmpty()) {
            Long top = q.peek();
            if (top == 1) return true;
            q.poll();
            Long before = top - (sum - top);
            sum = top;
            if (before < 1) return false;
            q.offer(before);
        }
        return true;
    }
}
```