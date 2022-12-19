### 解题思路
注意题目要求的是每次拼写，char中每个字母只能用一次。
每个对于每个Word：
1. 先将『字母表』（字符串）存到**哈希表**
2. 在哈希表中寻找Word中**每个**字母，若找到，则将哈希表中该字母数量**减1**，若没找到，则说明不能组成这个单词

### 代码

```c
//将字符串存入哈希表
void mapCharacter(char* chars, char* characterMap) {
    memset(characterMap, 0, sizeof(char) * 26);
    for(int i = 0; chars[i] != '\0'; i ++) {
        characterMap[chars[i] - 'a'] ++;
    }
}

int countCharacters(char ** words, int wordsSize, char * chars){
    char characterMap[26] = {0};
    int count = 0;
    for(int i = 0, j = 0; i < wordsSize; i ++) {
        mapCharacter(chars, characterMap);
        j = 0;
        for(; words[i][j] != '\0'; j ++) {
            if(characterMap[words[i][j] - 'a'] == 0) {
                j = 0;
                break;
            }
            characterMap[words[i][j] - 'a'] --;
        }
        count += j;
    }
    return count;
}
```