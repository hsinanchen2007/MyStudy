
![image.png](https://pic.leetcode-cn.com/fc7f6896ef0004c2caf3005ed41fa3234476605102965cf45d86bf3a95fd2fe8-image.png)
用flag判断是否是第二次遇到该值还是更多次遇到该值。
```
    public int removeDuplicates(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }
        int count = 0;
        boolean flag = false;
        for(int i=1; i<nums.length; i++){
            if(nums[count] == nums[i] && !flag){
                flag = true;
                nums[++count] = nums[i];
                continue;
            }
            if(nums[count] == nums[i] && flag){
                continue;
            } else {
                flag = false;
            	nums[++count] = nums[i];
            }
        }
        return count += 1;
    }
```
