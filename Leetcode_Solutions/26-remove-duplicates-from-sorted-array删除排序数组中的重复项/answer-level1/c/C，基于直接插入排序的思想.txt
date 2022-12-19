### 解题思路
数组有序，值相同的元素一定连续，初始时第一个元素为非重复，之后依此判断后面元素和前面非重复有序表中最后一个元素是否相同，若相同则继续向后判断，若不同则插入到前面的非重复有序表的最后，直到判断到表尾为止。

### 代码

```c


int removeDuplicates(int* nums, int numsSize){
    int i,j;    //i用于存储第一个不相同的元素，j为工作指针
    if(numsSize==0)
    return 0;
    for(i=0,j=1;j<numsSize;j++){
        if(nums[i]!=nums[j]){   //查找下一个与上一个元素值不同的元素
            nums[++i]=nums[j];  //找到后，将元素前移
        }
    }
    return i+1;
}


```