### 解题思路
先判断圆心是否在矩形内。如果圆心在矩形外，当圆与矩形相切的情况，圆心会形成一道轨迹，越过该轨迹则重叠。

### 代码

```cpp
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
		if (x_center <= x2 && x_center >= x1 && y_center <= y2 && y_center >= y1)
		{
			return true;
		}
		else if (x_center <= x2 + radius && x_center >= x1 - radius && y_center <= y2 && y_center >= y1)
		{
			return true;
		}
		else if (y_center <= y2 + radius && y_center >= y1 - radius && x_center <= x2 && x_center >= x1)
		{
			return true;
		}
		else if (pow((x_center - x1), 2) + pow((y_center - y1), 2) <= pow(radius, 2) || pow((x_center - x1), 2) + pow((y_center - y2), 2) <= pow(radius, 2) || pow((x_center - x2), 2) + pow((y_center - y1), 2) <= pow(radius, 2) || pow((x_center - x2), 2) + pow((y_center - y2), 2) <= pow(radius, 2))
		{
			return true;
		}
		else
			return false;
	
	}
};
```