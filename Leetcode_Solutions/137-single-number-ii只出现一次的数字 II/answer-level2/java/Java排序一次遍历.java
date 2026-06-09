### 解题思路
从 [只出现一次的数字](https://leetcode-cn.com/problems/single-number/) 这一题引申而来

首先排序，然后分为三种情况
1. 1 3 3 3 ...
2. ... 3 1 3 ...
3. ... 3 3 3 1

其中`1` `2`两种情况可以合并考虑，`for(int i=0;i<nums.length;i=i+3)`，当出现`nums[i]`和`nums[i+1]`不相等的情况，则返回`nums[i]`

`3`这种情况当`i==nums.length-1`，则返回`nums[i]`

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        if(nums.length==1){
            return nums[0];
        }

        int i=0;
        for(;i<nums.length;i=i+3){
            if(i==nums.length-1){
                return nums[i];
            }

            if(nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
        
        return nums[i];
    }
}
```