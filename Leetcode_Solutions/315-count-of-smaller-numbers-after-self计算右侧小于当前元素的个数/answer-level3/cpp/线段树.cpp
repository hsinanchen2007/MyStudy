### 解题思路
线段树操作，每次刷新一个点。代码逻辑稍微有点复杂。  见下一个线段数组解法。

### 代码

```cpp
class Solution {
public:

struct node {
	int lft;
	int rgt;
	int sum;
};

void BuildNodeTree(vector<node>& nodeTree, int x, int leftIndex, int rightIndex) {
	if (leftIndex == rightIndex) {
		nodeTree[x].lft = leftIndex;
		nodeTree[x].rgt = rightIndex;
		nodeTree[x].sum = 0;
		return;
	}
	int mid = (leftIndex + rightIndex) >> 1;
	BuildNodeTree(nodeTree, 2*x, leftIndex, mid);
	BuildNodeTree(nodeTree, 2*x + 1, mid + 1, rightIndex);
	nodeTree[x].sum = 0;
	nodeTree[x].lft = leftIndex;
	nodeTree[x].rgt = rightIndex;
}
int QueryTree(vector<node>& nodeTree, int x, int leftIndex, int rightIndex)
{
	if (leftIndex > rightIndex) {
		return 0;
	}
	if (leftIndex == nodeTree[x].lft && rightIndex == nodeTree[x].rgt) {
		return nodeTree[x].sum;
	}
	int mid = (nodeTree[x].lft + nodeTree[x].rgt) >> 1;
	if (leftIndex > mid) {
		return QueryTree(nodeTree, x*2 + 1, leftIndex, rightIndex);
	} else if (rightIndex <= mid) {
		return QueryTree(nodeTree, x*2, leftIndex, rightIndex);
	} else {
		return (QueryTree(nodeTree, x*2, leftIndex, mid) + QueryTree(nodeTree, x*2 + 1, mid + 1, rightIndex));
	}
}
void UpdTree(vector<node>& nodeTree, int x, int index)
{
	if (nodeTree[x].lft == nodeTree[x].rgt && nodeTree[x].lft == index) {
		nodeTree[x].sum++;
		return;
	}
	int mid = (nodeTree[x].lft + nodeTree[x].rgt) >> 1;
	if (index > mid) {
		UpdTree(nodeTree, 2*x + 1, index);
	} else {
		UpdTree(nodeTree, 2*x, index);
	}
	nodeTree[x].sum++;
}

vector<int> countSmaller(vector<int>& nums) {
	if (nums.empty()) {
		return vector<int>();
	}
	vector<int> sortedNum(nums);
	map<int, int> rankMap;
	sort(sortedNum.begin(), sortedNum.end());
	int index = 1;
	int lastNum = sortedNum[0];
	for (auto num: sortedNum) {
		if (lastNum != num) {
			index++;
			lastNum = num;
		}
		rankMap[num] = index;
	}
	vector<node> nodeTree(index<<4, node());
	BuildNodeTree(nodeTree, 1, 1, index);
	vector<int> results;
	for (int i = nums.size() - 1; i >= 0; i--) {
		int sumTemp = QueryTree(nodeTree, 1, 1, rankMap[nums[i]] - 1);
		results.insert(results.begin(), sumTemp);
		UpdTree(nodeTree, 1, rankMap[nums[i]]);
	}
	return results;
}
};
```