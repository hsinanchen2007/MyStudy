  1. 找入度为0的点，如果不是一个，return false
  2. 从唯一入度为零的点，进行bfs遍历，并计数，如果遍历过程中有结点指向已访问过的结点，return false
  3. 遍历计数！=n， return false；否则，return true
```c++ []
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> not_root,visited;
        queue<int> q;
        int root=0,tmp,node_num=0;
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1) not_root.insert(leftChild[i]);
            if(rightChild[i]!=-1) not_root.insert(rightChild[i]);
        }
        if(not_root.size()!=n-1) return false;
        while(not_root.count(root)) root++;
        q.push(root);
        while(!q.empty()){
            tmp=q.front(); q.pop(); node_num++;
            if(visited.count(tmp)) return false;
            visited.insert(tmp);
            if(leftChild[tmp]!=-1) q.push(leftChild[tmp]);
            if(rightChild[tmp]!=-1) q.push(rightChild[tmp]);
        }
        return node_num==n;
    }
};
```
> -------------------------------------------------
> > \>\>\>[**我的算法题本 - 算法菜鸟之路**](https://github.com/lorwin0130/Algorithm-newbie)
> 会记录做过题的**不同解法、思路、套路总结以及个人思考**
> 欢迎各位大佬**来讨论呀**，欢迎**star (U^_^U)** 
> -------------------------------------------------

