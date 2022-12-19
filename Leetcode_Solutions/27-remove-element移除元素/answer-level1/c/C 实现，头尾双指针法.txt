![2019-09-28_18-50.png](https://pic.leetcode-cn.com/1f878205d0dcb71e378706b0f2416f29fd6670a3a61bc163947f223cc06c303a-2019-09-28_18-50.png)

```c
int removeElement(int* nums, int numsSize, int val){
    if (numsSize == 0)
        return 0;
    
    // 声明头尾指针
    int * left = nums;
    int * right = nums + numsSize - 1;
    while (left < right) {
        // 从左向右找到等于 val 的位置
        while (*left != val && left < right)
            left++;
        // 从右向左找到不等于 val 的位置
        while (*right == val && left < right)
            right--;
        // 用右指针的元素覆盖左指针元素
        *left = *right;
        right--;
    }
    // 如果左指针的元素不是 val，则包括左指针处的元素
    return left - nums + (*left != val);
}
```