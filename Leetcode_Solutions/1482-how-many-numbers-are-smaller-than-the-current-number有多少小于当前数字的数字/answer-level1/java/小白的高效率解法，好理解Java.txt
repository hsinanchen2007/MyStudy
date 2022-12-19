### 解题思路
看注释

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] copy = Arrays.copyOf(nums,nums.length);
        Arrays.sort(copy);
        //map存储下标，提高查询速度
        Map<Integer, Integer> map = new HashMap<>();
        for (int j = 0; j < copy.length; j++) {
            //只用记录最小的index
            if (!map.containsKey(copy[j])) {
                map.put(copy[j], j);
            }
        }

        // 获得结果
        for (int i = 0; i < nums.length; i++) {
            nums[i] = map.get(nums[i]);
        }
        return nums;
    }
}
```