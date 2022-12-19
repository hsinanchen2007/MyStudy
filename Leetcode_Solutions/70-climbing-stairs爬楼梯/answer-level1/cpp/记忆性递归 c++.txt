### 解题思路
把小问题的解计算出来。

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        f_=vector<int>(n+1,0);
        f_[0]=1;
        f_[1]=1;
        return dp(n);
    }
private:
    vector<int> f_; // 记忆化递归
    int dp(int n){  //动态规划
        if(f_[n]>0) return f_[n];
        else{
            f_[n]=dp(n-1)+dp(n-2);
            return f_[n];
        }
    }
};
```