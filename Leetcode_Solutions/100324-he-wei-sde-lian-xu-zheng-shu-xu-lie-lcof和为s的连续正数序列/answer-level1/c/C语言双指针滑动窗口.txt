### 解题思路

思路就是官方题解的方法三，题目不难主要是有几处细节需要注意。比如从这道题理解了用C语言刷题的时候为什么函数会出现returnSize这个形参。由于C语言申请动态数组必须设定数组大小，比如本题的（target/2）比如二叉树层序遍历那道题中的MAXSIZE。但是定义完大小之后，返回数组又不一定用的了这么大的空间。所以就需要有一个变量来告诉函数应该返回多大的数组，也就是returnSize的作用。
![捕获.PNG](https://pic.leetcode-cn.com/b345b0e9e4693cfee99337ade859e6a84138005aa4b715a9f4ef8f3a86ccc1c2-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */





int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes)
{
    int** ans=(int**)malloc(sizeof(int*)*(target/2));
    * returnColumnSizes=(int*)malloc(sizeof(int)*(target/2));
    int l=1;int r=2;
    int i=0;
    int val=0;
    while(l<r)
    {
        int sum=(l+r)*(r-l+1)/2;
        if(sum==target)
        {
            ans[i]=(int*)malloc(sizeof(int)*(r-l+1));
            val=l;
            for(int j=0;j<(r-l+1);j++)
            {
                ans[i][j]=val;
                val++;
            }
            (*returnColumnSizes)[i]=r-l+1;
            i++;
            l++;   
        }
        else if(sum<target) r++;
        else l++;
    }
    *returnSize=i;
    return ans;
}
```