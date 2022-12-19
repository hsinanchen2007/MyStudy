1. 因为arr[i]的范围是给定了的，所以可以用此方法。
2. count1[]中最多只有arrSize个不为0的数，所以只用给count2[]申请arrSize个空间
3. count1[]用于记录各个数出现的次数；count2[]用于记录次数的个数
![3.png](https://pic.leetcode-cn.com/c08077b32c15e093937916c01e8150096168790d821d5e385ddd9174df62c2fc-3.png)

```
bool uniqueOccurrences(int* arr, int arrSize){
    int i,j;
    bool temp=true;
    int *count1=(int *)malloc(sizeof(int)*2001);
    memset(count1,0,sizeof(int)*2001);
    int *count2=(int *)malloc(sizeof(int)*(arrSize+1));//数组最长的情况就是arr数组中的每个数都不一样，count且最大数为arrSize
    memset(count2,0,sizeof(int)*(arrSize+1));
    for(i=0;i<arrSize;i++){
        if(arr[i]>=0)
            count1[arr[i]]++;
        else
            count1[arr[i]+2000]++;
    }
    for(j=0;j<2001;j++){
        if(count1[j]>0)
            count2[count1[j]]++;
        if(count2[count1[j]]>1)
            temp=false;
    }
    free(count1);
    free(count2);
    return temp;
}
```
