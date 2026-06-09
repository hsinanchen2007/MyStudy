### 解题思路
先判断vector为空元素的情况，直接返回“”，这个很重要，刚做被卡在这里； 其次就是两个for循环，以第一个元素为基准，逐字符遍历，若每个元素都包含此字符，则push进临时字符串，最后返回此字符串

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string sub = "";
        int size = strs.size();
        if (size < 1) {
            return "";
        } 
        
        char tmp;
        int len = strs[0].length();

        for (int i = 0; i < len; i++) {
            tmp = strs[0][i];
            for (int j = 1; j < size; j++) {
                if (tmp != strs[j][i]) {
                    return sub;
                } 
            }
            sub.push_back(tmp);
        }

        return sub;
    }
};
```