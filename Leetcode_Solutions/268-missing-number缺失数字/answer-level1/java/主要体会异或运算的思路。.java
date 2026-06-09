```
class Solution {
    /*
    public int missingNumber(int[] nums) {
        //数学问题，首先求前n个数的总和。然后求数组元素累加和，相减就为所要找缺失的数字。
        int sum = 0 ;
        int n = nums.length ;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i] ;
        }
        int summ = n*(n+1)/2 ;
        return summ-sum ;
    }
    */

    //一种位运算异或的方式来解决问题。
    //异或运算符合交换定律。1^1^2^2^3^3^4 = 4 .
    //遍历数组，没一个数都跟其索引异或。初始化一个数组长度的值和数组索引组成全部0到n的数字。
    //通过交换律异或得到缺失的数字。
    public int missingNumber(int[] nums) {
        int mis = nums.length ;
        for(int i=0;i<nums.length;i++){
            mis^=i^nums[i] ;
        }
        return mis ;
    }
}
```
