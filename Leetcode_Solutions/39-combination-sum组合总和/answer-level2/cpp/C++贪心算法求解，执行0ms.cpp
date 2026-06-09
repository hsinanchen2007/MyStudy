![image.png](https://pic.leetcode-cn.com/b7b8baa64fc30e75c624ebd21c495d767147a7481a314c1f45a85942958d8473-image.png)
执用时0ms, 击败100%
### 解题思路
类似零钱兑换的思路, 先用最大数字尽量填满, 再往下用剩余数字填补剩余值; 遍历完之后, 最大数字个数减一, 重复上述过程。
递归到目标值为0时, 该递归分支有解, 记录下来。
如果目标值小于零, 说明无解; 若遍历完所有数字, 也无解。
	res记录解的集合;
	solu记录迭代过程中的解。

该解决方案输出的结果, 一定是从大到小排序的, 因此不会出现重复解的情况。

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.rbegin(), candidates.rend());
		vector<vector<int>> res;
		vector<int> solu;
		coinChangeIter(candidates, target, 0, res, solu);
		return res;
	}
	void coinChangeIter(vector<int>& candidates, int target, int index, vector<vector<int>>& res, vector<int>& solu){
		//target: 目标值    candidates:数字数组   index: 有效数字数组范围 res: 结果集合  solu: 当前方案
		if (target == 0){ //遍历到最后,有解
			res.push_back(solu);
			return ;
		}
		if (index == candidates.size() || target < 0)
			return; //遍历到最后,无解
		int candidate = candidates[index];
		// 贪心算法, 先用最大值填到满
		for (int count = target / candidates[index]; count > 0; count--) solu.push_back(candidates[index]);
		for (int maxCoinNum = target / candidates[index]; maxCoinNum >= 0; maxCoinNum--){
			coinChangeIter(candidates, target - maxCoinNum * candidates[index], index + 1, res, solu);
			if (maxCoinNum > 0) solu.pop_back(); //最大数字个数减一
		}
	}
};
```