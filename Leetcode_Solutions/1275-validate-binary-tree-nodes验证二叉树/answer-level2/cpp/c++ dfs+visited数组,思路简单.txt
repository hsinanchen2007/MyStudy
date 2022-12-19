代码思想很简单，就是dfs
考虑false的情况有两种：
1.两个节点指向同一个节点(访问了已经访问过的节点)
2.不只是一棵树(联通量大于1)

用一个visited数组记录是否被访问过
```
class Solution {
public:
    vector<bool> visited;
    bool dfs(int i,vector<int>& leftChild, vector<int>& rightChild){
        if(visited[i])
            return false;//情况一：访问已经访问过的
        visited[i]=true;
        bool b1=true;
        bool b2=true;
        if(leftChild[i]!= -1)//左孩子不为空则遍历左孩子
            b1=dfs(leftChild[i],leftChild,rightChild);
        if(rightChild[i]!= -1)//右孩子不为空则遍历右孩子
            b2=dfs(rightChild[i],leftChild,rightChild);
        return b1&&b2;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        visited = vector<bool>(n,false);
        if( !dfs(0,leftChild,rightChild))//判断情况1
            return false;
        for(int i=0;i<n;i++)//判断情况2，也就是在一次dfs后有没有还没有访问过的节点
            if(!visited[i])
                return false;
        return true;
    }
};
```
