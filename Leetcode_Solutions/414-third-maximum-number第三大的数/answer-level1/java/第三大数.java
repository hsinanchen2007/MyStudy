### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int thirdMax(int[] nums) {
        if(nums.length == 0)
            return 0;
        int third = 2;
        int i;
        Arrays.sort(nums);
        if(nums.length < 3)
            return nums[nums.length-1];
        for(i = nums.length - 2; i >= 0; i--){
            if(nums[i] < nums[i+1])
                third = third - 1;
            if(third == 0)
                break;
        }
        
        if(third == 0)
            return nums[i];
        return nums[nums.length-1];
    }
}
```