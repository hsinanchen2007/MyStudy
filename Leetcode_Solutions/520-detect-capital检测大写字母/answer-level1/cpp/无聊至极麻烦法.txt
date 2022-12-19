### 解题思路
将其视为哈夫曼树进行写程序，大写小写，大写大写，小写小写，10,11,00,不冲突01是错的，注意下前两位就OK

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        int len=word.size();
        if(len==1)
            return true;
        if(len==2){
            if(word[0]==word[1])
                return true;
            if(word[0]>'Z'&&word[1]<'a')
                return false;
        }
            
        for(int i=2;i<len;i++){
            if(word[0]>'Z'&&word[1]>'Z'){
                if(word[i]<'a')
                    return false;
            }
            else if(word[0]<'a'&&word[1]<'a'){
                if(word[i]>'Z')
                    return false;
                
            }
            else if(word[0]<'a'&&word[1]>'Z'){
                if(word[i]<'a')
                    return false;
            }
            else  
                return false;
        }
        return true;
    }
};
```