### 解题思路
这个题目没啥好说的，就是硬着去遍历，一旦不匹配就返回。
下面的代码用了1个track去减小遍历时间：
    用min_val避免string内部的访问越界的问题。
    如果后续每次都用if(i < strs[j].size())去避免越界，if执行的次数是O(min_val*n)，n为strs.size()
    而提前算好min_val的cost是O(n)

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        int len = strs.size(), min_val = INT_MAX;
        for(int i = 0; i < len; ++i){
            min_val = min(int(strs[i].size()), min_val);
        }
        string res;
        for(int i = 0; i < min_val; ++i){
            for(int j = 1; j < len; ++j){
                if(strs[j][i] != strs[0][i]){
                    return res;
                }
            }
            res += strs[0][i];
        }
        return res;
    }
};
```

### 结果

执行用时 : 8 ms , 在所有 C++ 提交中击败了 59.64% 的用户 
内存消耗 : 6.9 MB , 在所有 C++ 提交中击败了 100.00% 的用户