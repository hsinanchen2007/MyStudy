【超级简单易理解】从左往右，逐步寻找最大值，顺便累加水量。然后反向，从最后一个元素到最大值再运行一次。

```C++ []
class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int p = 0, p_max = 0, water = 0, water_tmp = 0;
        // p记录从左往右的最大值的坐标，也是全局最大值，p_max记录最大值的数值（可选）
        // water记录全局最大水量，water_tmp记录局部小水坑的水量
        for (int i = 0; i < height.size(); ++i)
        {
            if (p_max <= height[i])
            {
                // 遇到了更高的，更新相关信息
                p = i;
                p_max = height[i];
                water += water_tmp;
                water_tmp = 0;
            }
            else
                water_tmp += p_max - height[i];
        }
        int p2 = 0;    // 从右往左的最大值坐标
        p_max = 0;     // 更新为从右往左的最大值value
        water_tmp = 0; // 小水坑
        for (int i = height.size() - 1; i >= p; --i)
        {
            if (p_max <= height[i])
            {
                p2 = i;
                p_max = height[i];
                water += water_tmp;
                water_tmp = 0;
            }
            else
                water_tmp += p_max - height[i];
        }
        return water;
    }
};
```