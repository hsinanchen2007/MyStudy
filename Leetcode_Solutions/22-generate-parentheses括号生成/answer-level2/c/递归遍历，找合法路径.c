### 解题思路
找合法路径，递归实现，复杂度ok，内存稍大。result可以用链表代替，但估计优化不了太多
open --- closed暂时不配对没关系，走到底再看
open  <= closed后续无法补救，该分支无须继续

执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :11.7 MB, 在所有 C 提交中击败了70.83%的用户

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_COMBINATION (1500) 

// 遍历树, 找到符合要求的路径
/*
                          (
                    ((         ()
                (((   (()   ()(    x())x
                ......
*/

void conbinations(int open, int closed, int n,char* parenthese, int parenthese_index,char** result, int *returnSize)
{
    if(closed == n)
    {
        // 路径结束
        parenthese[parenthese_index] = '\0';
        result[*returnSize] = (char *)malloc(2 * n + 1);   
        //strncpy_s(result[(*returnSize)++], 2 * n + 1, parenthese, 2 * n + 1);
        strcpy(result[(*returnSize)++],parenthese);
        return;
    }

    if(open < n){
        parenthese[parenthese_index] = '(';
        conbinations(open + 1, closed, n, parenthese, parenthese_index + 1, result, returnSize);
    }

    //open  <= closed则该节点及其子孙都为非法路径，不需要遍历
    if(closed < n && open > closed){
        parenthese[parenthese_index] = ')';
        conbinations(open, closed + 1, n, parenthese, parenthese_index + 1, result, returnSize);
    }
    return;
}

 // 遍历树, 找到符合要求的路径
char ** generateParenthesis(int n, int* returnSize){
    char *parenthese = (char *)malloc(2 * n + 1); // +1 for '\0'
    char **result = (char **)malloc(sizeof(char *) * MAX_COMBINATION);

    // init
    memset(result, 0, 2*n+1);
    *returnSize = 0;

    conbinations(0, 0, n, parenthese, 0, result, returnSize);

    free(parenthese);
    return result;
}
```