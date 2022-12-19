### 解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
8.3 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string rt = strs[0];
        for(string s : strs){
            while(s.substr(0, rt.size()) != rt){
                rt = rt.substr(0, rt.size()-1);
                if(rt == "") return "";
            }
        }
        return rt;

    }
};
```