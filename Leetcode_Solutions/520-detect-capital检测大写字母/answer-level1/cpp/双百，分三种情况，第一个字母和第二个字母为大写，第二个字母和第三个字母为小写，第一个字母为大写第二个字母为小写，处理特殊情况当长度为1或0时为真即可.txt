### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        
if(word.size()==1||word.empty())return true;
         int k=1;
        if(isupper(word[0])){
        {
           
            if(isupper(word[1])){
                while(k<word.size()&&isupper(word[k]))k++;
                if(k==word.size())return true;
                return false;
            }else{
                while(k<word.size()&&islower(word[k]))k++;
                if(k==word.size())return true;
                return false;
            }
        }
        }else{
            while(k<word.size()&&islower(word[k]))k++;
            if(k==word.size())return true;
            return false;
        }
        
    }
};
```