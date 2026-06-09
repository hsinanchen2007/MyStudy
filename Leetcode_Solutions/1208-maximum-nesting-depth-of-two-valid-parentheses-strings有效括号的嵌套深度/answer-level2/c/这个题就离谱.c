### 解题思路
这个题看懂了是真不容易，我说一下我的想法
1.首先给你的字符全是'('和')'或者是''，所以就不用去纠结其他的
2.你需要干的就是给这些括号们分组
比如(((())))编号就是12344321，然后找到最大深度4除个2
这样就把它分为两组（1221和3443）
3.再另取一个同样长的储存空间，把深度低于最大深度一半的括号全部赋值为0，大于的存为1
4.最后返回这个新的储存空间就完成了


我的解法几乎是完全照抄大神的，两次遍历就行了，不用第三次
也学习了calloc和malloc的不同，前者开辟空间后全部赋值为0后者随机赋值

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAX(a,b) ((a)>(b)?(a):(b))
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int len=strlen(seq),d=0,dmax=0;
    int *depth=(int *)calloc(len,sizeof(int));
    for(int i=0;i<len;i++)
    {
        if(seq[i]=='(')
        {

        d++;
        depth[i]=d;
        dmax=MAX(dmax,d);
        }
        else
        {
           depth[i]=d;
           d--; 
        }
    }
    int hdepth=dmax/2;
    for(int i=0;i<len;i++)
    {
        if(depth[i]<=hdepth)depth[i]=0;
        if(depth[i]>hdepth)depth[i]=1;
    }
    *returnSize = len;
    return depth;
}
```