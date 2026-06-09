### 解题思路
因为c语言没有C++的hash map映射机制，所以需要使用c语言实现其hash。
![image.png](https://pic.leetcode-cn.com/5af69967b004e19e721693d214e6444b5821fb7e172df82227a16fcf63a3e0aa-image.png)


### 代码

```c
#define WORDLENGTH 20

typedef struct _tagHASHNODE
{
    char wordstr[WORDLENGTH]; /* key */
    int counter;
    UT_hash_handle hh;        /* handle */
}HASHNODE;

HASHNODE *g_hashNode = NULL;

void addWordIntoHashTable(char * wordsListHead)
{
    if( wordsListHead == NULL )
    {
        return;
    }

    char singleWord[WORDLENGTH] = {0};
    char *wordsListBegin = wordsListHead;
    char *wordsListEnd   = singleWord;
   
    while(isalpha(*wordsListBegin))
    {
        if(isupper(*wordsListBegin))
        {
            *wordsListBegin = tolower(*wordsListBegin);
        }
        *wordsListEnd++ = *wordsListBegin++;
    }

    HASHNODE * s = NULL;

    HASH_FIND(hh,g_hashNode,singleWord,sizeof(singleWord),s);

    if(s == NULL)
    {
        s = (HASHNODE*)malloc(sizeof(HASHNODE));
        memset(s,0,sizeof(HASHNODE));
 
        memcpy(s->wordstr,singleWord,WORDLENGTH);
        
        s->counter = 1;
        HASH_ADD(hh,g_hashNode,wordstr,sizeof(s->wordstr),s);
        
    }
    else
    {
        s->counter++;
    }

    return;
}

void addParagraphIntoHashTable(char *p)
{
    char *pHead = p;
    while(*pHead != '\0')
    {
        if(isalpha(*p))
        {
            p++;
        }
        else
        {
            addWordIntoHashTable(pHead);
            while(*p != '\0' && !isalpha(*p))
            {
                p++;
            }
            pHead = p;
        }
    }

    return;
}

void bannedHash(char *pHead)
{
    char singleWordtmp[WORDLENGTH] = {0};
    memcpy(singleWordtmp,pHead,strlen(pHead));
    HASHNODE * s = NULL;

    HASH_FIND(hh,g_hashNode,singleWordtmp,WORDLENGTH,s);

    if(s != NULL)
    {
        s->counter = 0;
    }

    return;
}

void clearHashTable()
{
    HASHNODE *curNode ,*tmp;
    HASH_ITER(hh,g_hashNode,curNode,tmp){
        HASH_DEL(g_hashNode,curNode);
        free(curNode);
    }
}
char * mostCommonWord(char * paragraph, char ** banned, int bannedSize){

    if(paragraph == NULL)
    {
        return NULL;
    }

    addParagraphIntoHashTable(paragraph);

    for(int i = 0;i < bannedSize;i++)
    {
        bannedHash(banned[i]); 
    }

    HASHNODE * s    = NULL;
    HASHNODE * tmp  = NULL;
    HASHNODE * sMax = NULL;

    HASH_ITER(hh,g_hashNode,s,tmp){
        if(sMax == NULL || sMax->counter <= s->counter)
        {
            sMax = s;
        }
    }

    int resLen = strlen(sMax->wordstr);
    char * res = (char *)malloc(sizeof(char)*(resLen+1));
    memset(res,0,sizeof(char)*(resLen+1));
    memcpy(res,sMax->wordstr,resLen);

    /* clear the hash table*/
    clearHashTable();

    return res;

}
```