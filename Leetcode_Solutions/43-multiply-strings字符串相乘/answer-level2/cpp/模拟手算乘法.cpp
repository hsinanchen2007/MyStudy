### 解题思路
第 i 位数 和 第 j 位数相乘， 其值分布在 i + j, 和 i + j + 1 范围上
不要形成思维惯性， 这里就算 `res[i+j] += sum / 10` 超过10 也没关系， 因为 vector<int> 存的是
数字，可以包括多位数

### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m  = num1.size();
        int n = num2.size();
        vector<int> res(m+n, 0);
        for(int i = m-1; i>=0; --i){
            for(int j = n-1; j>=0; --j){
                int temp = (num1[i]- '0') * (num2[j] - '0');
                int sum = temp + res[i+j+1];
                res[i+j+1] = sum % 10;
                res[i+j] += sum / 10;
            }
        }
        string str;
        for(int i =0; i<res.size(); ++i){
            if(i==0 && res[i] == 0) continue;
            str += ('0' + res[i]);
        }
        return str;
    }
};
```