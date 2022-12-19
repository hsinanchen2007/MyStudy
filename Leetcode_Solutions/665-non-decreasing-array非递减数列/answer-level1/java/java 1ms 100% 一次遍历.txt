### 解题思路
遍历整个数组如果出现不满足非递减的情况，并对每一次计数，第二次出现非递减时直接返回false。
对于每一个非递减数列中的断点，可分为两种不同的情况
①第i个元素是断点(nums[i]>nums[i+1])，i+1个元素小于i-1个元素，在只修改一个元素的情况下只能改变i+1的值才能保证是一个非递减数列，为了尽可能不影响后面的元素，nums[i+1]=min(满足条件的值)=nums[i];
②第i个元素是断点，i+1个元素大于等于i-1个元素,在满足条件的情况下修改nums[i]=[nums[i-1],nums[i+1]]中任取一个值
### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        int count=0,temp=Integer.MIN_VALUE;
        for(int i=0;i<nums.length-1;i++){
            //出现不满足非递减的情况
            if(nums[i]>nums[i+1]){
                //第二次出现非递减时直接返回false
                if(count++>0){
                    return false;
                }
                if(nums[i+1]<temp){
                    nums[i+1]=nums[i];
                }else{
                    nums[i]=temp;
                } 
            }
            temp=nums[i];
        }
        return true;
    }
}
```