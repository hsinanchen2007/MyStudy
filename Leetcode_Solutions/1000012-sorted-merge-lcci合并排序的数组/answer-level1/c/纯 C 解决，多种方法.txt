### 解题思路
合并两个有序的数组，首先需要想到的就是二路归并算法对应的是方法一，只是要注意思考一下边界情况，元素个数为 $0$；

然后对于其中一个有序排序中插入数，那么我们可以想到折半插入排序，对应方法二；

两种方法时间复杂度都是 $O(N*N)$；

代码测试，后一种一般会更快，但是两种空间复杂度都是击败 $100%$。

```c [-方法一：二路归并算法]
//二路归并算法
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int indexA=-1,indexB=-1,indexT=-1;
    if(m==0)
    {
        while(indexB<n-1)
        A[indexB]=B[++indexB];
        return;
    }
    int temp[m];
    indexA=-1,indexB=-1,indexT=-1;
    int numA,numB;

    while(indexT<m-1)
        temp[indexT]=A[++indexT];
    printf("%d",temp[indexT]);    
    indexT=-1;
    while(indexT<m-1||indexB<n-1)
    {
        numA=(indexT<m-1)?temp[indexT+1]:3222222;
        numB=(indexB<n-1)?B[indexB+1]:3222222;
        if(numA<numB)
            A[++indexA]=temp[++indexT];
        else
            A[++indexA]=B[++indexB];
    }
}


```

```c [-方法二：折半插入排序]
//折半插入排序
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int low,high,mid;
    int temp;
    int i,j;
    
    for(i=0;i<n;i++)
    {
        low=0;
        high=m-1+i;
        temp=B[i];
        while(high>=low)
        {
            mid=(low+high)/2;
            if(A[mid]>temp)high=mid-1;
            else
            low=mid+1;;
        }
        for(j=m-1+i;j>=high+1;j--)//后移
        A[j+1]=A[j];
        A[high+1]=B[i];
    }
}
```
