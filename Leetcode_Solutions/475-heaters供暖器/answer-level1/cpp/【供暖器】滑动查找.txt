### 思路
1. 保证 `houses` 和 `heaters` 是升序的
2. 对每一个房子左边的暖气，记录它让它成为下一个房子左边最开始计算的暖气
3. 如果是房子右边的暖气，那么它是最后一个需要计算的暖气
4. 以此为标准滑动遍历房子和暖气

### 答题
```C++ []
int findRadius(vector<int>& houses, vector<int>& heaters)
{
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int ans = 0;
    int l = 0;
    for (int i = 0; i < houses.size(); i++)
    {
        int radius = INT_MAX;
        for (int j = l; j < heaters.size(); j++)
        {
            l = (houses[i] >= heaters[j]) ? j : l;
            radius = min(radius, abs(houses[i] - heaters[j]));
            if (houses[i] < heaters[j]) break;
        }
        ans = max(ans, radius);
    }
    return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

