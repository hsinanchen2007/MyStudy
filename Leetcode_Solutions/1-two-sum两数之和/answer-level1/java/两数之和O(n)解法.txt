### 解题思路
定义一个Map存储上一个值，Key：存储数组之前位置对应的数值，value存储数值对应的位置
由于HashMap key查找时间复杂度为O(1)，利用这一特性，在通过target - 数组当前遍历的值 ，去hashMap中查找，如果查找到的话，即返回。

### 代码

```java
class Solution {
     public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> map = new HashMap<>();
        int[] position = new int[2];
        for (int i = 0; i < nums.length; i++) {
            if (map.keySet().contains(target - nums[i])) {
                position[0] = map.get(target - nums[i]);
                position[1] = i;
                return position;
            }else {
                map.put(nums[i],i);
            }
        }
        return position;
    }
}
```