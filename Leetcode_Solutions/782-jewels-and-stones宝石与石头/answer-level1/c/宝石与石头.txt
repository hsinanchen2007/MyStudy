### 解题思路
1 统计自己的石头每种有几个
2 把属于宝石种类的石头个数加起来

注意：释放申请的内存
### 代码

```c
int numJewelsInStones(char * J, char * S){
    int result=0;
    //利用ascll码表，建立一个整数数组，每个元素就是每种石头的个数，数组下标就是石头种类（char转换成的int）
    int *sum=(int *)malloc(sizeof(int)*123);
    int i;
    for(i=0;i<123;++i)
        sum[i]=0;
    //统计自己每类石头各有几个
    char *iter=S;
    while(*iter!='\0')
    {
        sum[(int)(*iter)]+=1;
        ++iter;
    }
    //根据“宝石列表”，直接加出自己的宝石数
    iter=J;
    while(*iter!='\0')
    {
        result+=sum[(int)(*iter)];
        ++iter;
    }

    free(sum);
    return result;

}
```