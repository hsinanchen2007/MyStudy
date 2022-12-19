### 解题思路
1.先检查是否有出现第一个字母是小写且第二个字母大写的情况，若是则直接返回false。
2.若步骤1通过的话，则检查除首字母外，若后面所有字母是否全为大写或全为小写则返回true，反则返回false。

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(islower(word[0]) && isupper(word[1])){
            return false;
        }
        int upCount = 0;
        for(int i = 1;i < word.length();i++){
            if(word[i] >= 65 && word[i] <= 92){
                upCount++;
            }
        }
        
        if(upCount == 0 || upCount == word.length() - 1){
            return true;
        }
        
        else{
            return false;
        }
    }
};
```