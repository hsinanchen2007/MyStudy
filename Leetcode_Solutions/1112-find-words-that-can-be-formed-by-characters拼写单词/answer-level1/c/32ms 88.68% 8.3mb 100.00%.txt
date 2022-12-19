### 解题思路
要注意的是chars的每个字符只能用一次是说对于你要写的每个单词中只能出现一次，不是说你要写的所有单词h中只能出现一次，比方说chars能单独写A和B两个单词，某个字母a在A和B中各出现一次，但chars中只有一个a，那么最终要返回的是A+B的长度，任意单词间互相不影响

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int a[26]={0};
    int i=0;
    while(chars[i]!=0){
        a[chars[i]-'a']++;
        i++;
    }
    int sum=0,j=0;
    for(i=0;i<wordsSize;i++){
        j=0;
        while(words[i][j]!=0){
            if(a[words[i][j]-'a']>0){
                a[words[i][j]-'a']--;
            }else{
                break;
            }
            j++;
        }
        if(words[i][j]==0){
            sum+=j;
        }
        j--;
        while(j>=0){
            a[words[i][j]-'a']++;
            j--;
        }
    }
    return sum;
}
```