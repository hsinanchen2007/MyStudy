### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        map<char,int> flag;
        int length = astr.length();
        for (int i = 0; i < length; i++)
        {
            flag[astr[i]] = flag[astr[i]] + 1;
            if (flag[astr[i]] != 1){
                return false;
            }
        }
        return true;
    }
};
```