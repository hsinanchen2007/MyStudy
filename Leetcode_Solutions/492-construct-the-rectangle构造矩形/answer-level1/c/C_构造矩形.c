### 解题思路
开方，然后递减，直到整除
开放调用库函数。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize){
    *returnSize = 2;
    int *result = malloc(sizeof(int) * *returnSize);
    result[1] = (int)sqrt(area);
    while(result[1])
    {
        if(area % result[1] == 0)
        {
            result[0] = area / result[1];
            return result; 
        }
        result[1]--;        
    }
    return NULL;
}
```