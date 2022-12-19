### 解题思路
线段树模板题

### 代码

```cpp
class Solution {
/*
看作一棵递归树，如果是叶子节点就治，如果是非叶子节点就分。
怎么分？
修改函数的参数即可。
怎么治？
不知道，但我会线段树。
lsum怎么合并？
max{左数组lsum，左数组+右数组lsum}
rsum怎么合并？
max{右数组rsum，右数组+左数组rsum}
*/
public:
    struct node
    {
        int l,r;
        int val;
        int lsum,rsum,allsum;
    }T[40000];
    int cnt=1;
    void up(int p)
    {
        T[p].val=max(T[p<<1].val,max(T[p<<1|1].val,T[p<<1].rsum+T[p<<1|1].lsum));
        T[p].lsum=max(T[p<<1].lsum,T[p<<1].allsum+T[p<<1|1].lsum);
        T[p].rsum=max(T[p<<1|1].rsum,T[p<<1|1].allsum+T[p<<1].rsum);
        T[p].allsum=T[p<<1].allsum+T[p<<1|1].allsum;
    }
    void build(vector<int>& nums,int p,int l,int r)
    {
        T[p].l=l;
        T[p].r=r;
        if(l==r)
        {
            T[p].allsum=T[p].val=T[p].lsum=T[p].rsum=nums[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(nums,p<<1,l,mid);
        build(nums,p<<1|1,mid+1,r);
        up(p);
    }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        build(nums,1,0,n-1);
        return T[1].val;
    }
};
```