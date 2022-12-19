```
class Solution {
    public int hammingDistance(int x, int y) {
        int res = x^y;
        int count =0;
//***中的判断整数的二进制流中1的个数的思路
        while(res!=0){
            ++count;
            res=res&(res-1);
        }
        return count;
    }
}
```
