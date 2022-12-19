### 解题思路
从左到右找到相等的开始计数加一，遇到更大的数就停止并返回。
![image.png](https://pic.leetcode-cn.com/1a468e74cc0127c8dd27924c42c22c4a612f8dc4de168aff560ec982f9cc1eb7-image.png)


### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums.length==0 || target<nums[0] || target > nums[nums.length-1]) return 0;
        int index = 0;
        int count = 0;
        for(index=0;index<nums.length && target>=nums[index];index++){
            if(target==nums[index]) count++;
        }
        return count;
    }
}
```