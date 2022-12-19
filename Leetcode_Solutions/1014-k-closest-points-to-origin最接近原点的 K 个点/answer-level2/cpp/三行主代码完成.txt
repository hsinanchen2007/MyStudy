### 解题思路
此处撰写解题思路
![微信截图_20200208112101.png](https://pic.leetcode-cn.com/b83154cd4b9605b28eb40e2fb0af1fc80d8ca99af5345201f3179d67ebd82583-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200208112101.png)

### 代码

```cpp
class Solution {
public:
   	static bool cmp1(vector<int>&a, vector<int>&b)  //自定义排序，按照欧几里得距离升序
	{
		return a[0] * a[0] + a[1] * a[1] <b[0] * b[0] + b[1] * b[1];
	}


	vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
	{

		sort(points.begin(), points.end(), cmp1); //对points自定义排序

		points.erase(points.begin() + K, points.end()); //保留前面K个最小的元素，删除后面的元素

		return points;
	}
};
