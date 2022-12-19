### 解题思路

以每个 operator 为界分割成两个子表达式分治计算。

### 代码

```cpp
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int n = input.size();
        return divide(input, 0, n - 1);
    }
    
    vector<int> divide(string& expr, int start, int end) {
        vector<int> res;

        bool Op = false;
        for(int i=start; i<=end; i++) {
            if(expr[i] != '+' && expr[i] != '-' && expr[i] != '*')
                continue;
            Op = true;
            auto left = divide(expr, start, i - 1);
            auto right = divide(expr, i + 1, end);
            for(int l: left)
                for(int r: right) {
                    if(expr[i] == '+')
                        res.push_back(l + r);
                    else if(expr[i] == '-')
                        res.push_back(l - r);
                    else if(expr[i] == '*')
                        res.push_back(l * r);
                }
        }
        
        // 纯数字
        if(!Op) {
            int sum = 0;
            for(int i=start; i<=end; i++)
                sum = sum * 10 + expr[i] - '0';
            res.push_back(sum);
        }
        
        return res;
    }
};
```