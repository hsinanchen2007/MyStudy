### 解题思路
此处撰写解题思路
当时只想到堆插入和删除都是O(logn)，忘了一共有n个数据，那就是O(nlogn).....
执行用时 :
5 ms
, 在所有 Java 提交中击败了
5.22%
的用户
内存消耗 :
39.4 MB
, 在所有 Java 提交中击败了
33.33%
的用户
### 代码

```java
class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int len = nums.length;
        int[] res = new int[len];
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < len; i++){
            int tmp = a * nums[i] * nums[i] + b * nums[i] + c;
            queue.offer(tmp);
        }
        for (int i = 0; i < len; i++){
            res[i] = queue.poll();
        }
        return res;
    }
}
```