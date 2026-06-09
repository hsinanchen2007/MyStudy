**解题思路**
    一开始看到这个题目，我的第一反应就是会用到两个for循环，因为在多个元素中任意两个元素之和等于目标元素，由此可知需要遍历。所以我用的是Java代码表示

```
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] arg=new int[2];
       for(int i=0;i<=nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[i]+nums[j]==target){
                    arg[0]=i;
                    arg[1]=j;
                    return arg;

                }
               

            }

        }
        return arg;
        
    }
}



```