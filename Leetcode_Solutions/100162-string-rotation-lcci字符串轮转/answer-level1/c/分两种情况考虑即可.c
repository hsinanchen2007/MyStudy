### 解题思路

![image.png](https://pic.leetcode-cn.com/b4e1119165a7c825c2ad48211b9aae7160532288accce19cc1fe7cca3df43863-image.png)

### 代码

```c
bool isFlipedString(char* s1, char* s2){
    int lens1 = strlen(s1);
    int lens2 = strlen(s2);
    if (lens1 < 0 || lens1 > 100000 || lens2 < 0 || lens2 > 100000) {
        return false;
    }
    if (lens1 == 0 && lens2 == 0) {
        return true;
    }
    int table1[26] = {0};
    int table2[26] = {0};
    if (lens1 != lens2) {
        return false;
    } else {
        for (int i = 0; i < lens1; i++) {
            table1[tolower(s1[i])-'a']++;
            table2[tolower(s2[i])-'a']++;
        }
        int i = 0;
        for (i = 0; i < 26; i++) {
            if (table1[i] != table2[i]) {
                return false;
            }
        }
        if (i == 26) {  //总是忘了等于len,老是想着等于len-1!!!!!
            return true;
        }
    }
    return false;
}
```