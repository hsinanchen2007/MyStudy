# multimap牛批！
首先要知道map本来就是按照key值排好序的，因此用map去保存战斗力和行索引再用迭代器输出前k个元素就相当省事儿！
最刚开始考虑的是使用map去保存每一行的战斗力和行索引，但是发现有一些行的战斗力是相同的，后出现的行会覆盖掉先出现的行，那么这个时候就应该用multimap了，而且在key相同的情况下，后insert的元素也会排列在先insert的元素后面，正好符合题意。
# 代码简洁明了

```
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
	multimap<int, int> rows;
	int len = mat.size();
	for(int i = 0; i < len; i++)
	{
		int this_row = 0;    //用来计算每一行的战斗力
		for (int& num : mat[i])
		{
			this_row += num;
		}
		rows.insert(pair<int,int>(this_row,i)); //插入multimap，自动排序
	}
	auto it = rows.begin();
	vector<int> ret;        //保存最终结果的数组
	for (int i = 1; i <= k; i++) //用迭代器遍历前k个最小元素
	{
		ret.push_back((*it).second);
		++it;
	}
	return ret;
}
```

# 速度双百
![image.png](https://pic.leetcode-cn.com/2376900f18988c726fb1207ef121e50beef0eaa04a3db133234f4d57a5493170-image.png)


    