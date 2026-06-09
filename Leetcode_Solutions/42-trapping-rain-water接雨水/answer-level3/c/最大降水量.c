### 解题思路
相当于砌墙，看墙中间的最大值，刚开始是想找到凹字形的东西，遍历太麻烦
因此转变思路，找到最高的山，然后从左到右一步步乘水，并且不断更新左侧墙的最高高度
从而得到答案

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

    // 相当于看左侧的墙，垒得有多高，即水位在这里高度
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
//找到左右两侧的最大值的共同最小值 决定乘多少水 nice啊  基本解法

int trap(vector<int>& height)
{
    int ans = 0;
    int size = height.size();
    for (int i = 1; i < size - 1; i++) {
        int max_left = 0, max_right = 0;
        for (int j = i; j >= 0; j--) { //Search the left part for max bar size
            max_left = max(max_left, height[j]);
        }
        for (int j = i; j < size; j++) { //Search the right part for max bar size
            max_right = max(max_right, height[j]);
        }
        ans += min(max_left, max_right) - height[i];
    }
    return ans;
}
