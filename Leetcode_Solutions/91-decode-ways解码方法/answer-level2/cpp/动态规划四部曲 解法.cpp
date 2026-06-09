### 解题思路
动态规划四部曲
1. 确定状态
    f[i] 表示前i个数字最多能转换成几种字母
2. 状态转换方程
    f[i] = f[i-1]|第i个数字可转换成字母的情况 + f[i-2]|第i和第i-1个数字可转换成字母的情况下
3. 初始值和边界条件
    f[0] = 1，无法转换的f[j] = 0;
4. 计算顺序
    从小到大计算

### 代码

```cpp
class Solution {
public:

    int numDecodings(string s) {
        const int n = s.size();

        
        vector<int> f(n+1, 0);
        
        // f[i] 表示前i个数字可以转换成多少种字母
        f[0] = 1;
        //cout << CanDoubleConvert(s, 0) << endl;

        for(int i = 1; i <= n; i++){
            
            // 最后一个数字
            int t = s[i-1] -'0';
            if (t >= 1 && t <= 9){
                f[i] += f[i-1];
            }
            
            // 最后两个数字
            if (i >= 2){
                int d = (s[i-2]-'0') * 10 + t;
                if (d >= 10 && d <= 26){
                    f[i] += f[i-2];
                }
            }
        }
    
        return f[n];
    }
};
```