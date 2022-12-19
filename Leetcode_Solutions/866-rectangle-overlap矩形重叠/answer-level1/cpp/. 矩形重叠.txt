### 解题思路
1.如果矩形A 的点在矩形B内部，则两矩形重叠，反之同理
![顶点相交.png](https://pic.leetcode-cn.com/471cdd1ff2d7df67cc55a4edf30c0d63ef5169db85fb23a89a4e3cfe3d76b81f-%E9%A1%B6%E7%82%B9%E7%9B%B8%E4%BA%A4.png)

2.
![顶点相交.png](https://pic.leetcode-cn.com/4cab65adf4d85f192107b559263e8b43aacf9df7b0b8825acc6cc67356e88ff3-%E9%A1%B6%E7%82%B9%E7%9B%B8%E4%BA%A4.png)
### 代码

```cpp
class Solution {
public:
 bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
	{
		if (IsOverlap_1(rec1, rec2))
		{
			return true;
		}
		else if (IsOverlap_1(rec2, rec1))
		{
			return true;
		}
		
		return  IsOverlap_2(rec1[0], rec1[1], rec1[2], rec1[3], rec2[0], rec2[1], rec2[2], rec2[3]);
	}
	bool IsOverlap_Point(int x1,int y1,int x2,int y2, int x,int y)
	{
		if (x > min(x1, x2) && x < max(x1,x2))
		{
			if (y > min(y1,y2) && y < max(y1,y2))
			{
				return true;
			}
		}
		return false;
	}

	bool IsOverlap_1(vector<int>& rec1, vector<int>& rec2)
	{
		if (IsOverlap_Point(rec1[0], rec1[1], rec1[2], rec1[3], rec2[0], rec2[1]))
		{
			return true;
		}
		if (IsOverlap_Point(rec1[0], rec1[1], rec1[2], rec1[3], rec2[2], rec2[3]))
		{
			return true;
		}
		if (IsOverlap_Point(rec1[0], rec1[1], rec1[2], rec1[3], rec2[2], rec2[1]))
		{
			return true;
		}
		if (IsOverlap_Point(rec1[0], rec1[1], rec1[2], rec1[3], rec2[0], rec2[3]))
		{
			return true;
		}
		return false;
	}
	bool IsOverlap_2(int x1, int y1, int x2, int y2, int x3, int y3,int x4,int y4)
	{
		if (max(x1,x2) >= max(x3,x4) && min(x1,x2) <= min(x3,x4))
		{
			if (max(y1,y2) <= max(y3,y4) && min(y1,y2) >= min(y3,y4))
			{
				return true;
			}
		}
		if (max(x1, x2) <= max(x3, x4) && min(x1, x2) >= min(x3, x4))
		{
			if (max(y1, y2) >= max(y3, y4) && min(y1, y2) <= min(y3, y4))
			{
				return true;
			}
		}
		return false;
	}
};
```