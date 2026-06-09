### 解题思路
此处撰写解题思路

### 代码

```cpp
class NumArray {

private:
    vector<int> tree;
    vector<int> data;
    int leftchild(int index)
    {return index*2+1;}
    int rightchild(int index)
    {return index*2+2;}
    void buildTree(int index,int l,int r)
    {
        if(l==r)
        {
            tree[index] = data[l];
        }
        else
        {
            int mid = l + (r-l)/2;
            int lc(leftchild(index)),lr(rightchild(index));
            buildTree(lc,l,mid);
            buildTree(lr,mid+1,r);
            tree[index] = tree[lc]+tree[lr];
        }
    }
    int sumRange(int index,int l,int r,int i,int j)
    {
        if(l==i&&r==j) return tree[index];
        int mid = l+(r-l)/2;
        int lc(leftchild(index)),lr(rightchild(index));
        if(j<=mid) return sumRange(lc,l,mid,i,j);
        if(i>=mid+1) return sumRange(lr,mid+1,r,i,j);
        else
        {
            return sumRange(lc,l,mid,i,mid)+sumRange(lr,mid+1,r,mid+1,j);
        }
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
        return sumRange(0,0,data.size()-1,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```