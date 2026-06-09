### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:   //BFS
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;;
        queue<TreeNode *>que;
        TreeNode * head;
        int size,count=1;
        que.push(root);
        while(!que.empty()){  //从这开始标准模板 1.队列不为空运行
            size=que.size();  //1.得队列大小
            for(int i=0;i<size;i++){ //根据大小来循环遍历队列每一个值
               head=que.front(); //队列头
               if(head->left==NULL&&head->right==NULL) return count;//写树类题目，一定要注意他要求什么，根据他的要求，得到什么条件限制
               if(head->left!=NULL) que.push(head->left); //进队
               if(head->right!=NULL) que.push(head->right);
               que.pop(); //出队
            }
            count++;
        }
        return count;

        /* DFS
        if(root==NULL) return 0;
        if(root->left==NULL) return minDepth(root->right)+1;
        if(root->right==NULL) return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;//递归的子问题
        */
    }
};
```