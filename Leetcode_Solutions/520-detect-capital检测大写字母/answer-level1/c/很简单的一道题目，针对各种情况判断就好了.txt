### 解题思路
此处撰写解题思路

### 代码

```c
bool isAllLarge(char *word)
{
    int i = 0;
    while(word[i] != '\0') {
        if (!(word[i] >= 'A' && word[i] <= 'Z')) {
            return false;
        }
        i++;
    }
    return true;
}

bool isAllLittle(char *word)
{
    int i = 0;
    while(word[i] != '\0') {
        if (!(word[i] >= 'a' && word[i] <= 'z')) {
            return false;
        }
        i++;
    }
    return true;
}

bool isNormal(char *word)
{
    int i = 1;
    while(word[i] != '\0') {
        if (!(word[i] >= 'a' && word[i] <= 'z')) {
            return false;
        }
        i++;
    }
    return true;
}

bool detectCapitalUse(char * word){
    bool res = false;

    if (word[0] >= 'A' && word[0] <= 'Z') {
        res |= isAllLarge(word);
        res |= isNormal(word);
    }
    else {
        res |= isAllLittle(word);
    }

    return res;
}
```