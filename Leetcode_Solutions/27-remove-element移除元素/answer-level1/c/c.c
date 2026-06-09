### 解题思路
此处撰写解题思路
1、和上一道题一样，即不同数值时，进行real值增加与拷贝；

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int real_num = 0;
    int i = 0;

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            real_num++;
            nums[real_num - 1] = nums[i];
        }
    }

    return real_num;
}
```