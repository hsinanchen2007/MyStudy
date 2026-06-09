### 解题思路
通过depth变量去探索最大深度，max记录。
因为需要将原数组拆成两个且和最小，那么就可以从深度
入手将最大深度低于max/2的都划分成B组，其中需要注意的是一些判定的条件
要保证（）是成对的拿到B中的
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int depth=0,max=0;
    int seqsize=strlen(seq);
    *returnSize=seqsize;
    for(int i=0;i<seqsize;i++)//确定最大深度
    {
        if(seq[i]=='(')
        depth++;
        else 
        depth--;
        if(depth>max)
        max=depth;
    }
    int *returnseq=(int *)calloc(seqsize,sizeof(int));
    depth=0;
    int a=0;
    for(int i=0;i<seqsize;i++)
    {
        if(seq[i]=='(')
        depth++;
        else 
        {
            if(seq[i-1]=='('&&returnseq[i-1]==1)
            {
                returnseq[i]=1;
                a++;
            }
            if(a%2)
            {
                returnseq[i]=1;
                a++;
            }
             depth--;
        }
        if(depth>(max/2+max%2))
        {
            returnseq[i]=1;
            a++;
        }
        
    }
    return returnseq;

}
```