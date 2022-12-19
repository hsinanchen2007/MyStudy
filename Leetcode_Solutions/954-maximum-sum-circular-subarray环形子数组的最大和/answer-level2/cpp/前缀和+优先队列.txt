### 解题思路
遇到求数组子序列的极大、极小值问题，首先应该想到的是前缀和，将问题转换成求S[i] - S[j]的问题；
其次是注意滑窗的长度，当长度小于要求长度的时候，需要将最小和 同 0比较，取最小值；
大于要求长度的时候，需要注意不断的从队列里面将数弹出来，所以在这里用了一个node存储index信息，如果最小值是区间外面的，直接pop（）掉就行了。

### 代码

```cpp
class Solution {
public:
struct node {
	int sum;
	int index;
	node(int inputSum, int inputIndex) {
		sum = inputSum;
		index = inputIndex;
	}
};

struct cmp {
	bool operator() (node a, node b)
	{
		return a.sum > b.sum;
	}
};

int maxSubarraySumCircular(vector<int>& A) {
	int gap = A.size();
	for (int i = 0; i < gap; i++) {
		A.push_back(A[i]);
	}
	vector<node> S(A.size(), node(0, 0));
	S[0].sum = A[0];
	S[0].index = 0;
	for (int i = 1; i < S.size(); i++) {
		S[i].index = i;
		S[i].sum += S[i - 1].sum + A[i];
	}
	priority_queue<node, vector<node>, cmp> sumQueue;
	int results = S[0].sum;
	sumQueue.push(S[0]);
	for (int i = 1; i < A.size(); i++) {
		node frontMin = sumQueue.top();
		while (!sumQueue.empty() && frontMin.index + gap < i)
		{
			sumQueue.pop();
			frontMin = sumQueue.top();
		}
		int minFrontSum = frontMin.sum;
		if (i < gap) {
			minFrontSum = min(0, minFrontSum);
		}
		results = max(S[i].sum - minFrontSum, results);
		sumQueue.push(S[i]);
	}
	return results;
}
};
```