### 解题思路
设置慢指针i和快指针j，慢指针i负责存放不重复的元素，快指针j负责移动筛选。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    if(numsSize==0) return 0;
    int i=0,j;
    for(j=0;j<numsSize;j++){
        if(nums[j]!=val){
            nums[i]=nums[j];
            i++;
        }
    }
    return i;

}
```