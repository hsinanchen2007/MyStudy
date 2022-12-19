### 解题思路
1.因为只有第一个节无需特别格式因此从后往前遍历字符串，按照格式规则压入result，再将result逆序化返回即可。

### 代码

```cpp
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        if (S.size() <= 0 || K <= 0){
            return S;
        }
        
        string result;
        //Format Segment
        int count = 0;
        for (int i = S.size() - 1; i >= 0; --i){
            if ('-' == S[i]) { continue; }
            if (K == count){
                result += '-';
                count = 0;
            }
            result += toupper(S[i]);
            count++;
        }

        //reverse
        reverse(result.begin(), result.end());
        return result;
    }
};
```