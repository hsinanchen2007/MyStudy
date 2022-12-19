### 解题思路
两数相加大于目标值，右指针往左移；两数相加小于目标值，左指针往右移

执行用时 :8 ms, 在所有 C 提交中击败了82.72%的用户
内存消耗 :6.5 MB, 在所有 C 提交中击败了100.00%的用户
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){

    int *result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int left = 0;
    int right = numbersSize - 1;
    
    while(left < right){
        
        if(numbers[left] + numbers[right] == target){

            result[0] = left + 1;
            result[1] = right + 1;
            break;
        }
        else if(numbers[left] + numbers[right] > target){
                
            right--;
        }else{
                
            left++;
        }
    }
    
    return result;
}
```