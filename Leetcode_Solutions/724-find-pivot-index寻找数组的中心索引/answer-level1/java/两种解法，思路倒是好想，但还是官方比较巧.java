```
class Solution {
    /*
    这种暴力的方法是有点蠢但是能过！
    最容易想到的一种耿直的解法
    public int pivotIndex(int[] nums) {
        //避免考虑边界条件，实例化一个左右添0的数组。
        int[] res = new int[nums.length+2] ;
        res[0] = 0 ;
        res[res.length-1] = 0 ;
        for(int i=1;i<res.length-1;i++){
            res[i] = nums[i-1] ;
        }

        int result = -1 ;
        for(int i=1;i<res.length-1;i++){
            int sumLeft = 0 ;
            int sumRight = 0 ;
            for(int j=i-1;j>=0;j--){
                sumLeft+=res[j] ;
            }
            for(int j=i+1;j<res.length-1;j++){
                sumRight+=res[j] ;
            }
            if(sumLeft==sumRight){
                result = i-1 ;
                break ;
            }
        }

        return result ;
    }
    */

    public int pivotIndex(int[] nums) {
        //使用右和*2+中心索引 = 总和的解法。
        int sum = 0 ;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i] ;
        }

        int result = -1 ;
        for(int i=0;i<nums.length;i++){
            int sumRight = 0 ;
            for(int j=i+1;j<nums.length;j++){
                sumRight+=nums[j] ;
            }
            if(sum-sumRight*2==nums[i]){
                result = i ;
                break ;
            }
        }
        return result ;
    }
}
```
