### 解题思路
该问题是台阶问题的进化版。转移方程为：

### 代码

```cpp
class Solution {
public:
    int translateNum(int num) {
        string numStr = to_string(num);

        //各个位置初始化为1，因为每个位置至少是一个
        std::vector<int> dp(numStr.size()+1,1);
        for(int i = 1;i<numStr.size();i++){
            if(numStr[i-1] == '0' || numStr.substr(i-1,2) > "25"){
                //只能是1位的情况
                dp[i+1] = dp[i];
            }else{
                //两位能组合成一个字母的情况
                dp[i+1] = dp[i] + dp[i-1];
            }
        }

        return dp[numStr.size()];
    }
};
```