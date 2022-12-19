### 解题思路
else if(word[1]>='a'){
                   if(i<word.size()-1&&word[i+1]<='Z') return false;
                    注意加个i的限制条件，这个时候i必须从1开始遍历
### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()<1) return true;
        for(int i=0;i<word.size();i++){
            if(word[0]>='a'){
                if(word[i]<'a') return false;
            }
            else if(word[0]<='Z'){
                if(word[1]<='Z'){
                    if(word[i]>'Z') return false;
                }
                else if(word[1]>='a'){
                   if(i<word.size()-1&&word[i+1]<='Z') return false;
                } 
            }
        }
        return true;
    }
};
```