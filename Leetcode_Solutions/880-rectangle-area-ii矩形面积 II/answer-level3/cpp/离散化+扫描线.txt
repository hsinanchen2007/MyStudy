因为这题求的是面积的并集，所以相对简单。
我是从下到上扫描的。
先设置一个结构体类型为边edge，因为用的是扫描线，所以遇到下边给下边对应的区间+1，遇到上边给上边对应的区间-1，所以在结构体中存储线段左边的横坐标，线段右边的横坐标，线段的纵坐标，线段是下边还是上边，上边为-1，下边为1。
然后树的节点有三种，分别为cnt记录这个区间被完全覆盖的次数，len记录被覆盖区间的长度，weight为权重，因为离散化了，所以区间覆盖的数量并不等于区间的大小。（我这边写法并不是最好，但是省事。。）
然后这边线段树不需要pushdown，也不需要lazy标记，因为我们每次都是先更新+1，再更新-1，所以保证了区间的cnt肯定是>=0的。
然后如果下边区间被更新过了，这次需要更新-1了，下边区间被覆盖的len会pushup上来（cnt不需要pushup上来），所以无需担心问题。
pushup函数就是如果该区间被完全覆盖，那很简单，直接等于它的权重即可，如果未被完全覆盖，就等于它的孩子的权重的和即可。如果是叶子节点了，就为0。
build函数，其实就是初始化所有的cnt和len，并将每个区间的weight分配正确。
接下来将边排序，并将所有横坐标离散化，三连打一套sort，unique，lower_bound。
因为是求面积，所以比较简单。直接上一次更新后的覆盖区间长度*（这次纵坐标-上次纵坐标）即可。（肯定为正，因为我们就是按y排序的）
排序这边有个如果重边情况，y相等时将下边放在前面，因为如果先-1（可能）会使得cnt为负数，就导致错误了。
```
const int MOD=1e9+7;
const int MAXN=405;
class Solution {
public:
    using LL=long long;
    int tot=0;
    LL mp[MAXN];
    struct edge{
        int x1,x2,y,isup;
        void modify(int x1,int x2,int y,int isup){
            this->x1=x1,this->x2=x2,this->y=y,this->isup=isup;
        }
        bool operator<(const edge &_cmp)const{
            if(y==_cmp.y)return isup>_cmp.isup;
            return y<_cmp.y;
        }
    }e[MAXN];
    struct treenode{
        int cnt;
        LL len,weight;
        void clear(){
            len=cnt=0;
        }
    }s[MAXN<<2];
    void addedge(int x1,int y1,int x2,int y2){
        e[tot++].modify(x1,x2,y1,1);
        e[tot++].modify(x1,x2,y2,-1);
    }
    #define mid (l+(r-l>>1))
    inline void pushup(int p,int l,int r){
        if(l==r){
            s[p].len=s[p].cnt>0?s[p].weight:0;
        }else{
            s[p].len=s[p].cnt>0?s[p].weight:s[p<<1].len+s[p<<1|1].len;
        }
        s[p].len%=MOD;
    }
    void build(int p,int l,int r){
        s[p].clear();
        if(l==r){
            s[p].weight=mp[l+1]-mp[l];
            s[p].weight%=MOD;
            return;
        }
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        s[p].weight=s[p<<1].weight+s[p<<1|1].weight;
        s[p].weight%=MOD;
    }
    void modify(int p,int l,int r,int x,int y,int v){
        if(x<=l&&y>=r){
            s[p].cnt+=v;
            pushup(p,l,r);
            return;
        }
        if(x<=mid)modify(p<<1,l,mid,x,y,v);
        if(y>mid)modify(p<<1|1,mid+1,r,x,y,v);
        pushup(p,l,r);
    }
    #define lbx1(x) (lower_bound(mp+1,mp+m,e[(x)].x1)-mp)
    #define lbx2(x) (lower_bound(mp+1,mp+m,e[(x)].x2)-mp)
    int rectangleArea(vector<vector<int>>& rect) {
        int cnt=0;
        mp[0]=0;
        for(auto &i:rect){
            addedge(i[0],i[1],i[2],i[3]);
            mp[++cnt]=i[0],mp[++cnt]=i[2];
        }
        sort(e,e+tot);
        sort(mp+1,mp+cnt+1);
        int m=unique(mp+1,mp+cnt+1)-(mp+1);
        build(1,1,m-1);
        modify(1,1,m-1,lbx1(0),lbx2(0)-1,e[0].isup);
        LL ans=0,prev=s[1].len;
        for(int i=1;i<tot;++i){
            modify(1,1,m-1,lbx1(i),lbx2(i)-1,e[i].isup);
            ans+=prev*(e[i].y-e[i-1].y)%MOD;
            ans%=MOD;
            prev=s[1].len;
        }
        return (int)ans;
    }
};
```
