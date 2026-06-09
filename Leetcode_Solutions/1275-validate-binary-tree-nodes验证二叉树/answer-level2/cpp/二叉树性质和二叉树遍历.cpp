### 解题思路
利用二叉树的一些数学性质保证遍历后能确定是否是二叉树
+ 除根节点外所有节点的度为1
+ 从根节点遍历能得到n个节点

### 代码

```cpp
class Solution {
public:
    int print(int root,vector<int>& leftChild, vector<int>& rightChild)//中序遍历二叉树，返回的是访问到的节点个数
    {
        if(root==-1)
            return 0;
        return print(leftChild[root],leftChild,rightChild) + 1 + print(rightChild[root],leftChild,rightChild);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>node(n,0);
        for(int i = 0;i<n;i++)
        {
            
            if(leftChild[i]!=-1)
            {
                node[leftChild[i]]++;
                if(node[leftChild[i]]>1)//验证度数小于1
                    return false;
            }
            if(rightChild[i]!=-1)
            {
                node[rightChild[i]]++;
                if(node[rightChild[i]]>1)//验证度数小于1
                    return false;
            }
        }
        int root = -1;
        for(int i = 0;i<n;i++)
        {
            
            if(node[i]==0)
            {
                root = i;
                break;
            }
        }
        if(root==-1)//没有根节点的情况
            return false;
        if(print(root,leftChild,rightChild)!=n)//判断是否是一个树
            return false;
        return true;
    }
};
```