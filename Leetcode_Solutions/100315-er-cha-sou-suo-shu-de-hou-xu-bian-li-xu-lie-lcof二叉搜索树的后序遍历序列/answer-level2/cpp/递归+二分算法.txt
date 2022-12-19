用递归不用再赘述了，当确定一个根节点之后，如果采用线性遍历方式验证当前划分方式是否合法，每一层的子树均会导致一次全量的重复验证，因此时间复杂度为O(N * K)，N为节点数，K为数深度。

考虑对验证方式优化，对于每一个节点，均验证其是否超出最大值最小值即可。最大值最小值有低层的根节点的值逐步缩小。

实现方式如下，相比线性查找代码量更多一些。

```
bool helper(int start, int end, int nMin, bool bHasMin, int nMax, bool bHasMax)
	{
		if (start > end) return true;
		int val = pOrder->at(end);
		if (bHasMin && val <= nMin) return false;
		if (bHasMax && val >= nMax) return false;
		int left = start, right = end - 1, mid = 0;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (pOrder->at(mid) < val)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return helper(start, right, nMin, bHasMin, min(nMax, val), true)
			&& helper(right + 1, end - 1, max(nMin, val), true, nMax, bHasMax);
	}
	bool verifyPostorder(vector<int>& postorder) {
		pOrder = &postorder;
		return helper(0, postorder.size() - 1, INT_MIN, false, INT_MAX, false);
	}
	vector<int> *pOrder;
```

去掉了线性查找的部分，每一层没有重复遍历，时间复杂度为O(N)