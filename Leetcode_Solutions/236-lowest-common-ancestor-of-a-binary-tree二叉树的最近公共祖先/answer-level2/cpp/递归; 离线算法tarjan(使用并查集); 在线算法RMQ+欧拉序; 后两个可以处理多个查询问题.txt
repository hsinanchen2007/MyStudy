1. 递归
``` c++
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // <1> 递归 如果p和q在一边, 我们返回那一边它们的最近祖先; 在两边, 那么最近祖先就是root;遇到了p或者q, 就返回p或q, 否则返回NULL
        if (root == nullptr|| root == p || root == q ) {
            return root;
        } 
            
        TreeNode* left =  lowestCommonAncestor(root->left, p, q); //在左子树和右子树中分别去找p,q的最近公共祖先
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) // p和q分别在root的左右两棵子树, 那么root就是最近公共祖先
            return root;
        else if(left == nullptr) // 说明p和q都不在左子树里, 那么只能返回右子树的结果
            return right;
        else if(right == nullptr)// 说明p和q都不在右子树里, 只能返回左子树的结果
            return left;      
        else return nullptr; // 这棵子树没有p或q 返回nullptr
}
```
2.  离线的Tarjan算法, 也就是说有q个查询, 在一次dfs遍历中全部完成 需要使用并查集
``` c++
class unionFind{
    public:
    unordered_map<TreeNode*, TreeNode*> arr;
    unionFind(){ //初始化
       
    }

    void Union(TreeNode* first,TreeNode* second){
        TreeNode* i=find(first); 
        TreeNode* j=find(second);
        if(i!=j){ //如果祖先不同 真的合并
            arr[j]=i;
        }
    }

    TreeNode* find(TreeNode* cur){ //路径压缩的find
        if(arr.count(cur)==0)
            arr[cur]=cur;
        if(arr[cur]!=cur){
            TreeNode* ans=find(arr[cur]);
            arr[cur]=ans;
            return ans;
            // return arr[cur]=find(arr[cur]); //直接和最终的答案接起来
        }
        else 
            return cur;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        // <2> 离线的Tarjan算法, 也就是说有q个查询, 在一次dfs遍历中全部完成  https://www.cnblogs.com/JVxie/p/4854719.html
            // 1.任选一个点为根节点，从根节点u开始, 标记根节点被访问过
            // 2.递归调用dfs遍历根节点的所有子节点v, 每调用一次dfs, 把v合并到u上, 注意一定是把v合并到u上, u是更高级
            // 3.寻找与当前点u有询问关系的点q。
            // 4.若是q已经被访问过了，则可以确认u和q的最近公共祖先就是q的父亲f


        // 这个写法尽可能地想要实现一次dfs遍历, 把所有的q个查询都完成, 所以大量地使用了unordered_map
        // 这么实现的一个小问题是, p的查询中有q,q的查询中有p, 但是最终返回的结果是, 要么是p记录着正确结果, 要么是q记录着正确结果, 另外一个显示得是NULL
            // 对于怎么好地表示这个查询, 怎么好地记录结果, 怎么好地表示并查集,还是没有好的办法
        
        unordered_map<TreeNode*, vector<TreeNode*>> query; // 记录结果, 如果有q个查询, 在query中实际上有2q个项
        unordered_map<TreeNode*, vector<TreeNode*>> res;   // 记录结果, 如果有q中查询, 在res中有2q个项, 其中q个记录着正确答案, 剩下q个记录着NULL
        unordered_set<TreeNode*> visited; // 记录某个结点是否被访问过
        query[p]={q}; // 建立query 注意查询是双向的, 对称的
        query[q]={p};
        unionFind uF; //并查集
        dfs(root,query, res,uF, visited); // 进行dfs
        if(res[p][0]) // 由于res[p][0]和res[q][0]一个记录着正确答案, 一个记录着NULL, 必须把正确答案挑选出来
            return res[p][0];
        else 
            return res[q][0];

    }


    // <2> 离线的Tarjan算法, 也就是说有q个查询, 在一次dfs遍历中全部完成  https://www.cnblogs.com/JVxie/p/4854719.html
    void dfs(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>&query, unordered_map<TreeNode*, vector<TreeNode*>>&res, unionFind&uF,unordered_set<TreeNode*>&visited){
        if(root){
            visited.insert(root); // 现在设置root访问过, 还是把这个放在所有的子节点访问过后, 我觉得没区别, 因为在并查集中查询的时候, 没访问过的结点会被创建, 同时把父亲设置为自己
            if(root->left){ // 如果左子树存在
                dfs(root->left, query, res, uF,visited); // dfs左子树
                uF.Union(root,root->left); // 注意一定是把左子树合并到根节点上, 根节点还是父亲
            }
            if(root->right){
                dfs(root->right, query, res, uF,visited); // dfs右子树
                uF.Union(root,root->right);  // 注意一定是把右子树合并到根节点上, 根节点还是父亲
            }

            if(query.count(root)!=0){ // 如果有关于root的查询
                if(res.count(root)==0){ // 建立容纳结果的数组
                    res[root]=vector<TreeNode*>(query[root].size(), NULL);
                }
                for(int i=0;i<query[root].size();++i){ // 对于和root有关的每一个查询
                    if(visited.count(query[root][i])){ // 这个这个结点已经被访问过了
                        res[root][i]=uF.find(query[root][i]); // 那么这个结点的父亲就是两个结点的最近公共祖先                
                    }
                        
                }
            }
        }
    
    }
};
```
3.  在线算法RMQ+欧拉序
```c++
class Solution {
public:
    int time; // <3> RMQ中需要用到的时间戳
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //  <3> 在线算法, RMQ (Range Minimum/Maximum Query) 使用nlogn的时候建nlogn大的表, 在O(1)的时间内查询[i,j]的最大值或最小值,取决于建的是什么表
                // 注意我看得那个RMQ既然是从1开始, 其实可以从0开始  https://blog.csdn.net/qq_31759205/article/details/75008659
                // 建这个所谓sparse table也就是F的过程其实就是一个动态规划F[i][j]表示的是从i开始连续2^j个元素即[i,i+2^j-1]中的最大/最小值
            // 我们建立一个欧拉序,每当某个结点开始dfs的时候, 把它加入到数组里; https://www.cnblogs.com/stxy-ferryman/p/7741970.html,https://www.cnblogs.com/zhouzhendong/p/7256007.html
                // 当它从子节点dfs执行完回到这个结点的dfs的时候, 再把这个结点放到数组里, 同时, 我们记录一下深度
            // 依靠这个欧拉序和记录的深度, 我们就可以找到任意两个结点之间的LCA了
                // 我们首先找到这两个结点第一次出现在数组的位置,也就是他们开始执行dfs函数的时候,
                // 这两个位置之间(闭区间), 一定会出现他们的最近共同祖先(而不会出现最近共同祖先的祖先), 而具体哪个才是最近共同祖先呢?
                    // 答案是, 深度最小的那个, 因为它是这个区间里面最高的那个结点, 是这两个结点的祖先(最近共同祖先)
            // 所以如果我们这样操作, 大小为n的数组in记录的是, 某个结点第一次dfs到的时间; 大小为2n的EulerOrder数组记录的是按照欧拉序结点的深度
            // 当我们查询结点p和q的最近共同祖先时, 我们从in获得p和q在EulerOrder数组中第一次出现的位置, 找到这个范围内的最小值, 比如是即可
            // 我们使用time来作为时间戳, 作为in数组的值

        unordered_map<TreeNode*, int>in;   // 记录每个节点第一次被访问的时间, 也就是第一次被加入到EulerOrder数组中的下标是多少
        vector<pair<TreeNode*, int>> EulerOrder; // 记录欧拉序的数组, 既要记录下是哪个结点, 也要记录下这个结点在dfs中的深度
        time=-1; // 初始值设置为-1 这样的话第一个被访问过的结点即根节点被插入到EulerOrder的第0个位置
        dfs(root,in,EulerOrder,1); //进行深度优先搜索, 设置好in和EulerOrder

        int n=EulerOrder.size();
        int num=1; // 为了避免下标错误的问题, 我们直接开一个n(logn+1)大小的数组, num就是为了计算logn(取下界)+1
        // 比如我们一共有17个元素[0,16], 从0开始, 最多有2^4=16的连续元素, 也就是[0,15] 那么我们j的取值范围就是0,1,2,3,4 所以需要的空间是5
        for (int j = 1; (1 << j) <= n; j++) 
            ++num;
        
        vector<vector<pair<TreeNode*, int>>> F(n,vector<pair<TreeNode*, int>>(num)); // 开出n*num的空间
        --n;
        for (int i = 0; i <= n; i++){ // 边界条件, 当j==0的时候
            F[i][0]=(EulerOrder[i]);
        }
        
        
        for (int j = 1; (1 << j) <= n; j++) { // 外层循环是logn次
            for (int i = 0; i + (1 << j) - 1 <= n; i++) { //n层循环每次最多n次
                if(F[i][j - 1].second<=F[i + (1 << (j - 1))][j - 1].second) // 注意, 我们要求的取得是最小值, 所以下面是取小的那一个, second对应地是深度
                    F[i][j] = F[i][j - 1];
                else 
                    F[i][j]=F[i + (1 << (j - 1))][j - 1];
               
            }
        }
        
        int l=min(in[p],in[q]), r=max(in[p],in[q]); // l和r分别是闭区间的左右端点, 我们求得是这个闭区间内最小值对应的TreeNode*
        int k = 0; // 我们查询的思路分成两个区间, 是一个区间是以l为起点, 另一个区间以r为终点, 同时要求两个区间要覆盖整个区间[l,r],
            // 这个2^k就是两个区间的长度 要有2*2^k>=(r-k+1) 这样才能保证覆盖了区间[l, r]
        while ((1 << (k + 1)) <= r - l + 1) 
            k++;

        // 把区间分成了[l, l+2^k-1 ] 和[r-(2^k)+1,r]
        if(F[l][k].second<=F[r - (1 << k) + 1][k].second) // 同理, 要取较小值
            return F[l][k].first;
        else 
            return F[r - (1 << k) + 1][k].first;
    
    }


    // <3> RMQ 欧拉序所用到的dfs函数
    void dfs(TreeNode* root, unordered_map<TreeNode*, int>&in, vector<pair<TreeNode*, int>> &EulerOrder,int depth){
        if(root){
            ++time; // 时间增加
            in[root]=time; // 这是root第一次被访问的时间 也是它在EulerOrder中第一次出现的下标
            EulerOrder.push_back(make_pair(root,depth));
            if(root->left){ // 访问左节点
                dfs(root->left,in,EulerOrder,depth+1);
                ++time; // 左节点访问完了, 时间增加, 时间必须增加, 这样才能保证记录得每个节点第一次被访问的时间是正确的
                EulerOrder.push_back(make_pair(root,depth)); // 根据欧拉序, 把root和depth再次加入到EulerOrder中
            } 
            if(root->right){ // 访问右节点
                dfs(root->right,in,EulerOrder,depth+1);
                ++time; // 右节点访问完了, 时间增加, 时间必须增加, 这样才能保证记录得每个节点第一次被访问的时间是正确的
                EulerOrder.push_back(make_pair(root,depth)); // 根据欧拉序, 把root和depth再次加入到EulerOrder中
            }
        }
    }

    
};
``` 






