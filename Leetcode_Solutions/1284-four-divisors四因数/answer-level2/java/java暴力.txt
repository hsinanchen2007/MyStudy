```
class Solution {
    public int sumFourDivisors(int[] nums) {
        int sum= 0;
        for(int i = 0;i<nums.length;i++){
            int k = 0;
            int a = 0;
            int b = 0;
            int p = 0;
            for(int j = 2;j<nums[i]/2;j++){
                if(p==0&&nums[i]%j== 0&&j!=nums[i]/j){
                    a = j;
                    b = nums[i]/j;
                    k =  1 + nums[i] + j + nums[i]/j;
                    p++;
                }
                if(p==1&&a!=j&&b!=j&&nums[i]%j==0){
                    p++;
                    break;
                }
            }
            if(p==1){
                sum += k;
            }
        }
        return sum;
    }
}
```
