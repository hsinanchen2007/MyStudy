### 解题思路
规律
1.n位数乘m位数，结果为m+n位数
2.num1中的第i位于num2中的第j位相乘，结果一定会落在i+j和i+j+1

### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> res(num1.size() + num2.size(),0);
        for(int i = num1.size()-1;i>=0;--i){
            for(int j = num2.size()-1;j>=0;--j){
                int mul = (num1[i]-'0') * (num2[j]-'0');
                int p1 = i+j,p2 = i+j+1;
                res[p1] += mul / 10;
                res[p2] += mul % 10;
            }
        }
        //每个位都可能保存了大于10的数，一次性进位即可
        int carry = 0;
        for(int i = res.size()-1;i>=0;--i){
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
        }
        string r;
        for(auto i:res){
            if(r.empty() && i == 0)continue;//避免前面的0
            r += i+'0';
        }
        return r.empty()?"0":r;
    }
};
```