### 解题思路
执行用时 :4 ms, 在所有 C 提交中击败了95.77%的用户
内存消耗 :6 MB, 在所有 C 提交中击败了100.00%的用户

此方法是在按列求法的基础上进行了优化，在求第i个柱子左右两边柱子的最大高度时，采用动态规划，避免了每次都要重复遍历左右两边柱子的高度（避免了嵌套循环），从而大大降低了时间复杂度。
### 代码

```c
int trap(int* height, int heightSize){//动态规划
    int num = 0;
    int temp = 0;
    int* max_left = (int*)malloc(heightSize*sizeof(int));
    int* max_right = (int*)malloc(heightSize*sizeof(int));
    for (int i = 1; i < heightSize - 1; i++)
    {
        if (max_left[i - 1] < height[i - 1])
            max_left[i] = height[i - 1];
        else
            max_left[i] = max_left[i - 1];

    }
    for (int i = heightSize - 2; i >= 0; i--)
    {
        if (max_right[i + 1] < height[i + 1])
            max_right[i] = height[i + 1];
        else
            max_right[i] = max_right[i + 1]; 
    }
    for (int i = 1; i < heightSize - 1; i++)
    {

        if (max_left[i] <= max_right[i])
            temp = max_left[i];
        else 
            temp = max_right[i];

        if (height[i] < temp)
            num += temp - height[i];
        else
            continue;
    }
    return num;
}
```