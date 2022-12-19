一开始我用的方法是递归，结果超时了，然后我想[等一下！决定我能不能跳到尾部的唯一条件，其实就是看我能不能跳过所有的"0"，所以我只要检查每个"0"能不能被跳过就好啦！]，所以就写了下面这些代码）

```
public class Solution {
    public bool zero_jump(int n,int[] nums){
        for(int i=n-1;i>=0;i--){
            if(nums[i]>n-i||nums[i]>=nums.Length-1-i){return true;}
        }
        return false;
    }
    public bool CanJump(int[] nums) {

        //特殊情况处理
        if(nums.Length==1){return true;}
        if(nums[0]==0){return false;}

        for(int i=nums.Length-1;i>0;i--){
            if(nums[i]==0){
                if(zero_jump(i,nums)==false){return false;}
                }
        }
        return true;
    }
}
```
