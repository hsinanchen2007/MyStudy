### 思路
1. 按照会议开始日期对 `events` 排序，使用默认排序算法就可以
2. 再使用一个优先队列，根据日期，将今天开始的会议全都加入到优先队列中
3. 优先队列的排序以会议的结束日期为标准，保证越接近结束日期的越靠前
4. 每一天如果优先队列里还有会议，就去参加一个
5. 新的一天，先把优先队列里已经过期的会议清除掉

### 答题
```C++
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
	{
		sort(events.rbegin(), events.rend());
		priority_queue<int, vector<int>, greater<int>> pq;

		int ans = 0;
		int day = 0;
		while (!events.empty() || !pq.empty())
		{
			day++;
			while (!pq.empty() && pq.top() < day)
			{
				pq.pop();
			}
			while (!events.empty() && events.back()[0] == day)
			{
				pq.push(events.back()[1]);
				events.pop_back();
			}
			if (pq.empty()) continue;
			pq.pop();
			ans++;
		}
		
		return ans;
    }
};
```

### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

