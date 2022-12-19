### 解题思路
通过双重遍历检查字符串。利用一个count变量来计数，检查是否同一位置上的所有字符都一样，一旦发现某个位置不同，直接跳出循环，节省时间。

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return "";
        int strlen = strs[0].size();
        int len = strs.size();
        string ans;
        
        for(int i = 0 ; i < strlen ; i++){
            int count = 0;
            for (int j = 1 ; j < len ; j++){
                if(strs[j][i]==strs[0][i])++count;
            }
            if (count==len-1)ans.insert(i,1,strs[0][i]);
            else break;//save time
        }
        return ans;
    }
};
```