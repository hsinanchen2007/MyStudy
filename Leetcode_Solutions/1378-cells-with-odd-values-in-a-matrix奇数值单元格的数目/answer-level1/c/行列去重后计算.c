![image.png](https://pic.leetcode-cn.com/2924a401a7d8cb2da03051f300389714fdbb999b4bdc94546d66d69ea357959d-image.png)

1.去除重复的行与列（两次相同的行或者相同的列）
2.由1得一共a行个1，b列个1，计算公式（a*m+b*n-2*a*b）。前两项为行元素与列元素的累加。后一项为重复累计的元素（因为要去除掉，所以一共重复累计2次）
```
int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    int nn[50]={0};
    int mm[50]={0};
    int nlen=0,mlen=0,i;
    int *p=&indices[0][0];
    int *p1=nn;
    int *p2=mm;
    for(i=0;i<indicesSize;i++)
    {
        nn[indices[i][1]] ^= 1u;
        mm[indices[i][0]] ^= 1u;
    }
    i=50;
    while(i--)
    {
        nlen+=*p1++;
        mlen+=*p2++;
    }
    return (nlen*n+mlen*m-2*nlen*mlen);
}
```
