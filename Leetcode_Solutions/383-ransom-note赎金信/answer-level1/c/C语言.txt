### 解题思路
两个数组存放字母出现的次数

### 代码

```c
bool canConstruct(char * ransomNote, char * magazine){
    int dictRan[26] = { 0 };
    int dictMag[26] = { 0 };
    for (int i = 0; i < strlen(ransomNote); i++) {
        dictRan[ransomNote[i] - 'a']++;
    }
    for (int i = 0; i < strlen(magazine); i++) {
        dictMag[magazine[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (dictRan[i] != 0) {
            if (dictRan[i] > dictMag[i]) {
                return false;
            }
        }
    }
    return true;
}
```