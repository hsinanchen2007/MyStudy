![image.png](https://pic.leetcode-cn.com/f47492958f6ec260e39ee19178ea7fcf73b4c62895a7b90dbab93a995b92d4c6-image.png)
### 解题思路
零钱问题的经典解法, 思路可用于诸多类似的问题: 
	22. 括号生成问题
	39. 组合总和
    先将硬币面额从大到小排序, 再从最大面额的个数开始分支。即先考虑用n个最大面额硬币, 剩余金额在用剩余面额硬币兑换; 再考虑用n-1个最大面额硬币, 剩余金额在用剩余面额硬币兑换...依次类推。
    再进行剪枝, 若已用数量已大于最小数量, 则无续再往下讨论。

### 代码

```cpp
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0)
			return 0;
		sort(coins.rbegin(), coins.rend());
		int miniAns = INT_MAX;
		coinChangeIter(coins, amount, 0, 0, miniAns);
		miniAns = (miniAns == INT_MAX) ? -1 : miniAns;
		return miniAns;
	}

	void coinChangeIter(vector<int>& coins, int amount, int index, int count, int& miniAns){
	//amount: 目标值    coins:硬币数组   index: 有效硬币数组范围 count: 已使用硬币数  miniAns: 当前最小值
		if (amount == 0){ //遍历到最后,有解
			miniAns = count < miniAns ? count : miniAns;
			return;
		}
		if (index == coins.size())
			return; //遍历到最后,无解
		for (int maxCoinNum = amount / coins[index]; maxCoinNum >= 0 && maxCoinNum + count < miniAns; maxCoinNum--){
			coinChangeIter(coins, amount - maxCoinNum * coins[index], index + 1, count + maxCoinNum, miniAns);
		}
	}
};
```