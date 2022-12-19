C++实现起来用priority_queue容器，默认从小到大排序，底层实现为最大堆。

```C++ []
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<int> q;
        for (int a : arr) {
			q.push(a);
			if (q.size() > k)
				q.pop();
		}
        while (!q.empty()) {
			res.push_back(q.top());
			q.pop();
		}
		return res;
    }
};
```
