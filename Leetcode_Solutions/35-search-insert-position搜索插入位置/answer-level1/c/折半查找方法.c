### 解题思路
折半查找又称二分查找，顾名思义，就是每次将一组已排序的数据取中间位置middle，最低位low，最高位high，与要查找的目标数据进行对比，如果数据比middle数大，就将low坐标移到middle+1；若数据比middle数小，就将high坐标移到middle-1的位置。最终匹配到的一定是middle。若无匹配数据，则说明当前数据比low小，则应放在low位置。新手在此，如有错误之处请多多指教！

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int low=0;
    int high=numsSize-1;
    int middle=0;

    while(low <= high){
        middle=low+(high-low)/2;
        if(target>nums[middle]){
            low=middle+1;
        }else if (target<nums[middle]){
                high=middle-1;
        }
            else if(target==nums[middle]){
                return middle;
            }
               
    }
    return low;
}

```