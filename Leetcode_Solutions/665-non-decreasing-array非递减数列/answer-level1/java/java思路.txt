如果只有两个元素直接返回true
如果只有三个元素，记录nums[i]>nums[i+1]的次数，如果大于一则返回flase
如果是三个元素以上，同样记录nums[i]>num[i+1],在满足nums[i+1]>nums[i-1]的情况下（比如说[1,4,3,...]），令nums[i+1]=nums[i],若3之后的元素都大于4,则实现非递减数列


```
class Solution {
    public boolean checkPossibility(int[] nums) {
        if(nums.length<3){return true;}
        int count = 0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]>nums[i+1]){
                count++;
                if(i>0&&nums[i-1]>nums[i+1]){nums[i+1]=nums[i];}
            }
            if(count>1){return false;}
        }
        return true;
    }
}
```


