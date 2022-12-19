执行结果：
通过
显示详情
执行用时 :
3 ms
, 在所有 Java 提交中击败了
67.16%
的用户
内存消耗 :
41.6 MB
, 在所有 Java 提交中击败了
71.69%
的用户
```
class Solution {
    public boolean canJump(int[] nums) {
        int len=nums.length;
        if(len<=1)return true;
        
        int max=nums[0];
        if(max>=len-1)return true;
        int start=0;
        while(true){
            int newMax = jj(nums,start,max);
            if(newMax>=len-1){
                return true;
            }else if(newMax<=max){
                return false;
            }else{
                start=max+1;
                max=newMax;
            }
        }
       // return false;
        
    }
    private int jj(int[] nums,int start, int max){
         int mm=0;
        for(int i=start; i<=max; i++){
            int x = nums[i]+i;
            if(x>mm)mm=x;
        }
        return mm;
    }
}
```
