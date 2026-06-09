### 解题思路
参考剑指offer原书，动态规划dp，dp(n) = max(dp(n-cut)*dp(cut))     0 < cut <= n/2
### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n< 2) return 0;
        if(n==2) return 1;
        if(n==3) return 2; 

        //原始长大于等于4
        int* dp = new int[n+1];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;      //这里不作为原始绳长，而是剪完之后比如剪了一段3，本身的长度就比继续分的长度乘积大(4之后开始不符合)

        for(int i=4; i<n+1; i++)
        {
            int max = INT_MIN;
            for(int cut=1; cut <= i/2; cut++)
            {
                max = dp[i-cut]*dp[cut] > max ? dp[i-cut]*dp[cut] : max;    //o(n2),o(n) dp 从上到下分析，从下到上求解
            }
            dp[i] = max;
        }
        return dp[n];
    }
};
```

### 解题思路
贪心算法，尽量多的长度为3的字段，剩余4时停止(4>3*1)

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n< 2) return 0;
        if(n==2) return 1;
        if(n==3) return 2; 

        //原始长大于等于4, 尽量多分为长度为3的字段，剩余为4时不剪 (贪心算法o(1),0(1))
        int count3 = n / 3;
        int left = n % 3;
        int ans;
        if(left==1)
        {
            count3 -= 1;
            ans = pow(3, count3)*4;
        }
        else if(left==0) ans = pow(3, count3);
        else ans = pow(3,count3)*left;

        return ans;
    }
};
```