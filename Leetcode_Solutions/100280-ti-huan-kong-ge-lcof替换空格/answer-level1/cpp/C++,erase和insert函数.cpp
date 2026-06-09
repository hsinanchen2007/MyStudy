### 解题思路
采用s.erase(i, 1)除去空格，s.insert(i, "%20")插入“%20” 

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                s.erase(i, 1);          //抹去当前空格
                s.insert(i, "%20");     //在当前位置插入“%20”
            }
        }
        return s;
    }
};
```