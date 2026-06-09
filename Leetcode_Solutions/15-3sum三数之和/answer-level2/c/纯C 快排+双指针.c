```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// 以上注释说了跟没有说我感觉差不多，反正这道题新版用C语言写起来太坑了，参考了dodo大神
int CompareByIncrease(const void* a, const void* b)
{
    return *(int*)a - *(int*)b; // 快排构造递增序列
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    // 参数returnSize用来作为二维数组行数下标的指针
    // 排除[]时只输出半个]的平台bug
    *returnSize = 0;
    // 排除少于3个数的情况
    if( numsSize < 3 )
    {
        return NULL;
    }
    
    int cur = 0; // 相当于自变量，low和high的和相当于它的相反数
    int low = cur + 1;
    int high = numsSize - 1;
    
    // LeetCode 用realloc报错,malloc本以该分配A(3)(numsSize)排列空间，但是还报错,无奈用了平方，有什么解决办法？
    int** returnArray = (int**)malloc(sizeof(int*) * (numsSize)*(numsSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize)*(numsSize)); // 新版增加的参数，用来返回列数？还不能直接用 
    // 调用stdlib库的快速排序函数
    qsort(nums, numsSize, sizeof(int), CompareByIncrease);
    
    // 第一层循环用来遍历cur，第二层循环用来双指针往中间夹
    while((nums[cur] <= 0) && (cur + 1 < numsSize - 1)) // 当相反数大于0时停下，后面的都是正数了，肯定不可能
    {
        // 每次更新
        low = cur + 1;
        high = numsSize - 1;
        
        while(low < high)
        {
            if(0 == (nums[low] + nums[high] + nums[cur]))
            {
                returnArray[*returnSize] = (int*)malloc(sizeof(int) * 3); // 每次找到一组，二级指针就分配三个空间
                (*returnColumnSizes)[*returnSize] = 3; // 记录列数，非常骚而吊诡的操作
                returnArray[*returnSize][0] = nums[cur];
                returnArray[*returnSize][1] = nums[low];
                returnArray[*returnSize][2] = nums[high];
                (*returnSize)++;
                
                // 去low和high的重,非常不规范的写法，但看着极端舒服
                while( (nums[low] == nums[++low]) && (low < high) ); // 往后去重
                while( (nums[high] == nums[--high]) && (low < high) ); // 往前去重
            }
            else if(0 < (nums[low] + nums[high] + nums[cur]))
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        // 去cur的重，同样非常不规范的写法，但看着极端舒服
        while( (nums[cur] == nums[++cur]) && (cur + 1 < numsSize - 1) ); // 往后去重，同时cur往后移  
    }
    return returnArray;
}
```
