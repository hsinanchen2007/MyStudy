### 解题思路
1)使用hash表来解决，循环数组，计算当前数组中数值和给定值的差时多少，判断hash中是否存在这个差值(并且要判断不是当前下表的值)，如果存在，则能相加得到接结果，返回hash表中国对应的下标和当前下表，否则村如hashMap中，其中key为当前下表数组的值，value为当前数组的索引。

### 代码

```java
class Solution {
     public int[] twoSum(int[] nums, int target) {
		Map<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			int result = target - nums[i];
			if (map.containsKey(result) && map.get(result) != i) {
				return new int[] {map.get(result), i};
			}
            map.put(nums[i], i);
		}
        throw new IllegalArgumentException("错误");
    }
}
```