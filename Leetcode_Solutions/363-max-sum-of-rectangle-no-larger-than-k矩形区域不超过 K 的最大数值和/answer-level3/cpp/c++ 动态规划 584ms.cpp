# c++ 动态规划 584ms
# 24ms的提交范例的有误, 以下会解释, 感谢 zerostan 提出的建议

# **思路**
**首先这是一个DP问题**, 考虑到n行远大于m列, 我们先遍历每一列的所有连续的列组合情况, 是两层循环

**然后** 两层循环的外循环开始先初始化一个vector<int> prerowSum(n, 0), prerowSum[i]表示第i+1行, 以及当前连续的列所围成的单行多列的矩阵元素和

**然后** 在内循环部分: 我们先更新整个prerowSum, 然后到了范例的剪枝部分

**这一段将解释为什么24ms的提交范例有误: 范例的意思是：** 我们按顺序给prerowSum求和得到preSum, preSum表示的意思是：（第1行至第i-1行, 当前的连续的列的矩阵元素和）, 如果preSum比k小, 则比较记录, 并且如果preSum比0小, 表明第i-1行是个很大的负数, 前面连续多行的正的和都没他负的厉害, 那么重置preSum=0。**然而**：经zerostan说明，上述写法有漏洞：我参考了他的用例，简化了一下，例如：matrix = {{3}, {-7}, {3}, {3}, {3}, {-9}}, k=2。尽管在这轮行遍历中, 仅仅记录了0至res, 随后结论是0(这是因为可以将他们分成3 -7这两个数字 以及剩余的4个数字, 且最终preSum=0 < 2, 中间的正数都大于2了) ；然而这是错的：完全可以选择合适的矩阵如 -7 3 3 3, 其前一部分的和是-7 <0, 后一部分的和是9>2, 两者之和是2=2, 符合题目条件, 而解法中略去了。**因此不能使用这个剪枝。**


**接下来和单独一行元素, 找最大的连续多个元素和小于等于k的算法是一致的** 初始化set放一个0元素, 用set记录当前多行的Sum, 如果j行之前存在位置i满足curSum[j] - curSum[i] <= K, 表明以位置j结尾的序列有满足条件不大于K的, 那么可以找到最小的curSum[i]满足上述的不等式, 对应位置即是以j结尾且相加和不大于K的最大序列的开始位置, 比较curSum[j] - curSum[i]决定是否更新。甚至：如果有和是k的就直接return k

上段话中的curSum[i]相当于代码中的*iter, curSum[j]相当于代码中的preSum, 用set的原因是方便使用lower_bound(二分查找第一个>=preSum-k的下标。set初始化0这个哨兵值是：如果用到了这个值，说明存在一个从第一行到当前行的矩阵元素和满足条件

时间复杂度：O(m^2*nlog(n))

# **代码**

```cpp
class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int rows = matrix.size();
		if (!rows) return 0;
		int cols = matrix[0].size();
		if (!cols) return 0;

		int res = INT_MIN;
		for (int colstart = 0; colstart < cols; ++colstart)
		{
			vector<int> prerowSum(rows, 0);
			for (int colend = colstart; colend < cols; ++colend)
			{
				for (int row = 0; row < rows; ++row)
					prerowSum[row] += matrix[row][colend];
				int preSum = 0;

				/*
				for (int row = 0; row < rows; ++row)
				{
					preSum += prerowSum[row];
					if (preSum <= k) res = max(res, preSum);
					if (preSum < 0) preSum = 0;
				}
				if (preSum < k) continue;   //直接剪枝, 这是因为不存在没有判断过的矩阵和<k且比现在的preSum还大了
				else preSum = 0;*/

				set<int> sumSet;
				sumSet.insert(0); //哨兵值, 如果lower_bound查到了这个值, 说明存在一个从第一行到当前行的矩阵元素和满足条件
				for (int r = 0; r < rows; ++r) {
					preSum += prerowSum[r];
					auto it = sumSet.lower_bound(preSum - k);  //查找第一个>=curSum-k的下标, 注意: sumSet是个升序排序的set
					if (it != sumSet.end())
					{
						if (preSum - *it == k) return k;   //直接返回k
						else res = max(res, preSum - *it);
					}
					sumSet.insert(preSum);
				}
			}
		}

		return res;
	}
};
```

# **欢迎批评指正**
