### 解题思路
先做vector是否是空的判断，空则返回""
遍历找到最短string
如果最短是0，返回""
再对每个字符串进行最小长度的比较，直到每个都相等，返回最终字符串

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        int len = 10000000;
        for(const auto& c: strs){
            if(len>c.size())
                len = c.size();
        }
        if(len == 0)
            return "";
        else{
            while(len){
                s = strs[0].substr(0, len);
                bool b = true;
                for(const auto c: strs){
                    if(s != c.substr(0, len))
                        b = false;
                }
                if(b) break;
                else len--;
            }
        } 
        return strs[0].substr(0, len);
    }
};
```