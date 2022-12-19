![2020-02-03.png](https://pic.leetcode-cn.com/514e5d7b2833a7674193b0cec922cd3e0206179bfcb9dc107f712bf987e6adec-2020-02-03.png)

### 解题思路: 定义一个result数组并遍历intervals数组，
- **如果存在intervals中有元素与result重叠，则更新result数组中的内容为: result[j] = { min(intervals[i][0], result[j][0]), max(intervals[i][1], result[j][1]) };** （**即取重叠区间的最小值与最大值**）
- **如果result中不存在与intervals重叠的元素，则将当前intervals元素push到result数组中。**
- **定义一个全局falg判断是否有区间发生重叠**
- **如果有发生重叠，则将当前结果进入下次递归**
- **如果无重叠发生. 则直接返回result结果**
```
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> result = getResult(intervals);
		return result;
	}

	vector<vector<int>> getResult(vector<vector<int>>& intervals) {
		vector<vector<int>> result;
		bool globalFlag = false;
		for (int i = 0; i < intervals.size(); i++) {
			bool flag = false;
			for (int j = 0; j < result.size(); j++) {
				if (result[j][0] > intervals[i][1] || result[j][1] < intervals[i][0]) {
					continue;
				}
				result[j] = { min(intervals[i][0], result[j][0]), max(intervals[i][1], result[j][1]) };
				globalFlag = true;
				flag = true;
				break;
			}
			if (flag == false) {
				result.push_back(intervals[i]);
			}
		}
		return globalFlag ? getResult(result) : result;
	}
};
```
