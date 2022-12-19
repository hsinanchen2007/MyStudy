![image.png](https://pic.leetcode-cn.com/32f2da368e19e5b4c77ff869ba3562603b71223fed13dbfeb5a6058149f6eccb-image.png)




```
class Solution {
    public boolean checkPossibility(int[] nums) {
        int count = 0;
        if(nums.length <=1){
            return true;
        }
        for(int i=1;i<nums.length && count<=1;i++){
            if(nums[i-1] > nums[i]){
                count++;
                if(i-2<0 || nums[i-2] < nums[i]){
                    nums[i-1] = nums[i];
                }else{
                    nums[i] = nums[i-1];
                }
            }
        }
        return count <= 1;
    }
}
```

