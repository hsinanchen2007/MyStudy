### 解题思路
用一个标记数组来记录每个word是否在编码中，每个没处理的词拿来依次和前面在编码中的word进行比较处理，看新词是否是编码中某个word的尾缀，
如果新词是编码中的词的尾缀，不计算长度，新词标记为不在编码中。
如果编码中的词是新词的尾缀，则新词标记为在编码中，旧词标记为不在编码中，编码长度加上两词之差。
如果以上两种关系都不成立，则把新词标记在编码中，编码长度加上新词长度

### 代码

```c
bool isTail(char *longstr,char *shortstr,size_t longlen,size_t shortlen)
{
    while(shortlen>0)
    {
        if(*(longstr+longlen-1)!=*(shortstr+shortlen-1))
        {
            return false;
        }
        longlen--;
        shortlen--;
    }
    return true;
}

int minimumLengthEncoding(char ** words, int wordsSize){
    bool isNotTail[wordsSize];//标记一下完整的存在于编码中的字符串
    size_t lenOfStrs[wordsSize];
    int ans=0;
    int numOfEncodingStrs=0;
    for(int i=0;i<wordsSize;i++)
    {
        bool hadDownFlag=false;
        size_t ilen=strlen(words[i]);
        lenOfStrs[i]=ilen;
        for(int j=0;j<i;j++)
        {
            if(isNotTail[j])
            {
                size_t jlen=lenOfStrs[j];
                
                if(jlen==ilen)
                {
                    if(strcmp(words[i],words[j])==0)
                    {
                        isNotTail[i]=false;
                        hadDownFlag=true;
                        break;
                    }
                }
                else if(jlen>ilen)
                {
                   // printf("jl>il\n");
                    if(isTail(words[j],words[i],jlen,ilen))
                    {
                        isNotTail[i]=false;
                        hadDownFlag=true;
                        break;
                    }
                }
                else //if(jlen<ilen)
                {
                    if(isTail(words[i],words[j],ilen,jlen))
                    {
                        ans+=ilen-jlen;
                        isNotTail[j]=false;
                        isNotTail[i]=true;
                        hadDownFlag=true;
                        break;
                    }
                }
            }
        }
        if(!hadDownFlag)
        {
            isNotTail[i]=true;
            numOfEncodingStrs++;
            ans+=ilen;
        }
       // printf("%s\n",words[i]);
    }
    ans+=numOfEncodingStrs;
    return ans;
}
```