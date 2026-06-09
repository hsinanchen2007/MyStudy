### 解题思路
1：并查集通用解法：需要对并查集有足够的理解
参考：
遍历所有的边edges，将连通的结点放入同一个集合，形成一个联通分量GG。
在遍历的过程中，如果边(a, b)的两个结点a, b已经属于同一联通分量，则(a, b)就是该联通分量的冗余边。
作者：xiao-xiao-suan-fa
链接：https://leetcode-cn.com/problems/redundant-connection/solution/684-rong-yu-lian-jie-bing-cha-ji-shi-xian-by-xiao-/

以上解释，对于不理解并查集数据结构算法的同学，可能有点抽象，其实很简单。

2.普通解法：最直观的就是把具有相同点的边放在一个集合里，可以分三种情况
1）当一条边的两个点均不在已有集合中，则说明该边是独立个体，与其他集合无交集；
2）当一条边的有一个点在已有集合A中，则说明该边与集合A是相同集合，要合并；
2）当一条边的两个点已经在集合A中，则说明该边是A的冗余边

因此，求解时，我们要维护如下数据结构：
1）vector<set<int>> unionvec用于保存不相交的集合
2）vector<set<int>> unionbuff;//与某条边有交叉项的集合
每次edge加入时，与unionvec进行比较，包含edge的1个点的集合统一放入unionbuff，没有交际的放入unionvec；遍历完成后，将edge与unionbuff合并，统一放入unionvec；当下一条边的两个节点都在unionvec的某个集合中时，则找到结果


示例如下：
[[1,5],[3,4],[3,5],[4,5],[2,4]]
第一步：联通 1 5  [1,5]         unionvec
第二步：联通 3 4  [1,5] [3 4]   unionvec
第三步：联通 3 5  [1,3,4,5]     unionvec
第四步：联通 4 5 发现 4 5已经在并查集里了，此时4 5就是冗余边
我们可以看到 1 3，1 4，3 4 都是冗余边
![image.png](https://pic.leetcode-cn.com/e4528c4eb8343ba49e8e28ccbd457a4041545dc7d3b6c62c5970dd1e0956f365-image.png)


parent的个数是edges.size()+1，原因是n条边，最多n+1个点
比如3条边，最多就是[1,2][2,3][3,4]连在一起


1：并查集通用解法

### 代码

```cpp
class Solution {
public:
    deque<int> parent;


    int findroot(int i)
    {
        while(parent[i] != i){
            i = parent[i];
        }

        return i;
    }

    bool union_node(int a,int b){
        int roota = findroot(a);
        int rootb = findroot(b);

        if(roota == rootb){
            return false;
        }

        parent[rootb] = roota;
        return true;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        parent = deque<int>(edges.size()+1,0);

        for (int i = 1; i < parent.size();i++){
            parent[i] = i;
        }

        for (auto edge : edges){

            if (!union_node(edge[0], edge[1]))
            {
                return edge;
            }
        }

        return vector<int>();
    }
};
```

2.普通解法：
```cpp
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        if(edges.size()<3){
            return vector<int>();
        }
        vector<unordered_set<int>> unionvec;

        for(auto edge:edges){
            vector<unordered_set<int>> tempunionvec =unionvec;
            unionvec.clear();
            unordered_set<int> pointset;
            pointset.insert(edge.begin(), edge.end());

            unordered_set<int> tmppointset = pointset;

            for (int i = 0; i < tempunionvec.size();i++){
                int find =0;
                for(auto n:pointset){
                    if(tempunionvec[i].count(n)){
                        find ++;
                    }
                }
                if(find == 1){
                    tmppointset.insert(tempunionvec[i].begin(),tempunionvec[i].end());   //有相同项
                }else if(find == 2){
                    return edge;
                }else{
                    unionvec.push_back(tempunionvec[i]); //无交叉项
                }
            }

            unionvec.push_back(tmppointset);
        }

        return vector<int>();
    }
};
```



