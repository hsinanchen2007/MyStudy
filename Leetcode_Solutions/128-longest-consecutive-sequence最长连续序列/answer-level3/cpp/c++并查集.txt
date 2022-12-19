### 解题思路
此处撰写解题思路
感觉力扣的评测系统有点奇怪啊，主函数里面多了一个遍历就超时过不了按理说。。O(2n)不是跟O(n)一样的么。。
这应该是数据结构最小生成树之后第一次用并查集写题，由于之前对并查集理解不是很深入所以参考了几个大佬的代码。
并查集，包含并和查两种操作，所以基本上和连通有关的题都可以这么做（借用某位大佬的话）。然后并查集可以用哈希表实现或者是数组实现，听说数组会比哈希表快一些。c++里面就是unordered_map了，把每个结点的编号作为key把它的父节点作为value..
这里应该是先把所有连续的数都连在一起，那么通过并操作就能得到很多连通分量然后计算每个连通分量的结点数就行了，当然这里求每个连通分量的结点数的时候是直接在并操作里面实现的，把两个结点的根节点并起来顺带把两个结点根节点对应的结点数也加起来，因为他们是同一个连通分量。然后优化的话，就一个路径压缩了。路径压缩说白了，就是尽量把所有的子结点的父节点都搞成一个。其实不是很高大上的东西，你可以把并查集理解成树，最理想的情况就是这个树只有两层。第一层是根节点，第二层全是子节点然后他们的父节点都是一样的。嗯，大概就这些了，如果有更深的理解我还会后期更新一下，如果有说的不太对的地方感谢各位大佬指教，不过记录一下理解还是希望可以帮到更多像我这样的初学者。
最后说一下，并查集能实现的就是很快找到有多少个连通分量，然后改造一下能判断是不是存在回路。(应该某些情况下能找到回路个数吧)
### 代码

```cpp
class Solution {
public:
    unordered_map<int,int> roots;
    unordered_map<int,int> DSU;
    int find_root(int root)  //find
    {
        int pre_root=root;
        while(DSU[root]!=root)
        {
            root=DSU[root];
            DSU[pre_root]=DSU[root];
        }
        return root;
    }
    void union_root(int a,int b)
    {
        int root_a=find_root(a);
        int root_b=find_root(b);
        if(root_a!=root_b)
        {
            DSU[root_a]=root_b;
            roots[root_b]+=roots[root_a];
        }
    }
    bool contain(int x)
    {
        return DSU.find(x)!=DSU.end();
    }
    int longestConsecutive(vector<int>& nums) {
         DSU.reserve(nums.size());
         for(auto num:nums)
         {
             if(contain(num))  //跳过重复的元素
                 continue;
             roots[num]=1;
             DSU[num]=num;
             if(contain(num-1))
                 union_root(num-1,num);
             if(contain(num+1))
                 union_root(num+1,num);
         }
          int max_value=0;
          for(auto root:roots)
          {
              max_value=max(max_value,root.second);
          }
         return max_value;
    }
};
```