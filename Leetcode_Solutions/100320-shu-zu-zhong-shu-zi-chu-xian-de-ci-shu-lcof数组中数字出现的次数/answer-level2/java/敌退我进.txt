```
class Solution {
    public int[] singleNumbers(int[] nums) {
        int[] ret = new int[2] ;
        int xor = 0 ;
        for (int i =0 ; i < nums.length ; i ++) {
            xor ^= nums[i] ;
        }
        // xor最后一位为1的数。比如： 12（1100）的最后一位为1的数是 4（0100）
        int lastOne = xor & -xor ;
        int a = 0 ;
        int b = 0 ;
        for (int i =0 ; i < nums.length ; i ++) {
            //分组将两个不同的数分到不同组
            if ( (nums[i] & lastOne) == 0)
                a ^= nums[i] ;
            else
                b ^= nums[i] ;
        }
        ret[0] = a ;
        ret[1] = b ;
        return ret ;
    }
}
```
