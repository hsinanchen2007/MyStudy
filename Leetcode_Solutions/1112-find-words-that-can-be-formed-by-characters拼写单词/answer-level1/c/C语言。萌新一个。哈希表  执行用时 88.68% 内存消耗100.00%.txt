### 解题思路
萌新的代码。
执行用时 :32 ms
内存消耗 :8.2 MB
自己建一个简易哈希表，使用时-1，错误时还原。
确定一个词就加上长度。

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int len=strlen(words);
    int i,j,k,x,cnt,sum=0;
    int h[26],m[26];
    for(i=0;i<26;i++)
    {
        h[i]=0;
    }
    for(i=0;chars[i]!='\0';i++)
    {
        k=chars[i]-'a';
        h[k]++;
    }
    for(i=0;i<26;i++)
    {
        m[i]=h[i];
    }
    for(i=0;i<wordsSize;i++)
    {
        cnt=0;
        for(j=0;words[i][j]!='\0';j++)
        {
            k=words[i][j]-'a';
            if(h[k]>0)
            {
                cnt++;
                h[k]--;
            }
            else 
            {
                cnt=0;
                break;
            }
        }
        for(x=0;x<26;x++)
        {
            h[x]=m[x];
        }
        sum+=cnt;
    }
    return sum;
}
```