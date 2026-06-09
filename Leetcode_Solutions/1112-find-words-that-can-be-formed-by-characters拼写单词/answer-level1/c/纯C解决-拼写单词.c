### 解题思路
此处撰写解题思路

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int hash[26];//记录每个元素的个数
    memset(hash,0,sizeof(int)*26);
    int temp_hash[26];
    int length_c=strlen(chars);
    int length;

    //填充hash表
    int i;
    for(i=0;i<length_c;i++)
    hash[chars[i]-'a']++;

    int result=0;
    int j;
    for(i=0;i<wordsSize;i++)
        {
            memcpy(temp_hash,hash,sizeof(int)*26);
            length=strlen(*(words+i));
            for(j=0;j<length;j++)
            {
                int num=*(*(words+i)+j)-'a';
                if(temp_hash[num]==0)
                break;
                temp_hash[num]--;
            }
            if(j==length)
            result+=length;
            //printf("%s\n",words[i]);}
        }
    return result;
}
```