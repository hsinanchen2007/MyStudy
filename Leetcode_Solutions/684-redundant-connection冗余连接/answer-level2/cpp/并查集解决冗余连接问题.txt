并查集的核心思想官方题解已经解释了，也可以通过查维基百科了解

## 核心思路
首先初始化，每个节点之间都没有边，独自在各自的集合中，然后遍历每一条边：
1. 如果这条边的两个节点在同一个集合中，那么说明它们连接后将成环，因此是那条附加的边
2. 否则，将这两个节点连接起来，即放入同一个集合

## 图示
以`[[1,2], [2,3], [3,4], [1,4], [1,5]]`为例

1. 首先初始化：
```
 5  1  2
       
    4  3
```
2. 第一次遍历到边`[1,2]`,检查节点`1`和`2`,不在同一个集合中，将这两个节点连接起来，放入同一个集合
```
 5  1 - 2
       
    4   3
```
3. 第二次遍历到边`[2,3]`,检查节点`2`和`3`,不在同一个集合中，将这两个节点连接起来，放入同一个集合
```
 5  1 - 2
        |
    4   3
```
4. 第三次遍历到边`[3,4]`,检查节点`3`和`4`,不在同一个集合中，将这两个节点连接起来，放入同一个集合
```
 5  1 - 2
        |
    4 - 3
```
5. 第四次遍历到边`[1,4]`,检查节点`1`和`4`,发现两个点都在同一个集合中，因此直接返回这两个点，后面的边已经不需要再检查了
```
 5  1 - 2
    *   |
    4 - 3
```
## 代码如下

```c++
class Solution {
public:
    // 并查集的基本数据结构
    const static int MAXN = 1001;
    int parent[MAXN + 1];
    int size[MAXN + 1];

    // 初始化并查集
    void UF(int n){
        for(int i = 0; i <= n + 1; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // 查找节点p的根节点
    int find(int p){
        while(parent[p] != p){
            parent[p] = parent[parent[p]]; // 剪枝操作，主要是避免这个树过深，不能理解的话，不要这个也是正确的
            p = parent[p];
        }
        return parent[p];
    }

    // 合并两个节点，即将他们的根节点设置为同一个
    void myunion(int p, int q){
        int pp = find(p);
        int pq = find(q);
        // 因为这个集合实质上是用树实现的，为了避免树过于不平衡，因此将节点少的树加入到节点多的树中
        // 不能理解的话，随便把一个树加入另一个树也是正确的
        if(size[pp] > size[pq]){
            parent[pq] = parent[pp];
            size[pp] += size[pq];
        }else{
            parent[pp] = parent[pq];
            size[pq] += size[pp];
        }
        return;
    }
    
    // 检查两个树是不是在一个集合中，即看他们的根节点是不是同一个
    bool connected(int p, int q){
        return find(p) == find(q);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int a, b;
        UF(n);  // 初始化并查集
        for(int i = 0; i < n; i++){
            a = edges[i][0];
            b = edges[i][1];
            if(connected(a, b))  // 如果在同一个集合，即找到这条附加边
                return {a, b};
            myunion(a, b);  // 否则，将这两个节点加入同一个集合
        }
        return {a, b};   // 这一步实际不会执行    
    }
};
```

## 复杂度分析
- 时间复杂度：$O(N\alpha(N)) \approx O(N)$。其中，$N$是边的数目。
    - 由于最坏的情况下需要对每条边都遍历一遍，每次都调用一次`myunion`函数一次（参考维基百科知道，这个函数平均下来是$\alpha(n)$的复杂度，$\alpha(n)$是`Inverse-Ackermann`函数，其在$n$值十分巨大时还是小于5），所以综合下来时间复杂度为$O(N\alpha(N)) \approx O(N)$
- 空间复杂度：$O(N)$，并查集的`parent`和`size`各需要`N`的空间。

## 参考资料
[LeetCode](https://leetcode-cn.com/problems/redundant-connection/solution/rong-yu-lian-jie-by-leetcode/)
[维基百科-并查集](https://zh.wikipedia.org/wiki/%E5%B9%B6%E6%9F%A5%E9%9B%86)