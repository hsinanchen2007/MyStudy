# 解1
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int (*array)[1000][1000], int *solution, int left_num, int *candidates, int candidatesSize, int position, int chosen_num)
{
    int i;
    for(i = chosen_num; i < candidatesSize && candidates[i] < left_num; i++){
        (*array)[*solution][position + 1] = candidates[i];
        dfs(array,solution,left_num - candidates[i],candidates, candidatesSize, position + 1,i);
    }
    if(i < candidatesSize && candidates[i] == left_num){
        (*array)[*solution][position + 1] = candidates[i];
        (*array)[*solution][0] = position + 1;
        (*solution)++;
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int i, j, tmp, k;
    for(i = 1; i < candidatesSize; i++){
        tmp = candidates[i];
        for(j = i-1; j >= 0 && candidates[j] > tmp; j--)
            candidates[j+1] = candidates[j];
        candidates[j+1] = tmp;
    }
    int array[1000][1000];
    int solution = 0;
    for(i = 0; i < 1000; i++)
        for(j = 0; j < 1000; j++)
            array[i][j] = 0;
    
    dfs(&array, &solution, target, candidates, candidatesSize, 0, 0);

    int **reval;
    *returnSize = solution;
    *returnColumnSizes = (int*)malloc(sizeof(int) * solution);
    reval = (int**)malloc(sizeof(int*) * solution);
    for(i = 0; i < solution; i++){
        (*returnColumnSizes)[i] = array[i][0];
        reval[i] = (int*)malloc(sizeof(int) * array[i][0]);
        for(j = 0; j < array[i][0]; j++){
            for(k = i; array[k][j+1] == 0; k--)
                continue;
            reval[i][j] = array[k][j+1];
        }
    }

    return reval;
}

```

# 解2
```
// #include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int i, j, tmp, k;
    int **reval;
    int solution = 0, top = 0, left_num = target;
    int array[1000][1000];
    int stack[1000][2];//stack[][0] is number, stack[][1] is the position
    for(i = 1; i < candidatesSize; i++){
        tmp = candidates[i];
        for(j = i-1; j >= 0 && candidates[j] > tmp; j--)
            candidates[j+1] = candidates[j];
        candidates[j+1] = tmp;
    }
    // insertation sort

    for(i = 0; i < candidatesSize || top > 0;){
        if(i >= candidatesSize || candidates[i] > left_num){
            while(i >= candidatesSize || candidates[i] > left_num){
                top--;
                if(-1 == top)
                    break;
                i = stack[top][1]+1;
                left_num += stack[top][0];
            }
            if(-1 == top)
                break;
        }else
            i = (top == 0) ? 0 : stack[top-1][1];

        left_num -= candidates[i];
        stack[top][0] = candidates[i];
        stack[top++][1] = i;

        if(0 == left_num){
            array[solution][0] = top;
            for(j = 0; j < top; j++)
                array[solution][j+1] = stack[j][0];
            solution++;
            top--;
            i = stack[top][1]+1;
            left_num += stack[top][0];
            // break;
        }
    }

    *returnSize = solution;
    reval = (int**)malloc(sizeof(int*) * solution);
    *returnColumnSizes = (int*)malloc(sizeof(int) * solution);
    for(i = 0; i < solution; i++){
        (*returnColumnSizes)[i] = array[i][0];
        reval[i] = (int*)malloc(sizeof(int) * array[i][0]);
        for(j = 0; j < array[i][0]; j++){
            reval[i][j] = array[i][j+1];
        }
    }
    return reval;
}

```

