维护一个哈希表`char maps[]`，检测每个字符串中所有字符是否有相同的值
大小写字母之间的间隙填充六个0，这样不用转换大小写

当然，`maps` 也可以是字符串。

```C

char maps[] = 
{
    2, 3, 3, 2, 1, 2, 2,// a-g
    2, 1, 2, 2, 2, 3, 3, // h-n
    1, 1, 1, 1, 2, 1, // opqrst
    1, 3, 1, 3, 1, 3, // uvwxyz
    0,0,0,0,0,0, // padding
    2, 3, 3, 2, 1, 2, 2,// a-g
    2, 1, 2, 2, 2, 3, 3, // h-n
    1, 1, 1, 1, 2, 1, // opqrst
    1, 3, 1, 3, 1, 3, // uvwxyz
};

int canTypedInOneLine(char * word)
{
    if(*word == '\0') return true;
    int pos = maps[word[0]-'A'];
    int i = 1;
    for(; word[i]!='\0'; i++)
        if(maps[word[i]-'A'] != pos)
            return -1;
    return i;
}

char ** findWords(char ** words, int wordsSize, int* returnSize){
    int ri = 0, oi = 0;
    for(int len; oi < wordsSize; oi++)
    {
        len = canTypedInOneLine(words[oi]);
        if(len >= 0)
        {
            if(ri != oi)
            {
                words[ri] = malloc(len+1);
                for(int i = 0; i <= len;i++)
                    words[ri][i] = words[oi][i];
            }
            ri++;
        }
    }
    *returnSize = ri;
    return words;
}

```
