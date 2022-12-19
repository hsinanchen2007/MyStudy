### 解题思路


### 代码

```cpp
/*next_permutation（start,end），和prev_permutation（start,end）。这两个函数作用是一样的，区别就在于前者求的是当前排列的下一个排列，后一个求的是当前排列的上一个排列。至于这里的“前一个”和“后一个”，我们可以把它理解为序列的字典序的前后*/
class Solution {
public:
    vector<string> permutation(string s) {
        if(s.empty()) return {};
        sort(s.begin(), s.end());
        vector<string> ans;
        ans.push_back(s);
        while(next_permutation(s.begin(), s.end())){
            ans.push_back(s);
        }
        return ans;
    }
};
```