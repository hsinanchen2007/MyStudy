### 解题思路
将所有数字出现过的数字统计在一个数组count中，为节约内存，做了归一化，数组大小max-min+1。这个问题也就是将count数组中大于1的值摊到右侧为0的地方。
考虑这样一个问题，数组[1,2,2,2,3]经过操作之后的结果应该是[1,2,3,4,5]，一次递增操作其实也就是给数组所有数字的和+1，那我们只要把原数组所有数字求和得到acount，然后对数组进行min~ASize+min的累加得到bcount，然后将结果相减即可得出结果。注意特殊情况，如果数组是[1,2,2,2,10],那么结果是[1,2,3,4,10]，bcount的累加将是从中间断开的。这种情况说明count数组中的一段0完全足够左侧多余的数进行右移，判断这种情况只需要判断当前累加的值与count下标的关系（如10在count数组中的下标是9，而遍历到9时的累加值是4，这时将累加值置为9即可。

### 代码

```c
int maxnum(int* A, int Asize){
    int max=A[0];
    for(int i=1;i<Asize;i++)
    if(max<A[i]) max=A[i];
    return max;
}
int minnum(int* A, int Asize){
    int min=A[0];
    for(int i=1;i<Asize;i++)
    if(min>A[i]) min=A[i];
    return min;
}

int minIncrementForUnique(int* A, int ASize){
   if(ASize==0) return 0;
   int max=maxnum(A,ASize);
   int min=minnum(A,ASize);
   int size=max-size+1;
   int* count =(int*)calloc(size,sizeof(int));
   int plus=0;
   int acount=0;
   int bcount=0;
   for(int i=0;i<ASize;i++)
   count[A[i]-min]++;
   for(int i=0;i<size;i++){
        acount+=count[i]*i;    //在count中对数组求和
        for(int k=0;k<count[i];k++){
            bcount+=plus;      //计算累加的和
            plus++;            //计算累加值
        }
        if(plus<=i+1){
            plus=i+1;           //如果累加值小于下标+1 ，说明之前所有的0已经全部被填满，累加值需要跳跃
        }
   }
   return bcount-acount;
}
```