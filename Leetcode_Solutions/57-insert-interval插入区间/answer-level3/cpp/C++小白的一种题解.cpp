### 解题思路
12ms ，95.33%
11.9Mb，100%

将newInterval插入至intervals中，之后将题目当成56题，合并区间做

ok废话不多说，我们直接上代码，详细的细节在代码中标出，哈哈哈哈嗝

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> res;
		if (intervals.empty() && newInterval.empty()) return res;         //特判
		if (intervals.empty())
		{
			res.push_back(newInterval);
			return res;
		}
		for (int i = 0; i <= intervals.size(); i++)                          
		{
        	//利用或符号的短路特性，先判断i是否到结尾，到了结尾就会直接进入判断内容而不会判断第二个条件，保证不会溢出
			if (i == intervals.size() || newInterval[0] < intervals[i][0])
			{
				vector<vector<int>>::iterator iter = intervals.begin() + i;
				intervals.insert(iter, newInterval);                              //找到newIntervals合适的位置插入进intervals
				if (i == 0)                                    //如果在开始就插入，就先递增一次，保证下面在穿递的时候不会发生数组溢出
					i++;
				Insert(i-1, intervals, res);                  //基本同上一题
				return res;
			}
		}
		return res;
	}
private:
	void Insert(int index, vector<vector<int>>& intervals, vector<vector<int>> &res)
	{
		for (int i = 0; i < index; i++)
			res.push_back(intervals[i]);                //将index之前的存入res
		vector<int> item;
		item.push_back(intervals[index][0]);
		item.push_back(intervals[index][1]);
		for (int i = index+1; i < intervals.size(); i++)          //从index+1开始，因为index存入了item，直接从下一个开始比较
		{
			if (item[1] >= intervals[i][0])            
			{
				if (item[1] < intervals[i][1])                   //对应于[3, 6], [5, 8]
					item[1] = intervals[i][1];                   //修改item为[3, 8]
				else											//对应于[3, 6], [4, 5]， item不需要修改，下一个区间被吞并
					continue;
			}
			else												
			//下面不可以合并，将item放进res里面存储结果，清空item，并且将当前的存入item，做下一轮比较合并
			{
				res.push_back(item);
				item.clear();
				item.push_back(intervals[i][0]);
				item.push_back(intervals[i][1]);
			}
		}
		res.push_back(item);                  //由于出来的时候最后一段是没有添加进去的，于是在最后再添加一次item，将最后一段的结果放进res
	}
};
```