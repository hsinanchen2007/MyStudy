### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j=0;
        for(int i=0;i<name.length();i++){
            if(name[i]==typed[j]){
                j++;
                continue;
            }
            else{
                while(j<typed.length()&&name[i]!=typed[j]){
                    j++;
                }
                if(j==typed.length()){
                    return false;
                }
                j++;
            }
        }
        return true;
    }
};
```