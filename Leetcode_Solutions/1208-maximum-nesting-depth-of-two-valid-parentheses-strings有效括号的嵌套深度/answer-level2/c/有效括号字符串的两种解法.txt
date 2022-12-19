### 解题思路
以下方法都是参考了大佬们的，有不恰当的地方，烦请指出

 判断相邻的两个是否相同，这是因为要分配成深度最小，你品，字符串的深度是固定的，如果一个大，一个小，那么两者当中最大的还是大，要做到两者当中的最大值是最小的，就要求两者的深度相同，挥着顶多相差一个1
 
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
第一种方法就是一个个的分配深度，先给A，再给B，如果遇到两个符号不同，就说明是同一深度的，
如果两个符号相同，就说明不是同一深度的，这是应该给A,B轮流赋值
 */

int* maxDepthAfterSplit(char * seq, int* returnSize){
    int length = strlen(seq);
    int num = 0;
    *returnSize = length;
    int *ret = (int *)malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
    {
        if(i != 0 && seq[i] == seq[i-1])
        {
            num = 1 - num;
        }
            ret[i] = num;
    }
    return ret;
}
 
 
```c
/**
第二种方法就是先算出最大深度，并且记录下每个字符的深度，把前一半深度给A,后一般深度给B，这样，在最大深度确定的情况下，我们可以看到A，B当中最大的值此时应该是最小的，其实，第二种思路和第一种思路的原理都是一样的，只不过表达的方式不一样而已
 */

int* maxDepthAfterSplit(char * seq, int* returnSize){
    int length = strlen(seq);
    *returnSize = length;
    int *ret = (int *)malloc(sizeof(int)*length);
    int maxDeep = 0;//最大深度
    int nowDeep = 0;//当前深度
    for(int i = 0; i < length; i++)
    {
        if(seq[i] == '(')//如果深度在增加的话
        {
            nowDeep++;
            ret[i] = nowDeep;
            if(nowDeep > maxDeep)
            maxDeep = nowDeep;
        }
        else//如果深度在减少，或（）配对，深度没有增加
        {
            ret[i] = nowDeep;
            //ret[i] = nowDeep;语句要放在nowDeep--;前面
            //你想想，如果（（（到这里的时候，下一个‘）’是不是应该与上一个‘（’深度相同，
            //而如果下下个是‘）’则深度减小，如果下下个又变成‘）’，说明是维持原来的深度，
            //在上一个if语句里面一进去就nowDeep++了，显然就还原了）））
            //你品，你细品
            nowDeep--;
        }
    }
    int mid = maxDeep/2;
    //mid是中间深度
    for(int i = 0; i < length; i++)
    {
        if(ret[i] > mid)
        //注意，这里必须写上
        ret[i] = 1;
        else
        ret[i] = 0;
    }
    return ret;
}
```