### 解题思路
![图片.png](https://pic.leetcode-cn.com/289d94334e63462583e8abe5e04a417e881c51ecc014ec5593b9a2fef89184b4-%E5%9B%BE%E7%89%87.png)
核心思想：
声明大小为26的辅助数组，数组下标+'a'与字母对应，数组内容来统计chars中各个字母的个数。
每次遍历words[i]之前，都初始化一遍辅助数组。
遍历words[i]时，用元素words[i][j]作为辅助数组的下标去查找辅助数组元素，如果元素内容为0，就可以break了，很明显无法组成word[i]。如果不为0就减一，继续循环。
### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int output=0;
    int clen=strlen(chars);
    for(int i=0;i<wordsSize;i++){
        int alphbet[26]={0};
        for(int i=0;i<clen;i++){
            char c=chars[i];
            alphbet[c-'a']++;
        }
        int wslen=strlen(words[i]);
        int flag=0;
        for(int j=0;j<wslen;j++){
            char c=words[i][j];
            if(alphbet[c-'a']!=0){
                alphbet[c-'a']--;
            }else{
                flag=1;
                break;//组成不了
            }
        }
        if(flag==0){
            output+=wslen;
        }
    }
    return output;
}
```