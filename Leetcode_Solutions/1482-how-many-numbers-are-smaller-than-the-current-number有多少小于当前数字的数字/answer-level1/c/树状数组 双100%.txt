![图片.png](https://pic.leetcode-cn.com/ba254152402732e42e4b19ccdec1e92748506e577333b83d218b6cce6e0e50aa-%E5%9B%BE%E7%89%87.png)

```
///树状数组解法
class Solution
{
public:
    int tree[102];
    int MAXN=101;
    int query(int pos)
    {
        int ans = 0;
        while (pos > 0)
        {
            ans += tree[pos];
            pos -= pos & (-pos);
        }
        return ans;
    }
    void update(int pos, int val)
    {
        int ans = 0;
        while (pos <= MAXN)
        {
            tree[pos] += val;
            pos += pos & (-pos);
        }
    }
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        memset(tree,0,sizeof(tree));
        vector<int> vec;
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            update(nums[i]+1,1);
        }
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            vec.push_back((query(nums[i])));
        }
        return vec;
    }
};
```
