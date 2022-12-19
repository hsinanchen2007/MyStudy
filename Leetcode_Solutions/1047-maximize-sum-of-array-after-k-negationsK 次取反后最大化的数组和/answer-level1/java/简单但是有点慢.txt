### 解题思路
每次获取最小值取反，最后求和。

### 代码

```java
class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for(int a : A){
            queue.offer(a);
        }
        while(K>0){
           int a = queue.poll();
           queue.offer(-a);
           K--;
        }
        int ans = 0;
        for(int a : queue){
            ans += a;
        }
        return ans;
    }
}
```