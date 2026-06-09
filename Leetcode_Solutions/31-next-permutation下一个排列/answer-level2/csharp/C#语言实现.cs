参照了官方题解和下面一些小伙伴的讲解。哈哈哈
```
public class Solution {
    public void NextPermutation(int[] nums) {
        bool find = false;
        int index = 0;
        for(int i=nums.Length-1; i>0;i--){
            if(nums[i]>nums[i-1]){
                index = i-1;
                find = true;
                break;
            }
        }
        
        //说明全部是降序 进行翻转然后输出
        if(!find){ 
            SwitchLoHi(nums,0,nums.Length-1);
            return;
        }
        
        int index2 = 0;
        for(int j=nums.Length-1;j>index;j--){
            if(nums[j]>nums[index]){index2=j; break;}
        }
        
        Switch(nums, index, index2);   
        SwitchLoHi(nums, index+1, nums.Length-1);
    }
    
    public void SwitchLoHi(int[] nums, int lo, int hi){
         while(lo<hi){
               Switch(nums, lo++,hi--);
         }
    }
    
    public void Switch(int[] nums, int i, int j){
        int m=0;
        m=nums[i];
        nums[i] = nums[j];
        nums[j]= m;
    }
}
```
