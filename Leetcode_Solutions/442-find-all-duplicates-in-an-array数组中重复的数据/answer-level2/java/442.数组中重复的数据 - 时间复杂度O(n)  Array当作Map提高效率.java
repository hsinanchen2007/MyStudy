### 解题思路
把ArrayList当作Map来使用，实测数组的访问是比HashMap要快的，因此只要定义一个长度为nums中最大值的数组用来存放nums中每个数字的出现次数即可。

### 代码

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> result = new LinkedList<>();
        if (nums.length == 0) return result;
        int max = nums[0];
        // 寻找数组nums中的最大值
        for (int num : nums) {
            if (num > max) max = num;
        }
        List<Integer> map = new ArrayList<>((int)(max * 1.5));
        // 初始化每个数字的出现次数为0
        for (int i = 0; i <= max; i++) {
            map.add(0);
        }
        for (int num : nums) {
            // 将当前数字出现次数+1
            map.set(num, map.get(num) + 1);
        }
        // 在map中遍历找到出现次数大于1的数字存入结果列表
        for (int i = 0; i <= max; i++) {
            if (map.get(i) > 1) {
                result.add(i);
            }
        }
        return result;
    }
}
```