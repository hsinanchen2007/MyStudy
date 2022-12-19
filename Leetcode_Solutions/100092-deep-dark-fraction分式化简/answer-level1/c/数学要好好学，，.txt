### 解题思路
首先找到分子分母值的规律，想要用一个公式直接一步计算，可是算了好久，发现好像找不到，所有就从每一个计算中找相同，从之前的评论中发现不需要约分，当然，如果需要，可以加一个辗转相除，

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int *p;
int* fraction(int* cont, int contSize, int* returnSize){
   int m,i;
   if(contSize>=2)
   {
       int m,i;
   p=(int*)malloc(sizeof(int)*2);
   p[0]=cont[contSize-1];
   p[1]=cont[contSize-1]*cont[contSize-2]+1;
   for(i=contSize-2;i!=0;i--)
   {
    m=p[0];
    p[0]=p[1];
    p[1]=m+p[1]*cont[i-1];
   }
    m=p[0];p[0]=p[1];p[1]=m;
   }
   else
   {
    p[0]=cont[0];  
    p[1]=1;
   }
    *returnSize=2;
    return   p;
}
```