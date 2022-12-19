找规律；
高位数，如 8 （1000）二进制4位数；是 000 的结果 +1；
dp[i] = dp[i - 2^digNum]  + 1; 
```
class Solution {
    public int[] countBits(int num) {
        int[] ans = new int[num+1];
        if(num < 0) return ans;
        ans[0] = 0;
        if(num == 0) return ans;
        ans[1] = 1;
        if(num == 1) return ans;
        
        int digNum = 1;
        for(int i = 2; i <= num; i++){
            if(i>=Math.pow(2,digNum+1)) digNum++;
            ans[i] = ans[i - (int)(Math.pow(2,digNum))] +1;
        }
        return ans;
    }
}
```
这里，在计算幂运算耗费太多时间；
用 digit 来存储幂运算结果。
```
class Solution {
    public int[] countBits(int num) {
        int[] ans = new int[num+1];
        // if(num < 0) return ans;
        ans[0] = 0;
        if(num == 0) return ans;
        int digNum = 0;
        int digit = (int)(Math.pow(2,digNum));
        for(int i = 1; i <= num; i++){
            if(i>= digit*2){
                digit*= 2;
                digNum++;
            }
            ans[i] = ans[i - digit ] +1;
        }
        return ans;
    }
}
```
O(n)的时间复杂度。