```cpp
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void adjustdown(int *a,int len,int k)
{
    a[0]=a[k];
    for(int i=2*k;i<=len;i=2*i)
    {
        if(i<len&&a[i]<a[i+1]) i++;
        if(a[0]>=a[i]) break;
        else{
            a[k]=a[i];
            k=i;
        }
    }
    a[k]=a[0];
}
void buildmaxheap(int *a,int len)
{
    for(int i=len;i>0;i--)
    {
        adjustdown(a,len,i);
    }
}
void sort(int *a,int len)
{
    buildmaxheap(a,len);
    for(int i=len;i>1;i--)
    {
        a[0]=a[i];
        a[i]=a[1];
        a[1]=a[0];
        
        adjustdown(a,i-1,1);
    }
}
void dfs(int target,int *candidates,int candidatesSize,int *path,int depth,int first,int **result,int *resultSize,int *resultColumnSizes)
{
    for(int i=first;i<candidatesSize;i++)
    {
    
        
        //mark,path
          if(i>first&&candidates[i]==candidates[i-1]) continue;
        
        path[depth]=candidates[i];
        depth++;
        
        //result
        int sum=0;
        for(int j=0;j<depth;j++)
        {
            sum=sum+path[j];
        }
        if(sum==target)
        {
            result[*resultSize]=(int *)malloc(sizeof(int)*candidatesSize);
            for(int k=0;k<depth;k++)
            {
                result[*resultSize][k]=path[k];
                
            }
            resultColumnSizes[*resultSize]=depth;
            *resultSize=*resultSize+1;
        }
        
        //dfs
        if(sum<target&&depth<candidatesSize) dfs(target,candidates,candidatesSize,path,depth,i+1,result,resultSize,resultColumnSizes);
        depth--;
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int **result=(int **)malloc(sizeof(int *)*17000);
    int resultSize=0;
    int *path=(int *)malloc(sizeof(int)*candidatesSize);
    *returnColumnSizes=(int *)malloc(sizeof(int)*17000);
    
    int *heap=(int *)malloc(sizeof(int )*(candidatesSize+1));
    for(int i=0;i<candidatesSize;i++)
    {
        heap[i+1]=candidates[i];
    }
    sort(heap,candidatesSize);
    for(int i=0;i<candidatesSize;i++)
    {
      candidates[i]=heap[i+1];
    }
    
    dfs(target,candidates,candidatesSize,path,0,0,result,&resultSize,*returnColumnSizes);
    
    *returnSize=resultSize;
    return result;
}
```
组合
1元素可否重复使用,first+1和first.
2元素本身就有重复的，为了保证结果集不重复，在前边的基础上剪枝。若此元素不是同层孩子第一个且与前一个孩子值相同，则直接舍去，continue.
排列
用mark[]记录可用元素情况。只要同类元素一层只取其次就能保证结果不重复。
直接用swap更简单，不用mark和path.