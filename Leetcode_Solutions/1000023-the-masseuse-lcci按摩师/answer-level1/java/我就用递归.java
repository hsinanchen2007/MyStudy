### 解题思路
开始头铁，直接从第一个开始用递归穷举，剪了半天枝都超时。
后来反过来，用类似动态规划的思想递归，总算过了。
我这个也算是动态规划的原始版低配版吧，用map记录重复子问题。

### 代码

```java
class Solution {
    private Map<Integer, Integer> map;

    public int massage(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        map = new HashMap<Integer, Integer>();
        return theMax(nums, nums.length - 1);
    }

    private int theMax(int[] nums, int nowIndex) {
        if (map.keySet().contains(nowIndex)) {
            return map.get(nowIndex);
        }

        if (nowIndex == 0) {
            return nums[0];
        }
        if (nowIndex == 1) {
            return Math.max(nums[0], nums[1]);
        }

        int yes = nums[nowIndex] + theMax(nums, nowIndex - 2);
        int no = theMax(nums, nowIndex - 1);
        map.put(nowIndex - 1, no);
        return Math.max(yes, no);
    }
}
```