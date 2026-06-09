```
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n=x^y;
        int res=0;
        while(n)
        {
            if(n%2!=0)res++;//若最低位是1 则余数不为0 res++
            n=n>>1;//向右移1位
        }
        return res;
    }
};
```
