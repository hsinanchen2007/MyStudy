```
class Solution {
    public int rob(int[] nums) {
        if(nums.length==0)return 0;
        int use=0,notUse=0,use2=0,notUse2=0;
        for(int i=2;i<nums.length-1;i++){
            int tmp=use;
            use=notUse+nums[i];
            notUse=Math.max(tmp,notUse);
        }
        for(int i=1;i<nums.length;i++){
            int tmp=use2;
            use2=notUse2+nums[i];
            notUse2=Math.max(tmp,notUse2);
        }
        return Math.max(Math.max(use,notUse)+nums[0],Math.max(use2,notUse2));
    }
}
```