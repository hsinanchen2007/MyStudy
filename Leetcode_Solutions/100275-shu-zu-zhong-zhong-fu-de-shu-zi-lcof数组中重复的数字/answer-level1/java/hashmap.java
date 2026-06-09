### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int res = -1;
        for (int num : nums){
            map.put(num, map.getOrDefault(num,0) + 1);
        }
        for (int i = 0; i < map.size(); i++){
            if (map.get(nums[i]) != null && map.get(nums[i]) > 1) res = nums[i];
        }
        return res;
    }
}
```