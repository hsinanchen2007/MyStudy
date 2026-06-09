### 解题思路
这个题的思路其实很简单，为了简化问题，本题可看做通过某点直线最多的点数，传统的做法就是分类讨论：
1.使用一个变量dup记录重复的点；
2.使用Map，构造一个pair<double,int>来记录：前者为斜率值，后者为计数（注意讨论斜率不存在的情况否则会造成除法异常）
**但本题难在高精度斜率的计算**，样例中有一个数据会使你的long double的精度都失效。所以这时候如果仍然采用传统的斜率判别法则需要运用高精度除法算法。
所以，基于此需要对Map的元素进行改变，构造pair<string,int>此时使用字符串来保存斜率（代码中精度我取了小数点后20位）
![无标题.png](https://pic.leetcode-cn.com/55b302d47650dcd89ec92eecaef6d0bd67fa7d3d6d0f78b6cf024a00ff467cb0-%E6%97%A0%E6%A0%87%E9%A2%98.png)

### 代码

```cpp
class Solution {
public:
   string Slope(int a, int b) {
	string s = "";
	char c;
	int p;
	stringstream ss;  //使用字符流将整数部分直接转换成字符串。
	p = a / b;
	ss << p;
	ss >> s;
	s += '.';
	for (int i = 0; i < 20; i++)  //小数点后模拟除法过程，此时精度为20位。
	{
		a = a % b * 10;
		c = (char)(a / b + 48);
		s += c;
	}
	return s;
}
int maxPoints(vector<vector<int>>& points) {
	map<string, int>Dic;   //构造映射表，string类型存储斜率，int类型存储相应的点数。
	int i, j, x1, x2, y1, y2, ans, res = 2, temp, dup;
	string k;
	if (points.size() <= 2)
		return points.size();
	for (i = 0; i < points.size(); i++) {
		dup = 0;
		ans = 0;
		for (j = i + 1; j < points.size(); j++) {
			x1 = points[i][0];
			x2 = points[j][0];
			y1 = points[i][1];
			y2 = points[j][1];
			if (x1 == x2 && y1 == y2)   //情况一：重复的点。
				dup++;
			else if (x1 == x2 && y1 != y2) {  //情况二：斜率不存在的点。
				if (Dic.find(" ") == Dic.end())
					Dic.insert(pair<string, int>(" ", 2));
				else
					Dic[" "]++;
				ans = max(Dic[" "], ans);
			}
			else {   //情况三：斜率存在的点。
				k = Slope(y1 - y2, x1 - x2);
				if (Dic.find(k) == Dic.end())
					Dic.insert(pair<string, int>(k, 2));
				else
					Dic[k]++;
				ans = max(Dic[k], ans);
			}
		}
		if (ans == 0)   //注意，若遍历完只有重复的点，则需要加一，因为dup是从0开始计数的。
			res = max(res, dup + 1);
		else
			res = max(res, ans + dup);
		Dic.clear();
		k = "";
	}
	return res;
}
};
```