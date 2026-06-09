### 解题思路
题目的意思，就是把`seq`分成两个部分，两部分深度之和低。
1. 计算每一个“（）”的深度，并记下最大深度$max$；
2. 深度小于（max/2）的为一组，剩下的为另一组。

因为分组时，就是把一部分有效字符拿出来，它的最小深度应当不高于max/2。
如果我想错了，一定要告诉我啊!
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int *deep;
    int i,tmp,max;
    tmp=0;max=0;
    for(i=0;seq[i];i++);
    deep=(int *)malloc(sizeof(int)*(i));
    for(i=0;seq[i];i++){
        if(seq[i]=='('){
            deep[i]=tmp;
            tmp++;
        }
        else{
            // tmp--;
            deep[i]=(--tmp);
        }
        max=(max>tmp)?max:tmp;
    }
    for(i=0;seq[i];i++){
        // printf("%d",deep[i]);
        if(deep[i]<max/2) deep[i]=0;
        else deep[i]=1;
    }
    *returnSize=i;
    return deep;
}
```