**判断是否重叠：**
如果一个矩形的右边界在另一个矩形左边界的左边且这个矩形左边界在另一个矩形有边界的左边，则两者不重叠；
同理，都在右边也不重叠；
上下边界也同理。
只要某个方向上矩形是分离的，两矩形就不重叠。
没有其他不重叠的情况了，剩下的就是重叠的。

**计算重叠面积：**
由于无论以何种形式重叠，重叠部分都是一个矩形，所以只要计算出它的长和宽就行了。
对两个矩形的4个x坐标排序，得到的中间两个坐标就是重叠部分的矩形两侧的x坐标，减一下得到长度。
y坐标同理得到宽度。
只要矩形重叠，长乘宽就是重叠部分面积。
如果矩形不重叠，重叠面积为0。

**代码：判断重叠**
```C++ []
class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		bool flag1 = false, flag2 = false;
		if ((rec1[0] <= rec2[2] && rec1[2] <= rec2[0]) || (rec1[0] >= rec2[2] && rec1[2] >= rec2[0]))
			flag1 = true;
		if ((rec1[1] <= rec2[3] && rec1[3] <= rec2[1]) || (rec1[1] >= rec2[3] && rec1[3] >= rec2[1]))
			flag2 = true;
		return !(flag1 || flag2);
	}
};
```

**代码：计算重叠面积**
```
class Solution {
public:
	int RectangleOverlapArea(vector<int>& rec1, vector<int>& rec2) {
		
		bool flag1 = false, flag2 = false;
		if ((rec1[0] <= rec2[2] && rec1[2] <= rec2[0]) || (rec1[0] >= rec2[2] && rec1[2] >= rec2[0]))
			flag1 = true;
		if ((rec1[1] <= rec2[3] && rec1[3] <= rec2[1]) || (rec1[1] >= rec2[3] && rec1[3] >= rec2[1]))
			flag2 = true;
		if (flag1 || flag2)
			return 0;
		vector<int> v1 = { rec1[0],rec1[2],rec2[0],rec2[2] };
		vector<int> v2 = { rec1[1],rec1[3],rec2[1],rec2[3] };
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		return (v1[2] - v1[1]) * (v2[2] - v2[1]);
	}
};
```

