### 解题思路
核心要点：长度为j的绳子拆后段乘积的最大值dp[j]=max(dp[j],dp[j-i]*i)，i∈[1,(n+1)/2]，即i最大不能是n，但也要至少为n的一半
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        vector<int>mv(n+1,0);
        mv[0]=1;
        for(int i=1;i<=(n+1)/2;i++){
            for(int j=i;j<=n;j++){
                mv[j]=max(mv[j],mv[j-i]*i);
            }
        }
        return mv[n];
    }
};
```