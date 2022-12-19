### 代码

```cpp
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int len1 = name.size(),len2 = typed.size();
        if(len2 < len1) return false;
        int i = 0,j = 0;
        while(i < len1 && j < len2){
            if(name[i] != typed[j]) return false;
            else{
                while(i < len1 && name[i] == typed[j]){
                    i++;
                    j++;
                }
                while(j < len2 && typed[j] == typed[j-1]) j++;
                if(i < len1 && j >= len2) return false;
            }
        }
        return true;
    }
};
```