```cpp
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comfunc(const void *p1,const void *p2)
{
    return (*(int*)p1)-(*(int*)p2);
}
void dfs(int depth,int *nums,int numsSize,int **ret,int *retSize,int *mark,int *path)
{
    for(int i=0;i<numsSize;i++)
    {
        //path,mark;
        if(mark[i]==0) continue;
        if(i>0&&nums[i]==nums[i-1]&&mark[i-1]==1) continue;
        
        mark[i]=0;
        path[depth]=nums[i];
        depth++;
        
        //result
        if(depth==numsSize)
        {
            ret[*retSize]=(int *)malloc(sizeof(int)*numsSize);
            for(int i=0;i<numsSize;i++)
            {
                ret[*retSize][i]=path[i];
            }
            *retSize=*retSize+1;
        }
        
        //dfs
        if(depth<numsSize) dfs(depth,nums,numsSize,ret,retSize,mark,path);
        depth--;
        mark[i]=1;
        
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums,numsSize,sizeof(int),comfunc);
    int **ret=(int **)malloc(sizeof(int*)*17000);
    int retSize=0;
    int *mark=(int *)malloc(sizeof(int)*numsSize);
    int *path=(int*)malloc(sizeof(int)*numsSize);
    dfs(0,nums,numsSize,ret,&retSize,mark,path);
    
    *returnSize=retSize;
    *returnColumnSizes=(int *)malloc(sizeof(int)*retSize);
    for(int i=0;i<retSize;i++)
    {
        (*returnColumnSizes)[i]=numsSize;
    }
    return ret;
}

```
1还是用老方法吧，用swap虽然节省了一些参数。但是这一题就解决不了，有重复元素的要排序剪枝，但swap会打乱顺序。
2重复元素排列的剪枝，i>0&&nums[i]==nums[i-1]&&mark[i-1]==1.为1的是当前层可用节点，即兄弟节点，若他们不可以相等.
子集树的,i>depth&&nums[i]==nums[i-1],子集树的可用节点集中在一起，depth之后全可用。