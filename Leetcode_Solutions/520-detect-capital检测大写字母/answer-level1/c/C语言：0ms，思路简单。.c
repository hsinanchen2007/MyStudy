![1.png](https://pic.leetcode-cn.com/35a07fa4304464a048f77308b65464d2f4932c5518a5fe3134a6ef4d7447e625-1.png)

**思路**
1. word[0]是小写，后面有大写字母，return false;
2. word[0]是大写，后面大写字母和小写字母都有，return false;
3. 否则，return true.
```
bool detectCapitalUse(char * word){
    int capital = 0;
    int lowercase = 0;
    if (word[0] >= 'A' && word[0] <= 'Z'){
        for (int i = 1; i < strlen(word); i++){
            if (word[i] >= 'a' && word[i] <= 'z'){
                capital = 1;
            }
            if (word[i] >= 'A' && word[i] <= 'Z'){
                lowercase = 1;
            }
        }
    }
    else{
        for (int i = 1; i < strlen(word); i++){
            if (word[i] >= 'A' && word[i] <= 'Z'){
                return false;
            }
        }
    }
    if (capital && lowercase)
        return false;
    return true;
}
```
