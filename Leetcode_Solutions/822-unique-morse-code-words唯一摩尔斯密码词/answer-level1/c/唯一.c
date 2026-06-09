考点：1、hash的理解
2、字符串函数的使用

int uniqueMorseRepresentations(char ** words, int wordsSize){
    char table[26][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                         "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
                         "..-","...-",".--","-..-","-.--","--.."};
    int len = 0;
    int count = 0;
    char **c = (char  **)malloc(100*sizeof(char*));
    for(int i = 0; i < wordsSize; i++)
    {
        len = strlen(words[i]);
        c[i] = (char *)malloc(len*sizeof(char)*5);
        memset(c[i],0,len*sizeof(char)*5);
        for(int j = 0 ; j <len; j++)
        {
            c[i] = strcat(c[i],table[words[i][j]-'a']);//table[words[i][j]-'a'] 简易的hash
        }
    }
    int flag[100] = {0};
    for(int i = 0; i < wordsSize; i++) //对当前的每个字符串和后面的字符串比较，如果出现将对应标志位置1，遇到1说明前面出现过就不统计
    {
        if(flag[i]==1){
            continue;
        }
        count++;
        for(int j = i+1;j<wordsSize;j++)
        {
            if(strcmp(c[i],c[j])==0)
            {
                flag[j] = 1;
            }
        }
    }
    for(int i = 0; i < wordsSize; i++)
    {
        free(c[i]);
    }
    free(c);
    return count;
}