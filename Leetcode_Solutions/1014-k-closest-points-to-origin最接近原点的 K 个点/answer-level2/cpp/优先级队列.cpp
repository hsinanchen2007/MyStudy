### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
struct pos
{
	int x;
	int y;
	int dist;
	friend bool operator<(const pos&a, const pos&b)
	{
		return a.dist > b.dist;
	}
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int size = points.size();
        int k=K;
	pos*arr = new pos[size];
	priority_queue<pos>q;
	for (int i = 0; i < points.size(); i++)
	{
		arr[i].x = points[i][0];
		arr[i].y = points[i][1];
		arr[i].dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
		q.push(arr[i]);
	}
	vector<int>temp = { 0,0 };
	vector<vector<int>>re;
	for (int i = 0; i < k; i++)
	{
		temp[0] = q.top().x;
		temp[1] = q.top().y;
		re.push_back(temp);
		q.pop();
	}
    return re;
    }
};
```