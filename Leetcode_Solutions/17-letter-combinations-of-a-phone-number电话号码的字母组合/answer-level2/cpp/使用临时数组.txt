### 解题思路
感觉还有优化的空间，不知道为什么执行时间是0ms, 空间也击败100%, 惊了
就是使用两个临时的空间执行拓展，然后合并一下到结果，感觉不难

### 代码

```cpp
class Solution {
public:
    Solution(){
        digitMap['2'] = "abc";
        digitMap['3'] = "def";
        digitMap['4'] = "ghi";
        digitMap['5'] = "jkl";
        digitMap['6'] = "mno";
        digitMap['7'] = "pqrs";
        digitMap['8'] = "tuv";
        digitMap['9'] = "wxyz";
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res, tmp, tmp2;
        char num, extend;
        string alpha;
        if(digits.size() == 0) return res;
        alpha = digitMap[digits[0]];
        for(int j=0; j<alpha.size(); j++){
            // 初始化
            string p(1, alpha[j]);
            res.push_back(p);
        }
        for(int i=1; i<digits.size(); i++){
            tmp = res;
            res.clear();
            num = digits[i];
            alpha = digitMap[num];
            for(int j=0; j<alpha.size(); j++){
                tmp2 = tmp;  // 保存
                extend = alpha[j];
                for(int k=0; k<tmp2.size(); k++){
                    tmp2[k] += extend;  // 拓展
                }
                // 合并
                res.insert(res.begin(), tmp2.begin(), tmp2.end());
            }
        }
        return res;
    }
private:
    map<int, string> digitMap;
};
```