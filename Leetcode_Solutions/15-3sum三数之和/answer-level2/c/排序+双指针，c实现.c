### 解题思路
先排序数组，然后依次遍历元素i(从0开始)，取左指针=i+1，右指针为numsSize-1,判断此三元素之和是否为0.
借鉴优秀题解@吴彦祖和@画家王铁男的实现。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//冒泡排序
void arraySort(int* nums, int numsSize){
    for(int i=0; i < numsSize-1; i++){
        for(int j=i+1; j < numsSize; j++){
            if(nums[i] > nums[j]){
                nums[i] = nums[i] + nums[j];
                nums[j] = nums[i] - nums[j];
                nums[i] = nums[i] - nums[j];
            }
        }
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    // 参数returnSize用来作为二维数组行数下标的指针
    // 排除[]时只输出半个]的平台bug
    *returnSize = 0;
    //当输入元素不足3个
    if(numsSize < 3){
        return NULL;  //c语言里没有[]，没有东西输出就用NULL表示
    }

    //初始化结果数组为numsSize行numsSize列的
    int** returnArray = (int**)malloc(sizeof(int*) * (numsSize)*(numsSize));
    // 新版增加的参数用来返回列数？还不能直接用 
    *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize)*(numsSize)); 
    arraySort(nums, numsSize);

    for(int i=0; i < numsSize; i++){
        //若排序后的数组首元素大于0 ，则肯定不存在三元组
        if(nums[0] > 0){
            return NULL;
        }
        //去重1：排除左指针与i元素已组合过的情况
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }

        int left = i+1, right = numsSize-1;
        while(left < right){
            if(nums[i] + nums[left] + nums[right] == 0)
            {
                // 每次找到一组，二级指针就分配三个空间
                returnArray[*returnSize] = (int*)malloc(sizeof(int) * 3); 
                (*returnColumnSizes)[*returnSize] = 3; // 记录列数，非常6666
                returnArray[*returnSize][0] = nums[i];
                returnArray[*returnSize][1] = nums[left];
                returnArray[*returnSize][2] = nums[right];
                (*returnSize)++;
                //去重2：左指针移动到最后1个相同元素
                while(left < right && (nums[left] == nums[left+1])){
                    left++;
                }
                //去重3：右指针移动到最后1个相同元素
                while(left < right && (nums[right] == nums[right-1])){
                    right--;
                }
                //双指针例行移动1位
                left++;
                right--;
            }
            else if(nums[i] + nums[left] + nums[right] < 0)
            {  //都没满足结果，去什么重？
                left++;            
            }
            else{
                right--;                        
            }
        }
    }
    
    return returnArray;
}
```