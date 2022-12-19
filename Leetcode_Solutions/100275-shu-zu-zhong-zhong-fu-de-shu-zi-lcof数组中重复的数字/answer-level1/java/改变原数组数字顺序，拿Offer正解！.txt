### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        if(nums.length==0)
            return -1;
        int i = 0;
        while(i<nums.length){
            if(nums[i]==i){
                i++;
                continue;
            }else{
                if(nums[i]==nums[nums[i]]){
                    return nums[i];
                }else{
                    int temp = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = temp;
                }
            }

        }
        return -1;
    }
}
```