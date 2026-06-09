### 解题思路
sign[ ]记录字母表中每个字母出现的次数，temp[ ]记录每个单词中每个字母出现的次数.能拼出来就加上这个单词的长度。

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int result = 0;
        int sign[26] = {0,};
    for(int i=0;chars[i]!='\0';i++){
        sign[chars[i]-'a']++;
    }
    for(int i=0;i<wordsSize;i++){
        int temp[26] = {0,};
        int count = 0;
        for(int j=0;words[i][j]!='\0';j++){
            temp[words[i][j]-'a']++;
        }
        for(int j=0;j<26;j++){
            count += temp[j];
            if(temp[j] > sign[j]){
                count = 0;
                break;
            }
        }
        result += count;
    }
    return result;
}
```