### 解题思路
双指针法
1. typed 的index 一直增加，不同时name的指针不动，同时比较前一个值是否相同（防止题目挖坑）
2. 结束时看看name指针是否指向结尾即可

### 代码

```cpp
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int iName = 0, iTyped = 0;
        while(iTyped < typed.size()){
            if(iName < name.size() && name[iName] == typed[iTyped]) ++iName;
            else{
                if(!(iName > 0 && name[iName - 1] == typed[iTyped])) return false;
            }
            ++iTyped;
        }
        if(iName != name.size()) return false;
        else return true;
    }
};
```