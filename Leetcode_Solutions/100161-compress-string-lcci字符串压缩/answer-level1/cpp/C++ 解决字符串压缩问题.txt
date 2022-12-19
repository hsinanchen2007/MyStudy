### 解题思路
此题不难。
1:空串的话返回空串。
2：要将count 转换为 string
3：最后比较压缩字符串和原字符串的大小

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        if(S.length() == 0) return S;
        string str = "";
        int count = 1;
        for(int i = 0;i< S.length(); i++){
            if(S[i] == S[i+1])
                count++;
            else{
                str += S[i] + to_string(count);
                count = 1;
            }
        }
        return str.length() >= S.length() ? S : str;
        }
};
```