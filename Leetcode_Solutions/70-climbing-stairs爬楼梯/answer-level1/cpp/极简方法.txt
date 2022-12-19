![Snipaste_2020-04-03_17-40-29.png](https://pic.leetcode-cn.com/1c377d632fa0d4fc954fd3d939c0d582c930f65aa25151ce05bd9a09b160994a-Snipaste_2020-04-03_17-40-29.png)


class Solution {
public:
    int climbStairs(int n){
        int i = 0，j = 1;
        while(n--){
            j = i + j;
            i = j - i;
       }
        return j;        
    }
};