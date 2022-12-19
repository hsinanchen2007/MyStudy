方法一：  
需要改变的数有两种情况，一种是该数比两边的数都小，一种是比两边的数都大；   
对于第一种情况，顺序遍历找出这样的数的个数count1：用max保存前面遍历过的最大数，如果nums[i]小于max，则count1加一；    
对于第二种情况顺序无法查找，因此用倒序遍历找出这样的数的个数count2：用min保存遍历过的最小值，如果nums[l-i-1]大于min，则count2加一；  
最后只要count1和count2只要有一个小于等于1就满足要求  
```
class Solution {
    public boolean checkPossibility(int[] nums) {
        int l = nums.length;
        int count1 = 0, max = 0;
        int count2 = 0, min = l;
        for(int i=0;i<nums.length;i++){
            if(nums[i]<max){
                count1++;
            }
            if(nums[l-i-1]>min){
                count2++;
            }
            max = max>nums[i]?max:nums[i];
            min = min<nums[l-i-1]?min:nums[l-i-1];
        }
        return count1<=1 || count2<=1;
    }
}
```
方法二：  
在遍历的过程中修改数组，如果出现nums[i]>nums[i+1]，则需要修改一个数，count加一，而修改分两种情况：  
1.如果i是0或者i-1的值小于i+1的值，就将nums[i]减小为nums[i+1]；  
2.如果i+1的值小于i-1的值，就将nums[i+1]增大为nums[i]；
```
class Solution {
    public boolean checkPossibility(int[] nums) {
        int count = 0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]>nums[i+1]){
                if(i==0 || nums[i+1]>=nums[i-1]){
                    nums[i] = nums[i+1];
                }else{
                    nums[i+1] = nums[i];
                }
                count++;
            }
        }
        return count<=1;
    }
```
两种解题方法的时间消耗几乎相同