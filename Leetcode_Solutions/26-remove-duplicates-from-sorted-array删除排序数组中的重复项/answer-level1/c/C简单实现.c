### 解题思路
- 这里采用的是一个指针表明当前考察的位置
- 如果找到重复的就需要移动数组，所以时间复杂度有些高

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int i , j , location ;
    int temp ;

    if(numsSize == 0)
    {
        return 0 ;
    }
    location = 0 ;//位置指针，考察的是location和location+1的两个元素是否相等
                  // location的范围应该是从0到numSize-2的

    for(;location<numsSize-1;)
    {
        //每次都是比较location和location+1的元素
        //1.如果相等的话就从location+1开始到numSize-1依次向前挪动，并且numsize--
        //2.如果不相等就挪动location指针

        if(nums[location] != nums[location+1])
        {
            location++;
        }
        else
        {
            for(j=location+1;j<numsSize;j++)
            {
                temp = nums[j] ; nums[j] = nums[j-1] ; nums[j-1] = temp;
            }

            numsSize--;
        }
    }

    return numsSize;
}
```