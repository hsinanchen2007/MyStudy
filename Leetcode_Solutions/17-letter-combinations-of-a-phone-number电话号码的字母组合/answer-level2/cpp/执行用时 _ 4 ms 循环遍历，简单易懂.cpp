### 解题思路
其实有一点dp的想法，result一直记录上一步的结果，用temp做中间变量计算现在结果
最后将temp赋值给result，继续下一次循环

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        vector<string> result;
        if(!len) return result;
        map<char,string> curr;
        curr['2'] = "abc";
        curr['3'] = "def";
        curr['4'] = "ghi";
        curr['5'] = "jkl";
        curr['6'] = "mno";
        curr['7'] = "pqrs";
        curr['8'] = "tuv";
        curr['9'] = "wxyz";
        for(int i = 0; i < len; i++){
            string now = curr[digits[i]];
            int n_len = now.size();
            int r_len = result.size();
            vector<string> temp;
            if(!r_len){
                for(int q = 0; q < n_len; q++){
                    string s;
                    s.push_back(now[q]);   //这里因为now[q]是char型，没法给添加进result，没想到好的转换方法
                    result.push_back(s);
                }
                continue;
            }
            for(int p = 0; p < r_len; p++)
                for(int q = 0; q < n_len; q++)
                    temp.push_back(result[p] + now[q]);
            result = temp;
        }
        return result;
    }
};
```