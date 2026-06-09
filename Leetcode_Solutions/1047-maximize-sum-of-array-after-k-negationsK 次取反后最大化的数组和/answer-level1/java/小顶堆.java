### 解题思路
当K不为0，就取出堆顶的元素反转，然后入堆，最后加和。

### 代码

```java
class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        //小顶堆
        PriorityQueue<Integer> min = new PriorityQueue<>((a,b)->a-b);
        int res = 0;
        for (int i : A) {
            min.add(i);
            res += i;
        }
        while (K-- != 0){
            Integer poll = min.poll();
            res -= poll;
            min.add(-poll);
            res += -poll;
        }
        return res;
    }
}
```