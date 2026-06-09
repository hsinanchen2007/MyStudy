### 解题思路
构建两个辅助数组，使B[i] = C[i] * D[i].

辅助数组，C[i] = A[0] * A[1] * A[2] * ... * A[i-1],
         D[i] = A[i+1] * A[i+2] * ... * A[n-1],

![1.png](https://pic.leetcode-cn.com/3ad736f1ffdfcbb221d227708ba4f5fccd8c995983c0177620afc33ab8c26748-1.png)
此处撰写解题思路

### 代码

```c

int* constructArr(int* a, int aSize, int* returnSize){
    *returnSize = aSize;
    if(a == NULL || aSize == 0 || aSize == 1)
    {
        return a;
    }

    int* b = (int*)malloc(sizeof(int)*aSize);  
    int* c = (int*)malloc(sizeof(int)*aSize);
    int* d = (int*)malloc(sizeof(int)*aSize);

    memset(b,0,aSize*sizeof(int));
    memset(c,0,aSize*sizeof(int));
    memset(d,0,aSize*sizeof(int));

    c[0] = 1;

    for(int i=1;i<aSize;i++)
    {
        c[i] = a[i-1]*c[i-1];
    }
    
    d[aSize-1] = 1;
    for(int j=aSize-2;j>=0;j--)
    {
        d[j] = a[j+1] * d[j+1];
    }

    for(int i=0;i<aSize;i++)
    {
        b[i] = c[i] * d[i];
    }

    return b;
}   
```