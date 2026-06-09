在打家劫舍的精选题解上进行了修改。那位老哥的题解很清晰，大家可以去看下，我只是分了可以第一家和可以最后一家的情况。

[@ikaruga](/u/ikaruga)
```java []


class Solution {
    public int rob(int[] nums) {
        if(nums.length == 1){
            return nums[0];
        }
        int sumOdd = 0;
        int sumEven = 0;
    
        for(int i = 0;i<nums.length-1;i++){
            if(i % 2 == 0){
                sumEven += nums[i];
                sumEven = Math.max(sumOdd,sumEven);
            }else{
                sumOdd += nums[i];
                sumOdd = Math.max(sumOdd,sumEven);
            }
        }
        int sumFirst = Math.max(sumOdd,sumEven);
        
        sumOdd = 0 ;sumEven = 0;
         for(int i = 1;i<nums.length;i++){
            if(i % 2 == 0){
                sumEven += nums[i];
                sumEven = Math.max(sumOdd,sumEven);
            }else{
                sumOdd += nums[i];
                sumOdd = Math.max(sumOdd,sumEven);
            }
        }
        int sumLast = Math.max(sumOdd,sumEven);
        return Math.max(sumLast,sumFirst);
    }
}
```