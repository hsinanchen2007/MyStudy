```
struct Node{//线段树节点
    int l,r;//l为离散化之后的区间左边界，r为离散化之后的区间右边界
    int c;//该区间被覆盖次数
    int len,ll,rr;//len为线段树维护的区间信息，这里表示矩形边覆盖区间的长度，由于建筑的底y=0,所以len在这里表示高
};
struct Line{
    int x,y1,y2;//垂直于x轴的矩形边的x坐标和两端的y值
    int f;//矩形左边为入边f=1,右边为出边f=-1，用来统计区间覆盖的次数
};
const int maxn=20010;//最多有10000个矩形，2*10000条边
class Solution {//该线段树模板也可用来求矩形面积问题,扫描线 
private:
    Line line[maxn];//存储矩形的左边和右边
    int y[maxn];//离散化的y值和真实y值之间的映射
    Node Tree[4*maxn];//线段树
public:
    void build(int rt,int l,int r){//建线段树
        Tree[rt].l=l;
        Tree[rt].r=r;
        Tree[rt].c=0,Tree[rt].len=0;
        Tree[rt].ll=y[l];
        Tree[rt].rr=y[r];
        if(l+1==r) return ;
        int m=(l+r)>>1;
        build(rt<<1,l,m);
        build(rt<<1|1,m,r);
    }
    void calen(int rt){//计算覆盖的线段长度
        if(Tree[rt].c>0){
            Tree[rt].len=Tree[rt].rr-Tree[rt].ll;
            return ;
        }
        if(Tree[rt].l+1==Tree[rt].r) Tree[rt].len=0;
        else Tree[rt].len=Tree[rt<<1].len+Tree[rt<<1|1].len;
    }
    void update(int rt,Line e){//加入边更新覆盖的线段长度
        if(e.y1==Tree[rt].ll&&Tree[rt].rr==e.y2){
            Tree[rt].c+=e.f;
            calen(rt);
            return ;
        }
        if(e.y2<=Tree[rt<<1].rr) update(rt<<1,e);
        else if(e.y1>=Tree[rt<<1|1].ll) update(rt<<1|1,e);
        else{
            Line tmp=e;
            tmp.y2=Tree[rt<<1].rr;
            update(rt<<1,tmp);
            tmp=e;
            tmp.y1=Tree[rt<<1|1].ll;
            update(rt<<1|1,tmp);
        }
        calen(rt);
    }
    static bool cmp(const Line& a,const Line& b){
        return a.x<b.x;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty()) return {};
        int t=0;//离散化y值，给y值从0编号
        y[0]=0;
        t++;
        for(auto b:buildings){
            //加入矩形左边
            line[t].x=b[0];
            line[t].y1=0;
            line[t].y2=b[2];
            line[t].f=1;
            y[t]=b[2];//给当前矩形y值离散化，矩形另外的一个y坐标为0，开始已经离散化了这里不用重复
            t++;
            //加入矩形右边
            line[t].x=b[1];
            line[t].y1=0;
            line[t].y2=b[2];
            line[t].f=-1;
            t++;
            
        }
        sort(line+1,line+t,cmp);//将边按x坐标排序
        sort(y,y+t);//将离散化的值由小到大排序
        build(1,0,t-1);//构建线段树
        vector<vector<int>> res;
        //下面代码改下可以用来求矩形围成的面积
        for(int i=1;i<t;i++){
            update(1,line[i]);
            int x,y;
            x=line[i].x;
            y=Tree[1].len;
            if(!res.empty()&&res.back()[0]==x){//如果当前边和前一个边重合，弹出前一个关键点
                res.pop_back();
            }
            if(res.empty()||res.back()[1]!=y){//如果当前边和前一个边y值不相等，加入当前关键点
                res.push_back(vector<int>{x,y});
            }
        }
        return res;
    }
};
```
