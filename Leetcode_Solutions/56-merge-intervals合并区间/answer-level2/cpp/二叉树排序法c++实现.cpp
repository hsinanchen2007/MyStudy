### 解题思路
1.首先，排序兼合并两个连续的区间，[a,b] [b,c]这种情况，把结果放入二叉树作为缓存
2.然后就迭代这个缓存就可以了，只要balance平衡为0，就说明一个区间闭合了，即可推入最终结果数组中


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> r;
	std::map<int, int> cache;

	/*
		用二叉树排序，顺便记录下是起点还是终点，起点+1 终点-1，
		对于两个区间连续的情况 比如[1,4],[4,5]
		四会连续出现两次，这样就自动合成为一个区间1，5
		之后遍历的时候只要平衡了就是一个处理好的区间
	*/
	for (int i = 0; i < intervals.size(); i++)
	{
		cache[intervals[i][0]] ++;
		cache[intervals[i][1]] --;
	}

	std::map<int, int>::const_iterator cit = cache.cbegin();
	int balance = 0;
	int start = 0;
	int end = 0;
	for (; cit != cache.cend(); cit++)
	{
		//迭代每一个起点或者终点
		if (balance == 0)
		{//新的区间开始
			start = cit->first;				
		}
		
		//计算平衡数，如果为0，说明一个区间闭合完毕
		balance += cit->second;

		if (balance == 0)
		{
			//区间闭合，推入结果中
			//起点变量复位
			end = cit->first;
			balance = 0;
			r.push_back({ start, end });
		}	

	}

	return r;
    }
};
```