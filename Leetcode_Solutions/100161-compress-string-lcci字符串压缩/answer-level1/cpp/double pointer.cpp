### 解题思路
此处撰写解题思路
easy题双指针
中间添加字符的时候，比如加入a11如果append一个a，一个11，这里有个小bug。字符10 + '0'不是10，想当然了，忽略了字符数大于9的时候

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        if (S.size() <= 1) return S;
        string tmp;
        int i = 0, j = 0;
        while (j < S.size()) {
            while (j < S.size() && S[i] == S[j]) j ++;
            // tmp.push_back(S[i]);
            //tmp.push_back(j - i + '0'); // when character count exceed 10, this will be wrong cause :
            tmp += S[i] + to_string(j - i);
            i = j;
        }
        return tmp.size() < S.size() ? tmp : S;
    }
};
```