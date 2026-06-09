### 解题思路
本题使用的方法为官网所提供的双指针的方式。
设置left和right两个指针，分别从两边开始遍历。
使用left_max和right_max两个数来记录当前最大值。
当碰到左边高度大于右边高度时，需要移动右边的指针。
如果当前高度比所记录的max值大时，那么只需要将max值改变，就继续进行循环，如果是小于等于的情况，那么可以将相减的值加入结果中。
当左边高度小于等于右边高度时，移动的是左边的指针。

### 代码

```c
int trap(int* height, int heightSize){
    int left = 0,right = heightSize-1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while(left < right)
    {
        if(height[left] >= height[right])
        {
            if(height[right] > right_max)
                right_max = height[right];
            else
                ans += (right_max - height[right]);
            right--;
        }
        else
        {
            if(height[left] > left_max)
                left_max = height[left];
            else
                ans += (left_max - height[left]);
            left++;
        }
    }
    return ans;
}
```