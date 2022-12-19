### 解题思路
首先去除特殊情况：数组长度为0时输出空数组；

创建一个空数组ans；
遍历数组第一个元素字符串中指针为i的字符，对于数组中每一个字符串，当i大于数组元素字符串的长度或者该元素字符串的i位字符不等于第一个字符串中的i为字符时，直接输出当前的ans；
否则ans += strs[0][i];

最后输出ans即可


### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(); 
        string ans = "";
        if(n == 0) return ans;
        for(int i = 0; i < strs[0].size(); i++){
            for(int j = 0; j < n; j++){
                if(i >= strs[j].size() || strs[j][i] != strs[0][i]) return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};
```