### 解题思路
思路可以参看代码

### 代码

```java
class Solution {
    // 1. 先排序，对于每一个元素，使用二分法找到另一个元素
    // √ 2. 扫描存储在hash表中，对每一个元素，判断与target的差值是否在hash表中
    //      时间复杂度：O(2*n)（两次遍历）
    //      空间复杂度：O(n)（hash表）   
    //    问题：1. 是否存在相同元素（存在，两遍hash通过遍历下标和hash下标不同来解决；一遍hash可以在覆盖相同元素前就判断完成）
    //         2. 是否存在负数（存在）
    //    优化：在第一次遍历时就直接开始寻找
    //          时间复杂度：O(2*n) -> O(n)
    public int[] twoSum(int[] nums, int target) {
        // 对应值，下标
        HashMap<Integer, Integer> map = new HashMap<>();
        // 扫描到hash表中
        for (int i = 0; i < nums.length; i++) {
            // 加入hash表之前先判断是否已经存在这样的两个数了
            Integer index = map.get(target - nums[i]);
            if (index != null) {
                return new int[]{index, i};
            }
            map.put(nums[i], i);
        }
        // 未找到
        return new int[0];
    }
}
```