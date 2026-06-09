通用的剔除K个重复以上元素的解法


```
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0) return 0;
        int k=2;
        int i=k-1;
        int j=k;
        while(j<nums.length){
            if(nums[j] != nums[i-(k-1)]){
                i++;
                nums[i] = nums[j];
            }
            j++;
        } 
        return i+1;
    }
}
```
