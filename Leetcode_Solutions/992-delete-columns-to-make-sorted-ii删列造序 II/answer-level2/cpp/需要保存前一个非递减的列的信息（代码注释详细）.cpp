### 解题思路
每一列可能会有以下几种情况：
1. 存在两个数递减情况a[j][i] < a[j-1][i]（需要讨论上一个非递减列k中a[j][k]（M） 和 a[j-1][k]（N）的情况）
	1. 若M < N，则符合条件（字符串比较大小从首位开始，若首位已经比较出来，则不进行后续判断）
	2. 若M = N，则该列已经不符合条件了
	3. 若M > N，**不可能**存在此情况（因为第k列是符合非递减条件的s）
2. 整列严格递增（该列任何时候都符合条件）
3. 该列非严格递增，即存在a[j][i] == a[j-1][i]，此时不用管（可以放到后面i+1列的时候进行判断）

代码中，首先找出第一个非严格递增的序列起始点start，并由此更新flag（其中flag[i]表明第i个元素和第i-1个元素之间形成了**严格**的大小关系，不包含相等）。依次遍历每一列，利用之前的flag信息作出判断，并随之更新flag。（具体代码都做了标注，有疑问欢迎探讨~）

想思路花了近一个小时，写代码调试又花了一个小时（主要是下标问题，越界，纵横坐标颠倒等毛病），还是挺菜的~
### 代码

```cpp
class Solution {
public:
	void setFlag(bool *flag, int index, vector<string>& A) {
		for (int i = 1; i < A.size(); i++) {
			if (A[i][index] > A[i - 1][index]) {
				flag[i] = true; // 表明第i行和第i-1行之间严格的大小关系已经确定了。
			}
		}
	}

	int minDeletionSize(vector<string>& A) {
		bool *flag = new bool[A.size()]{ false }; // flag[i]表明第i个元素和第i-1个元素之间形成了严格的大小关系
		// 找出start点
		int start = -1;
		for (int i = 0; i < A[0].size() && start<0; i++) {
			int j = 1;
			for (; j < A.size(); j++) {
				if (A[j][i] < A[j - 1][i]) {
					break;
				}
			}
			if (j == A.size()) start = i; // 表明第i列首先出现非递减序列
		}
		if (start < 0) return A[0].size(); // 不存在该序列
		setFlag(flag, start, A); // 更新flag表

		// 开始遍历string
		int count = (start > 0) ? start : 0; // 开始计数
		for (int i = start + 1; i < A[0].size(); i++) {
			int j = 1;
			for (; j < A.size(); j++) {
				if (A[j][i] < A[j-1][i] && flag[j] == false) {
					count++; // 出现递减序列但是之前记录的信息表明A[k][i]和A[k-1][i]并非严格递增关系
					break; // 即A[k][i] <= A[k-1][i]，所以此列不符合条件。
				}
			}
			if (j == A.size()) { // 若当前列满足条件，更新flag表
				setFlag(flag, i, A);
			}
		}
		return count;
	}
};
```