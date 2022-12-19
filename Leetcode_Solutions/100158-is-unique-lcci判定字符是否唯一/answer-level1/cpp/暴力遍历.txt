### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        int len = astr.length();
        for(int i = 0; i < len-1; i++){
            for(int j = i+1; j < len; j++){
                if(astr[i] == astr[j])
                    return false;
            }
        }
        return true;
    }
};
```