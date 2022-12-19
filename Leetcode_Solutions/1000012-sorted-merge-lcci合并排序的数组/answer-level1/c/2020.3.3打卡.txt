### 解题思路
主要遇到一个坑和一个不能理解的地方。
坑：把ASize当成了m，怪自己没仔细看给的参数。
不能理解的地方：数组的指针不就是数组第一个元素的指针吗，为什么改变了A，却改变不了A[i]]呢(我知道不能改变A数组里的值，但是A这个指针都变了的话，相应的，A[i]不应该指向另一个地址的数了吗)，看来数组的原理不是我相信中的那样。

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    //printf("%d\n",ASize);
    int ABSize=ASize;
    ASize=ABSize-BSize;
    int ab[ABSize];
    int ia=0,ib=0,iab=0;
    int a,b;
    while(iab<ABSize)
    {
        if(ia<ASize)
        {
            a=A[ia];
        }
        else
        {
            a=INT_MAX;
        }

        if(ib<BSize)
        {
            b=B[ib];
        }
        else
        {
            b=INT_MAX;
        }
        if(a>b)
        {
            ab[iab++]=b;
            ib++;
        }
        else
        {
            ab[iab++]=a;
            ia++;
        }
    }
   // A=NULL;
    for(int i=0;i<ABSize;i++)
    {
        A[i]=ab[i];
   //printf("%d ",ab[i]);
    }
}
```