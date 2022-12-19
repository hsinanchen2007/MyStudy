这题和第107. 二叉树的层次遍历 II的题目非常类似，都是使用层序遍历，并且在遍历过程中，对当前的队列数目进行了计数，然后每次循环都完全弹出了当前层的节点；只有处理完了当前层的节点，
才会进入下一层的处理。只不过这里由于是N叉树，所以使用了循环来压入每个节点的子节点，而107题中只需要对左右子树进行处理就可以了。


```
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<int> layer;
        vector<vector<int>> res;
        if(root==NULL) return res;

        queue<Node*> q;
        Node* temp;
        q.push(root);
        while(!q.empty()){/*一直循环，直到队列空，队列层序遍历的基本框架
            int num=q.size();
            for(int i=0;i<num;i++){/*统计每一层的节点树，保证处理完当前层的节点*/
                temp=q.front();
                q.pop();
                layer.push_back(temp->val);
                if(temp->children.size()!=0){
                    for(int i=0;i<temp->children.size();i++){
                    q.push(temp->children[i]);/*将每个节点的子节点压入队列*/
                    }
                }
            }
            res.push_back(layer);/*处理完一层后，压入结果*/
            layer.clear();/*压入结果后清空layer*/
        }        
        return res;
    }
};
```
