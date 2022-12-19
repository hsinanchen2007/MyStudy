### C++双指针
C++双指针

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string res="";
        int i=0;
        
        while(i<S.size()) {
            // 当前字符从1计数
            int count = 1;
            // 从前往后遍历，直到当前字符与后一个字符不相等
            while(i+1<S.size() && S[i] == S[i+1]) {
                count++;
                i++;
            }
            // 字符串累加结果
            res += S[i];
            res += to_string(count);
            // 跳到不相等字符或者说下一个字符
            i++;
        }
        // 压缩长度没有变短，就返回原先的字符串。
        return res.size() >= S.size() ? S : res;
    }
};
```