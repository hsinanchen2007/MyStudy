```
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int len1 = name.size();
        int len2 = typed.size();
        if (len1 > len2)
            return false;
        int i = 0;
        for (int j = 0; j < len2; j++){
            if (typed[j] == name[i]){
                i++;
            }
        }
        return i == len1;
    }
};
```