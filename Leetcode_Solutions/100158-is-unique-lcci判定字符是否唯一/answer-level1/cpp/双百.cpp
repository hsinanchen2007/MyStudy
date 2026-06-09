### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        map<int,bool> m;
        for(int i=0;i<astr.size();i++){
            if(m[astr[i]]==true) return false;
            m[astr[i]]=true;
        }
        return true;
    }
};
```