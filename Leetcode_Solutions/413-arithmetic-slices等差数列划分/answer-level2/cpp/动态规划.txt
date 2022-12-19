### 解题思路
判题机有毒，我从8ms直接飙到0ms
不在赘述，就是简单的动态规划，菜鸡大一写了将近。。。不说了，仅供参考

### 代码

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len=A.size();
        if(len<3) return 0;
        vector<int>dp(len+1,0);
        vector<int>path(len+1,0);
        int sum=1;
        path[1]=A[1]-A[0];
        for(int j=2;j<len;j++){
            path[j]=A[j]-A[j-1];
            if(path[j]==path[j-1]){
                dp[j]=dp[j-1]+sum;
                sum++;
            }
            else{
                dp[j]=dp[j-1];
                sum=1;
            }
        }
        return dp[len-1];
    }
};
```