### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Temp
{
    int index;
    int temp;  
};

typedef struct Temp Temp;
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *ans = (int *)malloc(sizeof(T[0])*TSize);
    Temp *stack = (Temp *)malloc(TSize*sizeof(Temp));
    int i,top = -1;
    int n = 0;
    *returnSize = TSize;
    
    for(i=0;i<TSize;i++)    ans[i] = 0;
    i=0;
    while(i< TSize)
    {   
        if(top == -1 || T[i] <= stack[top].temp)
        {
            top++;
            stack[top].index = i;
            stack[top].temp = T[i];
            i++;
        }
        
        else if(top >= 0 && T[i] > stack[top].temp)
        {   
            top++;
            for(;top >= 0 && T[i] > stack[top-1].temp ; )
            {
                ans[stack[top-1].index] = i - stack[top-1].index ;
                top --;
                if(top == 0)    break;
            }
            stack[top].index = i;
            stack[top].temp = T[i];
            //n = 0;
            i++;
        }
    }
    return ans;
}
```