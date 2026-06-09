### 解题思路

[1.两数之和](https://leetcode-cn.com/problems/two-sum)的输入是无序数组，同时要求你返回原来的下表，因此不能随便排序。除非你记录了排序前和排序后的对应关系，但这就把问题搞复杂了。

[15.三数之和](https://leetcode-cn.com/problems/3sum)输入的数组无序，但是只需你返回可能的组合数字，而不是下标，因此可以对数组进行排序。

而这道题目就是中间的缓冲，只不过他提前帮你排序了，因此直接用双指针，从前从后往中间迫近，就可以比用Map数据结构更快更省内存。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numbersSize, int target, int* returnSize){

    int *res = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int i = 0;
    int j = numbersSize - 1;
    while(true){
        if (nums[i] + nums[j] > target) {
            j--;
        } else if (nums[i] + nums[j] < target) {
            i++;
        } else{
            res[0] = i+1;
            res[1] = j+1;
            break;
        }
    }
    return res;

}
```