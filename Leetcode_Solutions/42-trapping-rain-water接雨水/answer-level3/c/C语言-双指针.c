### 解题思路
此处撰写解题思路

### 代码

```c
int trap(int* height, int heightSize)
{
    int res = 0, left = 0, right = heightSize - 1, i;
    while (right - left > 1)
    {
        if (height[left] <= height[right])
        {
            for(i = left + 1; i < right; i++)
            {
                if (height[i] >= height[left])
                    break;
                else
                    res += height[left] - height[i];
            }
            left = i;
        }
        else
        {
            for (i = right - 1; i > left; i--)
            {
                if (height[i] >= height[right])
                    break;
                else
                    res += height[right] - height[i];
            }
            right = i;
        }
    }
    return res;
}
```