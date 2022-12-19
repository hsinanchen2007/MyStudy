```
class Solution {
    public int firstMissingPositive(int[] nums) {
        for(int i=0;i<nums.length;i++){
            if(i!=0&&nums[i]==nums[i-1]){
                continue;
            }
            //思路就是每遇到一个1-n之间数字就把其放到对应的位置（因为返回结果最大也就是n+1，长度为n），i放到索引为i-1的位置（前提是i-1的位置本身不为i，否则会死循环）
            if(nums[i]!=i+1&&nums[i]>0&&nums[i]<=nums.length){
                if(nums[nums[i]-1]==nums[i]){
                    continue;
                }
                int tmp=nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=tmp;
                i=i-1;
            }
        }
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return nums.length+1;
    }
}
```

