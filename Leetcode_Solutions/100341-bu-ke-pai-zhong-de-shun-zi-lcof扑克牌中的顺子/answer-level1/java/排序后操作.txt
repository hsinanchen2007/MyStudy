排序后先判断王的数量，然后判断是否递增1，如果不是则判断是否有王，若有则王的数量减一，否则判定为不连续；```
代码块
class Solution {
    public boolean isStraight(int[] nums) {
        Arrays.sort(nums);
        int knum=0,i=0;
        boolean jud=true;
        while(i<nums.length-1){
            if(nums[i]==0){
                knum++;
                i++;}
            else{
                if(nums[i+1]-nums[i]==1){
                    i++;
                }
                else if(knum>0){
                    nums[i]++;
                    knum--;
                }
                else{
                    jud=false;
                    break;
                }
            }
        }
        return jud;
    }
}
```
代码块
```
