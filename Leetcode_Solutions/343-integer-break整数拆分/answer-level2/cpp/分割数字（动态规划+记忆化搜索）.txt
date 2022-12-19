### 题解
memo[i]---->分割数字的乘积最大值
![image.png](https://pic.leetcode-cn.com/d2c1f4e595cd9015387f9cbb8bb1a2be952caa3866eb1b730b9819fb6dade204-image.png)

### 代码

```cpp
//方法一：记忆化搜素
class Solution {
private:
    vector<int> memo;
    int max3(int a,int b,int c){
        return max(a,max(b,c));
    }
    int breakInteger(int n) {
        if(n==1) return 1;

        if(memo[n] != -1)
            return memo[n];
        int res = -1;
        for(int i=2;i<=n;i++) {
            for(int j=1;j<i;j++) {
                res = max3(res, j*(i-j),j * breakInteger(i-j));
            }
        }
        memo[n] = res;
        return res;
    }
public:
    //记忆化搜索
    int integerBreak(int n) {
        memo = vector<int>(n+1,-1);
        return breakInteger(n);
    }
};

//方法二：动态规划
class Solution {
private:
    vector<int> memo;
    int max3(int a,int b,int c){
        return max(a,max(b,c));
    }
    int breakInteger(int n) {
        if(n==1) return 1;

        for(int i=2;i<=n;i++) {
            for(int j=1;j<i;j++) {
                memo[i] = max3(memo[i], j*(i-j),j * memo[i-j]);
            }
        }
        return memo[n];

    }
public:
    //动态规划
    int integerBreak(int n) {
        memo = vector<int>(n+1,-1);
        return breakInteger(n);
    }
};


```