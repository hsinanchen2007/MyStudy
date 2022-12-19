### 解题思路
逻辑是判断到倒数第二个为止，（若相等，后面的左移，最后一个不能应用这种方法）
在这个判断中，要在最后改变数组有效长度，每相等一个，删除动作 size--）
但是最后一个元素需要单独判断

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
int i,j;
if(numsSize==0)
return 0;
if(numsSize==1&&val==nums[0])
return 0;
if(numsSize==1&&val!=nums[0])
return 1;
for(i=0;i<numsSize-1;i++)
    if(nums[i]==val)//shift left
    {
        for(j=i;j<numsSize-1;j++)
        {
            nums[j]=nums[j+1];
        }
        numsSize--;
        i--;
    }
if(nums[numsSize-1]==val)
    numsSize--;
return numsSize;
}
```