12行，性能还凑合，容易理解。
用`vector<string> res;`存储结果
递归结束条件：
当S为空串，递归结束，写入结果
递归中分三种情况：
1. 遇到的是数字，letter上添上这个数字继续递归
2. 遇到的是小写字母，letter上添加这个小写字母继续递归 + letter上添加这个大写字母继续递归
3. 遇到的是大写字母，letter上添加这个大写字母继续递归 + letter上添加这个小写字母继续递归
```
class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string S) {
        letterCase("", S);
        return res;
    }
    void letterCase(string letter, string S){
        if(S.size()==0)
        {
            res.push_back(letter);
            return;
        }
        char s = S[0];
        letterCase(letter+s, S.substr(1));
        if (s >= 'a' && s <='z')
        {
            letterCase(letter+char(toupper(s)), S.substr(1));
        }
        else if(s >= 'A' && s <='Z')
        {
            letterCase(letter+char(tolower(s)), S.substr(1));
        }
    }
    
};
```

