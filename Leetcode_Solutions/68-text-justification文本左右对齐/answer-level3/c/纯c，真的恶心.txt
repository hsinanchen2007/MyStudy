### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct node
{
    int idx;
    int len;
}StrNode;

char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize){
    char** res=(char**)malloc(sizeof(char*)*(wordsSize+1));

    StrNode* strat=(StrNode*)malloc(sizeof(StrNode)*(wordsSize+1));
    int k=1;//start数组的下标
    int tmpWidth=0;
    int space=0;//空格数

    strat[0].idx=0;//将单词分组
    int i;
    for(i=0; i<wordsSize; i++)
    {
        tmpWidth+=strlen(words[i]);
        space++;
        if(tmpWidth+space>maxWidth+1)
        {
            strat[k-1].len=tmpWidth-strlen(words[i]);
            strat[k++].idx=i;
            tmpWidth=0;
            space=0;
            i--;
        }
    }
    strat[k-1].len=tmpWidth;
    strat[k].idx=wordsSize;

    int l=0;
    int j;
    for(i=0; i<k-1; i++)
    {
        res[i]=(char*)malloc(sizeof(char)*(maxWidth+1));
        int m=strat[i+1].idx-strat[i].idx;//此行单词个数
        int spacenum=maxWidth-strat[i].len;//此行所需空格个数
        
        if(m==1) m=2;
        int sn=spacenum%(m-1);
        int kg=m-1;
        for(j=0; j<maxWidth; )
        {
            //先插入单词
            int t=0;
            while(t<strlen(words[l]))
            {
                res[i][j]=words[l][t];
                j++;
                t++;
            }
            l++;
            if(j>=maxWidth) break;
            //插入空格
            
            int tmp_spacenum=spacenum/(m-1);
            int yushu=spacenum%(m-1);
            
            if(kg>0)
            {
                if(yushu==0||sn==0)
                {
                    while(tmp_spacenum>0)
                    {
                        res[i][j]=' ';
                        j++;
                        --tmp_spacenum;
                    }
                    kg--;
                }
                else
                {
                    while(tmp_spacenum>=0)
                    {
                        res[i][j]=' ';
                        j++;
                        --tmp_spacenum;
                    }
                    kg--;
                    sn--;
                }
            }
            
        }
        res[i][maxWidth]='\0';
    }

    //最后一行左对齐
    res[k-1]=(char*)malloc(sizeof(char)*(maxWidth+1));
    int num=strat[k].idx-strat[k-1].idx;//最后一行单词个数
    int s=wordsSize-num;//剩余单词的起始位置
    for(int j=0; j<maxWidth;)
    {
        if(s<wordsSize)
        {
            int t=0;
            while(t<strlen(words[s]))
            {
                res[k-1][j]=words[s][t];
                t++;
                j++;
            }
            s++;
        }  
        res[k-1][j++]=' ';
    }

    res[k-1][maxWidth]='\0';
    *returnSize=k;
    return res;
}
```