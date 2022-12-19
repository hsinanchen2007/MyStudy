首先，构造一个short数组characters，长度为26，用于储存chars中每个字母的数目。接着遍历words二维数组，每次开始前复制前面的数组，复制的数组为copied，对于每个单词，碰到一个字母就在copied中对应字母减一，减到小于零时，说明不能构成这个单词，能遍历到这个单词结尾说明可以构成，遍历到末尾的坐标即是该单词长度。

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    short characters[26]={0};
    short i=0,j,length=0;
    while(chars[i]!=0){
        characters[chars[i]-97]++;
        i++;
    }
    short copied[26];
    for(i=0;i<wordsSize;i++){
        for(j=0;j<26;j++)
            copied[j]=characters[j];
        j=0;
        while(words[i][j]!=0){
            copied[words[i][j]-97]--;
            if(copied[words[i][j]-97]<0) break;
            j++;
        }
        if(words[i][j]!=0) continue;
        else length=length+j;
    }
    return length;
}
```