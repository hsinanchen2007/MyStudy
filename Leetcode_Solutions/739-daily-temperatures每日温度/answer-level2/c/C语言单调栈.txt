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
    *returnSize = TSize;
    Temp* stack = (Temp*)malloc(sizeof(Temp) * TSize);
    int *ret = (int*)malloc(sizeof(int) * TSize);
    int i;
    for(i = 0; i < TSize; i++) {
        ret[i] = 0;
    }
    int top = -1;
    i = 0;
    while(i < TSize) {
        if(top < 0 || T[i] <= stack[top].temp) {
            top++;
            stack[top].temp = T[i];
            stack[top].index = i;
            i++;
        } else if (top >= 0 && T[i] > stack[top].temp) {
            top++;
            while(T[i] > stack[top - 1].temp) {
                ret[stack[top - 1].index] = i - stack[top - 1].index;
                top--;
                if(top == 0) {
                    break;
                }
            }
            stack[top].temp = T[i];
            stack[top].index = i;
            i++;
        }
    }
    return ret;
}
```