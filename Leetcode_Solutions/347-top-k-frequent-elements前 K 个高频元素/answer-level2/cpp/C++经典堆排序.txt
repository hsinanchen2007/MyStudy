### 解题思路
参考男票
[@zhe-da-zhu-bo-li-gong](/u/zhe-da-zhu-bo-li-gong/)通过最小堆排序，实现了前K个高频元素问题

### 代码

```cpp
class Solution {
public:
	class cmp {
	public:
		//通过重载操作符来对优先队列定义排序规则
		bool operator()(pair<int, int>& a, pair<int, int>& b)
		{
			return a.second > b.second;
		}
	};
	vector<int> topKFrequent(vector<int>& nums, int k) {
		//map<int, int> myMap; 
		//不使用map的原因是map底层是红黑树，每次插入会进行排序，增加了时间复杂度
		unordered_map<int, int> myMap;
		//统计该值出现的次数
		for (auto num : nums)
		{
			myMap[num]++;
		}
		//遍历map，用最小堆保存频率最大的k个元素
		//优先队列，把最小的元素放在队首
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
		for (unordered_map<int, int>::iterator beg = myMap.begin(); beg != myMap.end(); beg++)
		{
			pq.push(make_pair(beg->first, beg->second));//压入该键值对
			if (pq.size() > k)//堆中元素多于k个
			{
				pq.pop();
			}
		}
		//取出最小堆中的元素
		vector<int> res;
		while (!pq.empty())
		{
			res.push_back(pq.top().first);
			pq.pop();
		}
		//结果要逆序输出
		vector<int> tempRes(res.rbegin(), res.rend());
		return tempRes;
	}
};
```