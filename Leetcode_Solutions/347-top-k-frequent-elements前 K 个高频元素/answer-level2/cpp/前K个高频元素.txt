# 前K个高频元素
给定一个非空的整数数组，**返回其中出现频率前 k 高**的元素。

示例 1:

```
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
```

示例 2:

```
输入: nums = [1], k = 1
输出: [1]
```

说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

<hr>

##  解法1：
思路：用一个哈希表存放各元素出现的次数，用一个一维数组存放出现过的元素，再将哈希表中的数据存放到二维数组中进行排序，取出前k个元素放入一维数组中。
```
class Solution {
public:
	static bool cmp(const vector<int> &a, const vector<int> &b)//根据频率排序
	{
		return a[1] > b[1];
	}
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> a;//存放出现过的元素
		map<int, int> list1;//计算频率
		for (int i = 0; i < nums.size(); i++)
		{
			if (!list1.count(nums[i]))//若没找到，则插入元素
			{
				list1.insert(map<int, int>::value_type(nums[i], 1));
				a.push_back(nums[i]);
			}
			else
			{
				list1[nums[i]]++;//找到了频率+1
			}
		}
		vector<vector<int>> b(a.size(),vector<int>(2));//用来排序的二维数组
		for (int i = 0; i < a.size(); i++)
		{
			b[i][0]=a[i];
			b[i][1]=list1[a[i]];
		}
		sort(b.begin(), b.end(), cmp);
		a.clear();
		for (int i = 0; i < k; i++)
		{
			a.push_back(b[i][0]);
		}
		return a;
	}
};
```
<br>

##  解法2：

```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;//计算频率
        for (auto &num: nums)
            count[num]++;
        multimap<int, int, std::greater<int>> freq;//用于排序，小根堆
        for (auto &f : count)
            freq.insert(make_pair(f.second, f.first));
        vector<int> res;//存放结果
        for (auto it = freq.begin(); it != freq.end() && k; ++it,--k)
            res.push_back(it->second);
        return res;
    }
};
```

