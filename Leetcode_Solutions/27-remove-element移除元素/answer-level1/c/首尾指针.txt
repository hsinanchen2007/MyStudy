### 解题思路
此处撰写解题思路

### 代码

```c


int removeElement(int* nums, int numsSize, int val)
{
    int i = 0;
    int n = numsSize;
    while (i < n) {
        if (nums[i] == val) 
        {
            nums[i] = nums[n - 1];
            n--;
        } else {
            i++;
        }
    }
    return n;
}
```