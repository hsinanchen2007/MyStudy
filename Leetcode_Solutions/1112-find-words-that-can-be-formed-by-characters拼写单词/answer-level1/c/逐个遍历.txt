### 解题思路
此处撰写解题思路

### 代码

```c

int cacu(int *mapTmp, int *map)
{
    for(int i=0;i<26;i++)
    {
        if(mapTmp[i] != 0)
        {
            if(mapTmp[i] > map[i] )
            {
                return 0;
            }
        }
    }
    return 1;
}

int countCharacters(char ** words, int wordsSize, char * chars){

int map[26] ={0};
while(*chars != '\0') {
    map[*chars - 'a']++;
    chars++;
   
}

int len = 0;
int mapTmp[26]={0};
for(int i = 0; i < wordsSize;i++)
{
    char *p = words[i];
    while(*p != '\0')
    {
        mapTmp[*p-'a']++;
        p++;
         
    }
    if(cacu(mapTmp,map))
    {
        len+=strlen(words[i]);
    }
    memset(mapTmp,0,sizeof(mapTmp));
}
return len;
}
```