### 解题思路
思路很简单。
① ： 判断是否为空，为空直接返回
② ： 确定一个标准字符，用于比较(注意边界检查)
③ ： 用一个$for$循环进行查找，假如相同且没有访问越界则继续，否则直接return就好了
④ ： 假如该字符在这次这个$for$循环中没有出问题则直接加上

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        char ch;
        string ans;

        for (int i = 0;; ++ i){
            if(i < strs[0].size()) ch = strs[0][i];
            else return ans;

            for (auto& e : strs){
                if (i < e.size() && e[i] == ch)/*pass*/;
                else return ans;
            }
            ans += ch;
        }

        return ans;
    }
};
```