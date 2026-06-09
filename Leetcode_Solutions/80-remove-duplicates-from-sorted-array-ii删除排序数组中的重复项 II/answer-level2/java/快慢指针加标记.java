```
class Solution {
    public int removeDuplicates(int[] nums) {
        //k是慢指针；i是快指针 
        int k=0;
        //标记这个元素前面是否已经出现过两次 true:出现过
        boolean isDuplicate = false;
        for(int i=1;i<nums.length;i++){
            if(nums[k]==nums[i]){
                //如果快慢指针指向的值相等，并且这个值已经是第二次出现了，这是第三次了，那么继续下一个循环
                if(isDuplicate){
                    continue;
                }
                //如果快慢指针指向的值相等，并且这个值还没有出现过两次，则保留这个值在数组里
                k++;
                if(k!=i){//防止自己和自己交换
                    nums[k] = nums[i];                    
                }
                isDuplicate = true;//现在已经出现过两次了
            }else{
                //如果快慢指针指向的值不相等，则保留这个值在数组里
                k++;
                if(k!=i){//防止自己和自己交换
                    nums[k] = nums[i];                    
                }
                isDuplicate = false;
            }
        }
        return k+1;
    }
}
```
