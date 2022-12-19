### 解题思路
此处撰写解题思路

### 代码

```cpp
class NumArray {

public:
	vector<int> tree;
	vector<int> data;
private:
	int leftchild(int index)
	{
		return index * 2 + 1;
	}
	int rightchild(int index)
	{
		return index * 2 + 2;
	}
	void buildTree(int index, int l, int r)
	{
		if (l == r)
		{
			tree[index] = data[l];
		}
		else
		{
			int mid = l + (r - l) / 2;
			int lc(leftchild(index)), lr(rightchild(index));
			buildTree(lc, l, mid);
			buildTree(lr, mid + 1, r);
			tree[index] = tree[lc] + tree[lr];
		}
	}
	int sumRange(int index, int l, int r, int queryL, int queryR)
	{
		if (l == queryL&&r == queryR) return tree[index];
		int mid = l + (r - l) / 2;
		int lc = leftchild(index);
		int lr = rightchild(index);
		if (queryL >= mid + 1)  return sumRange(lr, mid + 1, r, queryL, queryR);
		else if (queryR <= mid)  return sumRange(lc, l, mid, queryL, queryR);
		else  
        {
			return sumRange(lc, l, mid, queryL, mid) + sumRange(lr, mid + 1, r, mid + 1, queryR);
		}
	}
	
	void update(int index, int l, int r,int i,int val)
	{
		if (l == r)
		{
			tree[index] = val;
			return;
		}
		int mid = l + (r - l) / 2;
		int lc = leftchild(index);
		int lr = rightchild(index);
		//在左边就更新左节点 在右边就更新右节点
		if (i <= mid) update(lc, l, mid, i, val);
		else  update(lr, mid + 1, r, i, val);
		//最后更新父节点
		tree[index] = tree[lc] + tree[lr];  
	}

public:
	NumArray(vector<int>& nums) {
		if (nums.size() > 0)
		{
			for (auto v : nums)
			{
				data.push_back(v);
			}
			tree.resize(4 * data.size());
			buildTree(0, 0, data.size() - 1);
		}
	}

	int sumRange(int i, int j) {
		if (data.size() == 0) return 0;
		return sumRange(0, 0, data.size() - 1, i, j);
	}

	//把index为i的值更新为val
	void update(int i, int val)
	{
		if (data.size() == 0) return;
		data[i] = val;  //更新data
		//更新tree
		update(0, 0, data.size() - 1,i,val);
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
```