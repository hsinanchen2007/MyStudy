### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseOnlyLetters(string S) {
        string s1("");
        //从后往前保存 S 中的字母
        for(int i = S.length() - 1; i >= 0; i--)
        {
            
            if(S[i] >= 'a' && S[i] <= 'z' || S[i] >= 'A' && S[i] <= 'Z')
                s1.push_back(S[i]);//添加字符到s中，用push_back();
        }
        //反转字符串
        for(int i = 0, k = 0; i < S.length(); i++)
        {
            if(S[i] >= 'a' && S[i] <= 'z' || S[i] >= 'A' && S[i] <= 'Z')
                S[i] = s1[k++];
        }
        return S;
    }
};
```