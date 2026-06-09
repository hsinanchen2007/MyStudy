#### 解题思路：
看到动态维护序列上，某一个区间的某一个值域内数字的个数的问题，就直接上树套树了。

定义一个树状数组维护数字的值，树状数组的每一个节点都是一个线段树维护区间，那么某一个区间的某一个值域内数字的个数的问题就可以通过在树状数组上提取一段值域，然后在其所对应的线段树上提取一段区间来查询。
这个数据结构的功能有：
* $O(log^2 n)$ 的时间复杂度查询序列一个区间内一个值域里的数字出现了多少次。
* $O(log^2 n)$ 的时间复杂度修改序列上的一个数字。

再回去看这个问题：

初始化的时候，就是建立这样的一颗树状数组套线段树。

查询的时候，需要利用题目中绝对众数的条件：
* 一个区间中的绝对众数只有一个
* 一个数字集合当且仅当包含绝对众数，这个集合内的数字的出现次数才会大于 `threshold`。
 
那么我们可以通过在给定区间上二分一个最小的 `x`，使得 `1~x` 之间的数字出现次数大于等于 `threshold`。
那么这个 `x` 是答案的唯一候选，然后在之前的数据结构上查询 `x` 在给定区间内的出现次数就可以了。如果大于 `threshold` 则输出 `x`，否则输出 `-1`。

初始化的复杂度是 $O(n log^2 n)$，查询的总复杂度是二分乘数据结构查询的复杂度 $O(q log^3 n)$。但是，二分的过程和树状数组上查询的过程本质相同，所以可以合并一起做。于是，查询的总复杂度就变成了 $O (q log^2 n)$。

这个做法本身并不优秀，因为使用线段树可以做到 $O(n log n)$ 初始化 + $O(q log n)$ 总查询复杂度。不过，还是想写成题解分享一下，树套树大法好！

另外，这题目翻译的时候，“在线”两个字最好不需要少，因为这个查询的确是不能离线的。
#### 代码：

```cpp [-C++]
const int MAXN=2e4+50;
const int MAXM=2e4;

struct BTree{ int ch[2], sum; }node[MAXN*100];
int root[MAXN], numn, PL, PR;

inline int lowbit(int x){ return x&-x; }

void init(){ 
    numn=0;
    memset(root, 0, sizeof(root));
}

void insertNode(int &x, int l, int r, int p){
    if (!x) { x=++numn; node[x].ch[0]=node[x].ch[1]=node[x].sum=0; }

    ++node[x].sum;

    if (l<r){
        int m=(l+r)/2;
        if (p<=m){
            insertNode(node[x].ch[0], l, m, p);
        }else insertNode(node[x].ch[1], m+1, r, p);
    }
}

void insertTree(int p, int v){
    for (int i=v; i<=MAXM; i+=lowbit(i)) 
        insertNode(root[i], PL, PR, p);
}

int queryNode(int x, int l, int r, int left, int right){
    if (!x) return 0;
    if (left<=l && r<=right) return node[x].sum;

    int m=(l+r)/2, ret=0;
    if (left<=m) ret+=queryNode(node[x].ch[0], l, m, left, right);
    if (m+1<=right) ret+=queryNode(node[x].ch[1], m+1, r, left, right);

    return ret;
}

int queryTree(int left, int right, int v){
    int ret=0;
    for (int i=v; i>0; i-=lowbit(i))
        ret+=queryNode(root[i], PL, PR, left, right);
    return ret;
}

class MajorityChecker {
public:
    MajorityChecker(vector<int>& a) {
        PL=0, PR=a.size()-1;
        init();
        for (int i=PL; i<=PR; i++) insertTree(i, a[i]);
    }
    
    int query(int left, int right, int threshold) {
        int ans=0, now=32768/2, k=threshold;
        while(now){
            if (now+ans>MAXM) { now/=2; continue; }
            int v=queryNode(root[ans+now], PL, PR, left, right);
            if (v<k) { k-=v; ans+=now; }
            now/=2;
        }
        
        int cnt=queryTree(left, right, ans+1) - queryTree(left, right, ans);
        return cnt>=threshold?ans+1:-1;
    }
};

```