权值线段树，用来表示一段区间某个数出现的次数。

从后往前更新数并查询比自己小的数即可解决。


```
struct node
{
    int l,r,sum;
    node(){l=r=sum=0;}
}*tree;
vector<int>v;
int n;
void lsh()//离散化
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
int getid(int x)
{
    int res=lower_bound(v.begin(),v.end(),x)-v.begin();
    if(res>=v.size())return -1;
    return res+1;
}
void push_up(int x)
{
    tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
}
void build(int x,int l,int r)
{
    tree[x].l=l,tree[x].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
}
void update(int x,int v)
{
    int L=tree[x].l,R=tree[x].r;
    if(L==R)++tree[x].sum;
    else 
    {
        int mid=(L+R)>>1;
        if(mid>=v)update(x<<1,v);
        if(mid<v)update(x<<1|1,v);
        push_up(x);
    }
}
int query(int x,int l,int r)
{
    int L=tree[x].l,R=tree[x].r;
    if(1<=L&&R<=r)return tree[x].sum;
    else 
    {
        int mid=(L+R)>>1,ans=0;
        if(mid>=l)ans+=query(x<<1,l,r);
        if(mid<r)ans+=query(x<<1|1,l,r);
        return ans;
    }
    return 0;
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        v=nums;
        n=nums.size();
        if(n==0)return nums;
        tree=new node[(n+5)*5];
        lsh();
        build(1,1,v.size());
        vector<int>res(n);
        for(int i=n-1;i>=0;--i)
        {
            int r=getid(nums[i])-1;
            if(r<=0)res[i]=0;
            else res[i]=query(1,1,r);
            update(1,getid(nums[i]));
        }
        return res;
    }
}
```

