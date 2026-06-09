### 解题思路
此题目非常巧妙，按照正常思路优化往往在遍历树上做手脚，但比较恶心的用例是 如果树的深度非常大，这样时间复杂度会降低到O(N^2) ,50000量级肯定是不达标的。如果先序遍历整棵树，那么每个子树的节点其实都是连续的，因此可以使用线段树的来实现区间求和，这样时间复杂度度将降到O(N*log(N))满足要求。如图：
![image.png](https://pic.leetcode-cn.com/13a0af171a1609891f6941e87d3e82560a81ea7b5eb1a3d555addf5aed071d82-image.png)
先序遍历后 1、2、3、5、6、4   假如求1节点的子树就是1~4所在位置节点求和，2节点为2~5节点求和。通过先序遍历将会求出某个节点子树的区间范围。
现在需要注意两种操作，一种是仅仅增加当前节点，一种为此节点及其子孙均增加相应值。
第一种情况处理比较简单，只要此节点的祖先节点均增加此值即可。
第二种情况比较复杂，为了优化性能，不对子区间进行增加，否则如果对根节点操作的复杂度将是O(N),这肯定完全不可接受，因此此值放在查询实计算。因此第二种操作此节点及其祖先节点均增加此子树节点数*操作值，并且用另外变量标记在此节点第二种操作的总和，这样在查询的时候在把此操作传下来就可以避免遍历所有子孙。


### 代码

```cpp
typedef long long LL;
LL BASE=pow(10,9)+7;

class Node {
public:
    Node* l;
    Node* r;
    int s;
    int e;
    int m;
    LL sum;   ///节点修改
    LL val;   ///区间修改，对子孙节点求和才需要，本节点不需要
    bool tag;   ///是否为叶子节点，true为叶子节点
    Node(int s, int e) : l(nullptr), r(nullptr), s(s), e(e), m((s+e)/2),sum(0), val(0), tag(true) {}
    Node* Left() {
        if (s == e) return nullptr;
        l = l ? l : new Node(s, m);
        return l;
    }
    Node* Right() {
        if (s == e) return nullptr;
        r = r ? r : new Node(m+1, e);
        return r;
    }
    void update(int start, int end, int newVal) {
        //cout<<start<<" "<<end<<endl;

        sum+=(LL)newVal*(end-start+1); 
        sum%=BASE;
        if (s == start && e == end){
            val += newVal;
            return;
        }
        if (tag) {
            Left()->update(s, m, 0);
            Right()->update(m+1, e, 0);
            tag = false;
        }
        if (end <= m) Left()->update(start, end, newVal);
        else if (start >= m+1) Right()->update(start, end, newVal);
        else {
            Left()->update(start, m, newVal);
            Right()->update(m+1, end, newVal);
        }
    }
    int query(int start, int end,LL add) {
        LL res=0;
        if (s == start && e == end){
            res=sum+add*(end-start+1);
            res%=BASE;
            return res;
        } 
        add+=val;
        
        if (tag) {
            res=add*(end-start+1);
            res%=BASE;
            return res;
        }
        
        if (end <= m) return Left()->query(start, end,add);
        if (start >= m+1) return Right()->query(start, end,add);
        return (Left()->query(start, m,add)+Right()->query(m+1, end,add))%BASE;
    }
};

class Solution {
public:
    vector<int> vIN;
    vector<int> vOUT;
    void dfs(vector<vector<int>>& vSun,int node,int &dfn){
        vIN[node]=++dfn;
        for(auto x:vSun[node]){
            dfs(vSun,x,dfn);
        }
        vOUT[node]=dfn;
    }
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
   
        vector<vector<int>> vSun(n+1);
        vIN=vector<int>(n+1);
        vOUT=vector<int>(n+1);
        for(auto ls:leadership){
            vSun[ls[0]].push_back(ls[1]);
        }
        int dfn=-1;
        dfs(vSun,1,dfn);
        Node lTree(0,n-1);

        vector<int> vAns;
        for(auto op:operations){
            int now=op[1];
            if(op[0]==1){
                lTree.update(vIN[op[1]],vIN[op[1]],op[2]);
            }else if(op[0]==2){
                lTree.update(vIN[op[1]],vOUT[op[1]],op[2]);

            }else{

                vAns.push_back(lTree.query(vIN[op[1]],vOUT[op[1]],0));
            }
        }
        
        
        return vAns;
    }
};
```