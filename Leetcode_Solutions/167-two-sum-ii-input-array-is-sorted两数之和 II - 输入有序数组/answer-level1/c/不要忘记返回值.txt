### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *res = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    int i = 0;
    int j = numbersSize - 1;
    
    while(i < j){
        if(numbers[i] + numbers[j] == target){
            res[0] = i + 1;
            res[1] = j + 1;
            return res;
        }else if(target > numbers[i] + numbers[j]){
            i++;
        }else{
            j--;
        }
    }

    return NULL;
}
```