### 解题思路
此处撰写解题思路
只需要建立一个哈希表，若该字符已存在则直接返回false
### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        map<char,bool> count;
        for(char c:astr){
            if(count[c]==true) return false;
            count[c] = true;
        }
        return true;
    }
};
```