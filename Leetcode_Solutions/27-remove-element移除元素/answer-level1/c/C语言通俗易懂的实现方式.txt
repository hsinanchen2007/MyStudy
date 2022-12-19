### 解题思路
- 设置一个位置指针，每次比较这个指针对应的位置的元素和val是否相等
- 相等
    * 从location+1开始到最后依次向前移动一个位置
    * 即location这个位置的元素被覆盖掉了所以后面接着还是从location开始考察
    * 数组的大小减一
- 不相等
    * 直接location指针加一

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int location , j , temp ;

    for(location=0;location<numsSize;)
    {
        //location是要考察的元素，如果location和val相等就
        //从location+1到numSize-1依次向前挪动一个位置
        //如果不相等的话就直接location++
        if(nums[location] == val)
        {
            for(j=location+1;j<numsSize;j++)
            {
                temp = nums[j] ; nums[j] = nums[j-1] ; nums[j-1] = temp;
            }

            numsSize--;
        }
        else
        {
            location++;
        }
    }

    return numsSize;
}
```