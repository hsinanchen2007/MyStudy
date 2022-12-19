### 解题思路
只需要根据给出的 length 遍历原字符串中的“真实”长度，如果当前遍历到的字符不为空格，则直接添加到结果中，若为空格，添加"%20"到结果中。

### 代码

```cpp
class Solution {
public:
    string replaceSpaces(string S, int length) {
        string ans;
        for(int i = 0; i < length; i++){
            if(S[i] != ' ')
                ans.push_back(S[i]); // push_back a character to the end
            else{
                ans.append("%20"); //append a c-string to string
            }
        }
        return ans;
    }
};
```