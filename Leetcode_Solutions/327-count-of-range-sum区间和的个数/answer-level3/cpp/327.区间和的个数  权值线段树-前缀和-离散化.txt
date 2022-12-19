![image.png](https://pic.leetcode-cn.com/42629b23671f910845a0a0b2a82711415b2f2d4dec08ace92839eec0b4f10e73-image.png)

本题单纯使用前缀和需要枚举区间左端点和右端点，复杂度n²，太慢;

维护前缀和的权值线段树，每到一个pre[i]就在树内查询有多少值在pre[i]-upper到pre[i]-lower之间，并向树内update pre[i]离散化后的值，复杂度nlogn;

```
class Solution {
public:
    typedef long long ll;
    int len,_lower,_upper;
    struct node
    {
        int l,r;
        ll sum;
        node(){l=r=sum=0;}
    }*tree;
    vector<ll> pre,v;
    void push_up(int x)
    {
        tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
    }
    void build(int x,int l,int r)
    {
        tree[x].l=l,tree[x].r=r;
        if(l==r){
            return;
        }
        int mid=(l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
    }
    void update(int x,int v)
    {
        int L=tree[x].l,R=tree[x].r;
        if(L==R&&L==v)
        {
            ++tree[x].sum;
            return;
        }
        int mid=(L+R)>>1;
        if(mid>=v)update(x<<1,v);
        if(mid<v)update(x<<1|1,v);
        push_up(x);
    }
    int query(int x,int l,int r)
    {
        int L=tree[x].l,R=tree[x].r;
        if(l<=L&&R<=r)
        {
           return tree[x].sum;
        }
        int mid=(L+R)>>1,ans=0;
        if(mid>=l)ans+=query(x<<1,l,r);
        if(mid<r)ans+=query(x<<1|1,l,r);
        return ans;
    }
    int getid(ll x)//对于pre[i]-upper使用lower_bound
    {
        int res = lower_bound(v.begin(),v.end(),x)-v.begin();
        if(res<v.size()&&v[res]>=x)return res+1;
        else return -1;
    }
    int getid2(ll x)//对于pre[i]-lower使用upper_bound
    {
        int res = upper_bound(v.begin(),v.end(),x)-v.begin();
        if(res<v.size()&&v[res]>x)return res;
        else return -1;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        len=nums.size();
        if(len==0)return 0;
        ll sum=0;
        for(int i=0;i<len;++i){sum+=nums[i],pre.push_back(sum);}
        v=pre;v.push_back(0);
        sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());//v数组，离散化后的前缀和数组，用来快速查找;
        _lower=lower,_upper=upper;
        int vlen=v.size();
        tree=new node[(vlen+10)*5];
        build(1,1,vlen);
        int res=0;
        update(1,getid(0));
        for(int i=0;i<len;++i)
        {
            int l=getid(pre[i]-upper),r=getid2(pre[i]-lower);
            if(l==-1&&r==-1){;}
            else 
            {
                if(l==-1)l=vlen;
                if(r==-1)r=vlen;
                res+=query(1,l,r);
            }
            update(1,getid(pre[i]));
        }
        return res;
    }
};
```
