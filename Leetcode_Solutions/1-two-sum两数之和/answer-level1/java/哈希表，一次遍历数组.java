### 解题思路
将每一个数组值减去传入的值，判断最后的值是否存在于key中
若存在将其索引打印出来

### 代码

```java
class Solution {
      public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int size=nums.length;
        int a = 0;
        for (int i = 0; i < size; i++) {
            a = target - nums[i];
            if (map.containsKey(a)) {      
                return new int[]{ map.get(a), i };
            }
            map.put(nums[i], i);
        }
      return new int[]{};
    }
}
```