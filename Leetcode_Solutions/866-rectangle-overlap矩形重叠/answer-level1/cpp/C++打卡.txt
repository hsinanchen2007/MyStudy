### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		int x1Low = rec1[0], y1Low = rec1[1], x1High = rec1[2], y1High = rec1[3];
		int x2Low = rec2[0], y2Low = rec2[1], x2High = rec2[2], y2High = rec2[3];
		//第二个矩形在第一个矩形的右侧，左侧，上方，下方时说明不重叠，返回false
		if ((x2Low >= x1High) || (x2High <= x1Low) || (y2Low >= y1High) || (y2High <= y1Low)) {
			return false;
		}
		return true;
	}
};
```