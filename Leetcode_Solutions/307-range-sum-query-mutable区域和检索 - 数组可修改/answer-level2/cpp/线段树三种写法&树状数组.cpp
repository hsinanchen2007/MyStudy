堆式存储：开4倍大小，$\text{[l,r]}$存储在下标为$\text{1}$的位置，$\text{[l,(l+r)/2]}$存储在$\text{1*2}$的下标，$\text{[(l+r)/2+1,r]}$存储在$\text{1*2+1}$的下标，这样耗费大小为$\text{4n}$。
好处是代码非常简单，不用担心写错。

```
class NumArray {
public:
    vector<int> sum,*nums;
    int n;
    void build(int o,int l,int r){
        if(l==r){
            sum[o]=(*nums)[l];
            return;
        }
        int mid=l+r>>1;
        build(o<<1,l,mid);
        build(o<<1|1,mid+1,r);
        sum[o]=sum[o<<1]+sum[o<<1|1];
    }
    void modify(int o,int l,int r,int x,int v){
        if(l==r){
            sum[o]=v;
            return;
        }
        int mid=l+r>>1;
        if(x<=mid)modify(o<<1,l,mid,x,v);
        else modify(o<<1|1,mid+1,r,x,v);
        sum[o]=sum[o<<1]+sum[o<<1|1];
    }
    int query(int o,int l,int r,int x,int y){
        if(x<=l&&y>=r)return sum[o];
        int mid=l+r>>1,ans=0;
        if(x<=mid)ans+=query(o<<1,l,mid,x,y);
        if(y>mid)ans+=query(o<<1|1,mid+1,r,x,y);
        return ans;
    }
    // 4倍大小
    NumArray(vector<int>& nums):n(nums.size()),sum(nums.size()<<2) {
        this->nums=&nums;
        if(n)build(1,0,n-1);
    }
    
    void update(int i, int val) {
        modify(1,0,n-1,i,val);
    }
    
    int sumRange(int i, int j) {
        return query(1,0,n-1,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
```

动态开点：创建三个数组，或者用结构体，指针之类的都可以，分别存储左右孩子的下标（或者指针），这样耗费大小为$\text{6n}$。
好处是，例如以后的可持久化数据结构，使用动态开点就很方便可以把另一个版本的修改嫁接在这个版本上。
```
class NumArray {
public:
    vector<int> lc,rc,sum,*nums;
    int node_tot=0,root;
    int n;
    void build(int &o,int l,int r){
        o=++node_tot;
        if(l==r){
            sum[o]=(*nums)[l];
            return;
        }
        int mid=l+r>>1;
        build(lc[o],l,mid);
        build(rc[o],mid+1,r);
        sum[o]=sum[lc[o]]+sum[rc[o]];
    }
    void modify(int o,int l,int r,int x,int v){
        if(l==r){
            sum[o]=v;
            return;
        }
        int mid=l+r>>1;
        if(x<=mid)modify(lc[o],l,mid,x,v);
        else modify(rc[o],mid+1,r,x,v);
        sum[o]=sum[lc[o]]+sum[rc[o]];
    }
    int query(int o,int l,int r,int x,int y){
        if(x<=l&&y>=r)return sum[o];
        int mid=l+r>>1,ans=0;
        if(x<=mid)ans+=query(lc[o],l,mid,x,y);
        if(y>mid)ans+=query(rc[o],mid+1,r,x,y);
        return ans;
    }
    // 数组都开2倍大小，动态开点
    NumArray(vector<int>& nums):n(nums.size()),lc(nums.size()<<1),rc(nums.size()<<1),sum(nums.size()<<1) {
        this->nums=&nums;
        if(n)build(root,0,n-1);
    }
    
    void update(int i, int val) {
        modify(root,0,n-1,i,val);
    }
    
    int sumRange(int i, int j) {
        return query(root,0,n-1,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
```
更紧凑的存储方式：发现动态开点只需要$\text{2n}$空间（存储区间和信息，其他左右孩子不算在内），其实堆式存储的最后一层是有很多冗余的，所以有一种方法可以将区间$\text{[0,n-1]}$映射到$\text{[0,2n-1]}$这个下标。下标表示为$\text{(l+r)|(l!=r)}$即可，但是因为写起来比较烦，所以使用宏定义。

```
class NumArray {
public:
    vector<int> sum,*nums;
    int n;
    int getPosition(int l,int r){
        return l+r|(l!=r);
    }
#define mid (l+r>>1)
#define slf getPosition(l,r)
#define lc getPosition(l,mid)
#define rc getPosition(mid+1,r)
    void build(int l,int r){
        if(l==r){
            sum[slf]=(*nums)[l];
            return;
        }
        build(l,mid);
        build(mid+1,r);
        sum[slf]=sum[lc]+sum[rc];
    }
    void modify(int l,int r,int x,int v){
        if(l==r){
            sum[slf]=v;
            return;
        }
        if(x<=mid)modify(l,mid,x,v);
        else modify(mid+1,r,x,v);
        sum[slf]=sum[lc]+sum[rc];
    }
    int query(int l,int r,int x,int y){
        if(x<=l&&y>=r)return sum[slf];
        int ans=0;
        if(x<=mid)ans+=query(l,mid,x,y);
        if(y>mid)ans+=query(mid+1,r,x,y);
        return ans;
    }
    // 2倍大小
    NumArray(vector<int>& nums):n(nums.size()),sum(nums.size()<<1) {
        this->nums=&nums;
        if(n)build(0,n-1);
    }
    
    void update(int i, int val) {
        modify(0,n-1,i,val);
    }
    
    int sumRange(int i, int j) {
        return query(0,n-1,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
```

最后是树状数组，树状数组写起来非常简单，并且比线段树有更小的常数。
但是树状数组的下标一般是从$1$开始，所以要注意一下，另外初始化的时候可以使用前缀和数组$\text{sum[i]=prefixsum[i]-prefixsum[i-lowbit(i)]}$来进行$O(n)$的初始化，查询的时候也把下标平移$1$就可以了。

```
class NumArray {
public:
    vector<int> sum,*nums;
    int n;
    int lowbit(int x){
        return x&-x;
    }
    void modify(int x,int v){
        for(;x<=n;x+=lowbit(x)){
            sum[x]+=v;
        }
    }
    int query(int x){
        int ans=0;
        for(;x;x-=lowbit(x)){
            ans+=sum[x];
        }
        return ans;
    }
    NumArray(vector<int>& nums):n(nums.size()),nums(&nums),sum(nums.size()+1) {
        // 先做一个前缀和数组
        vector<int> pre(sum);
        for(int i=1;i<=n;++i){
            pre[i]=nums[i-1];
            pre[i]+=pre[i-1];
        }
        for(int i=1;i<=n;++i){
            sum[i]=pre[i]-pre[i-lowbit(i)];
        }
    }
    
    void update(int i, int val) {
        int d=val-(*nums)[i];
        (*nums)[i]=val;
        modify(i+1,d);
    }
    
    int sumRange(int i, int j) {
        return query(j+1)-query(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
```
