见注释
```cpp
class Solution {
public:
	string findContestMatch(int n) {
		// 第一轮分区头和为3 最终轮分区头和为n + 1
		return match(1, 3, n + 1);
	}

	// start = 第一个数 roundDis = 分区头的和 target = 最终轮分区头的和
	string match(int start, int roundDis, int target) {
		// 是最终轮则输出
		if (roundDis == target)
			return '(' + to_string(start) + ',' + to_string(roundDis - start) + ')';
		// 计算下一轮两个分区头的和
		int nextRoundDis = roundDis * 2 - 1;
		// 两个分区分别递归
		return '(' + match(start, nextRoundDis, target) + ',' + match(roundDis - start, nextRoundDis, target) + ')';
	}
};
```
