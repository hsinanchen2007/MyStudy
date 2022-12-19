### 解题思路
利用快指针和慢指针来指向数组中的元素，快指针负责找到不重复的项，慢指针负责定位，将不重复的项依次赋值给num[1]，num[2]等，直到快指针到达最后一项

### 代码

```c
int removeDuplicates(int* nums, int numsSize)
{
    int pslow=0,pfast=1;//慢指针从第一项开始，所以为0.快指针从第二项开始，所以为1
    if(nums==NULL||numsSize<1) //防止输入为空
        return 0;
    for(;pfast<numsSize;pfast++)//快指针从第二项开始依次往后指
            if(nums[pslow]!=nums[pfast])//判断快指针所指向的元素与慢指针指向的元素是否不相等，即找到与慢指针所指向元素不同的元素
                {
                    pslow++;//让慢指针指向下一个元素
                    nums[pslow]=nums[pfast];//将第一个不重复的元素赋值给慢指针指向的元素
                }
    return pslow+1;//因为慢指针是从0开始计数的，所以返回值需要+1
}
```