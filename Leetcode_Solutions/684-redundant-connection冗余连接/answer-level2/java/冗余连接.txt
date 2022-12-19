# 并查集
并查集几个概念：
1.集合树：所有节点以代表节点为父节点构成的多叉树
2.节点的代表节点：可以理解为节点的父节点，从当前节点出发，可以向上找到的第一个节点
3.集合的代表节点：可以理解为根节点，意味着该集合内所有节点向上走，最终都能到达的节点

此处注明出处：
作者：Zhcode
链接：https://leetcode-cn.com/problems/redundant-connection/solution/tong-su-jiang-jie-bing-cha-ji-bang-zhu-xiao-bai-ku/
来源：力扣（LeetCode）

在本代码中，每次迭代都将左结点的代表结点划为右结点的代表结点
若左结点与右结点的代表结点是同一个，则说明两结点都在最小生成树中
初始化:每个结点的代表结点都是自己

# 代码
```java []
class Solution {
    public int find(int[] M, int x){
        while(M[x]!=x){
            x=M[x];
        }
        return x;
    }

    public int[] findRedundantConnection(int[][] edges) {
        int[] C=new int[edges.length+1];
        for(int i=0;i<C.length;i++) C[i]=i;
        int H1,H2;
        for(int[] edge:edges){
            H1=find(C,edge[0]);
            H2=find(C,edge[1]);
            if(H1==H2) return edge;
            else{
                C[H1]=H2;
            }
        }
        return new int[0];
    }
}
```



