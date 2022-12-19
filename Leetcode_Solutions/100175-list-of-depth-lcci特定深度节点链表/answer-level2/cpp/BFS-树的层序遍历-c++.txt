### 解题思路
还是犯了一些小错误，练习还是不够啊！

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // //我觉得就是一个BFS层序遍历罢了
    // vector<ListNode*> listOfDepth(TreeNode* tree) {
    //     vector<ListNode*> ans;
    //     queue<TreeNode*> q;
    //     q.push(tree);
    //     while(!q.empty()) {
    //         ListNode* node = new ListNode();  //创建一个对象指针，必须用申请！！！
    //         node->val = q.front()->val;
    //         ans.push_back(node);  //提前就放，由于这是一个地址，所以哪怕后面会加，也没有关系，数据会在
    //         int size = q.size() - 1; //之所以减一，是因为第一个已经用了
    //         //第一个的子节点也要入队，但是size要在之前判断，否则不是一层
    //         if(q.front()->left != NULL) q.push(q.front()->left);
    //         if(q.front()->right != NULL) q.push(q.front()->right);
    //         q.pop();  //第一个拿掉作为头
    //         //一次一层
    //         for(int i = 0; i < size; i++) {
    //             //访问
    //             TreeNode* top = q.front();
    //             q.pop();
    //             ListNode* next = new ListNode();  //创建一个对象指针，必须用申请！！！
    //             next->val = top->val;
    //             node->next = next;
    //             node = node->next; // 指向下一个
    //             //子节点入队
    //             if(top->left != NULL) q.push(top->left);
    //             if(top->right != NULL) q.push(top->right);
    //         }
    //     }
    //     return ans;
    // }


    //上面那版的头结点用法一点都不优雅，其实可以优雅的
    //我觉得就是一个BFS层序遍历罢了
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> ans;
        queue<TreeNode*> q;
        q.push(tree);
        while(!q.empty()) {
            //用一个head记录头结点，只需要浪费第一个地址空间，就可以不用考虑头结点问题
            ListNode* node = new ListNode(0), *head = node;  //创建一个对象指针，必须用申请！！！
            int size = q.size();
            //一次一层
            for(int i = 0; i < size; i++) {
                //访问
                TreeNode* top = q.front();
                q.pop();
                ListNode* next = new ListNode();  //创建一个对象指针，必须用申请！！！
                next->val = top->val;
                node->next = next;
                node = node->next; // 指向下一个
                //子节点入队
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
            }
            ans.push_back(head->next);
        }
        return ans;
    }
};
```