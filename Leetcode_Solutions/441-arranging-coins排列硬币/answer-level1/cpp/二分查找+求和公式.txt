执行用时 :4 ms, 在所有 C++ 提交中击败了95.62%的用户
内存消耗 :8.1 MB, 在所有 C++ 提交中击败了91.11%的用户

```
class Solution {
public:
    int arrangeCoins(int n) {
        long left=0,right=n;
        while(left<right){
            long mid=(left+right+1)>>1;
            if(mid*(mid+1)>>1 >n)
                right=mid-1;
            else 
                left=mid;
        }
        return right;
    }
};
```
