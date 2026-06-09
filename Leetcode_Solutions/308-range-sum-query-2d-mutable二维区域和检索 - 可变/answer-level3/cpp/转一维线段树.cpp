线段树可以用来解决频繁对区间查询和修改一类的题，求[天际线问题的题解](https://leetcode-cn.com/problems/the-skyline-problem/solution/sao-miao-xian-chi-san-hua-xian-duan-shu-mo-ban-ke-/)。
其实模板基本相似，难点是怎么把问题求解转为对区间的查询修改。
```
class NumMatrix {
private:
    vector<vector<int>>& matrix;
    vector<int> rangesum;//维护区间和信息
public:
    int idx(int r,int c){//矩阵坐标求区间下标
        return r*matrix[0].size()+c;
    }
    int rn(int idx){//区间下标求矩阵行号
        return idx/matrix[0].size();
    }
    int cn(int idx){//区间下标求矩阵列号
        return idx%matrix[0].size();
    }
    void build(int rt,int l,int r){//建线段树，rt为线段树节点号，l,r为该节点维护的左右区间边界
        if(l==r){
            rangesum[rt]=matrix[rn(l)][cn(l)];
            return ;
        }
        int m=(l+r)>>1;
        build(rt<<1,l,m);
        build(rt<<1|1,m+1,r);
        pushup(rt);
    }
    void pushup(int rt){//由当前节点的左右孩子区间和求当前节点区间和
        rangesum[rt]=rangesum[rt<<1]+rangesum[rt<<1|1];
    }
    void update(int i,int val,int rt,int l,int r){//区间点修改
        if(l==r){
            rangesum[rt]+=val;
            return ;
        }
        int m=(l+r)>>1;
        if(i<=m) update(i,val,rt<<1,l,m);
        else update(i,val,rt<<1|1,m+1,r);
        pushup(rt);
    }
    int query(int i,int j,int rt,int l,int r){//区间和查询
        if(i<=l&&r<=j){
            return rangesum[rt];
        }
        int m=(l+r)>>1;
        int ans=0;
        if(i<=m) ans+=query(i,j,rt<<1,l,m);
        if(j>m) ans+=query(i,j,rt<<1|1,m+1,r);
        return ans;
    }
    NumMatrix(vector<vector<int>>& mx):matrix(mx){
        if(mx.empty()||mx[0].empty()) return ;
        int sz=mx.size()*mx[0].size();
        rangesum=vector<int>(sz<<2);
        build(1,0,sz-1);//建线段树
    }
    
    void update(int row, int col, int val) {
        if(matrix.empty()||matrix[0].empty()) return ;
        int sz=matrix.size()*matrix[0].size();
        int addv=val-matrix[row][col];//当前值与原始值得差，用来对线段树进行点修改即和为减去原来的值加上新值
        update(idx(row,col),addv,1,0,sz-1);
        matrix[row][col]=val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(matrix.empty()||matrix[0].empty()) return 0;
        int sz=matrix.size()*matrix[0].size();
        int ans=0;
        for(int i=row1;i<=row2;i++){//按矩阵的行求各行表示的区间和
            ans+=query(idx(i,col1),idx(i,col2),1,0,sz-1);
        }
        return ans;
    }
};

```
