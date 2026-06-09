```
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double result = 0.0 ;
        double max = -10000.0 ;
        for(int i=0;i<nums.length-k+1;i++){
            double sum = 0.0 ;
            for(int j=i;j<i+k;j++){
                sum= sum+nums[j] ;
            }
            if(sum>max){
                max = sum ;
            }
        }
        result = max/k ;
        return result ;
    }
}
```
