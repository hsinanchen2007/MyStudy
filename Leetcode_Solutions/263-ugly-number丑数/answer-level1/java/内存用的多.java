```
class Solution {
    public boolean isUgly(int num) {
        if(num==0){
            return false;
        }
        int[] nums = {2,3,5};
        for(int i=0; i<3; i++){
            if(num%nums[i]==0){
                return isUgly(num/nums[i]);
            }
        }
        if(num==1){
            return true;
        }else{
            return false;
        }
    }

}
```
