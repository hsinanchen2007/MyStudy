### 解题思路
拼写每个单词的时候，可用字母是整张字母表，不是上一个拼写完剩下的字母。

### 代码

```c


int countCharacters(char ** words, int wordsSize, char * chars){

    //能拼成单词的字母数
    int result=0;
    //逐单词测试
    for(int row=0;row<wordsSize;++row)
    {   //建立字母表
        int table[26]={0};
        for(char* iter=chars;*iter!='\0';++iter)
            ++table[*iter-'a'];
        //每个单词逐字母测试
        for(int col=0;words[row][col]!='\0';++col)
            //如果单词的当前字母在字母表中有余量
            if(table[words[row][col]-'a']>0)
            {
                //字母表余量减一
                --table[words[row][col]-'a'];
                //计数器加一
                ++result;
            }
            else//如果当前单词在字母表中没有余量
                {//退回当前以及匹配的字母
                    while(--col>=0)
                    {
                        //余量加一
                        ++table[words[row][col]-'a'];
                        //计数器减一
                        --result;
                    }
                    //下一个单词
                    break;
                }
    }
    return result;
}


```