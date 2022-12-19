### 解题思路
找山峰，边上山边统计。当前最大水位就是当前最大高度，当前雨水量为水位-当前高度
### 代码

```c
int trap(int* height, int heightSize){
    int i = 0;
    int max_index = 0, max = 0;
    int water_lvl = 0;
    int water = 0;

    // 找最高峰
    for ( i = 0; i < heightSize; i++)
    {
        if(height[i] > max)
        {
            max_index = i;
            max = height[i];
        }
    }
    // 水位是递增的，当前水位即为当前最大高度
    // 雨水量=水位-当前高度
    water_lvl = 0;
    for ( i = 0; i < max_index; i++)
    {
        if(height[i] > water_lvl)
        {
            water_lvl = height[i];
        }
        water += water_lvl - height[i];
    }

    // 右坡同样过程
    water_lvl = 0;
    for(i = heightSize - 1; i > max_index ; i--)
    {
        if(height[i] > water_lvl)
        {
            water_lvl = height[i];
        }
        water += water_lvl - height[i];
    }

    return water;
}
```