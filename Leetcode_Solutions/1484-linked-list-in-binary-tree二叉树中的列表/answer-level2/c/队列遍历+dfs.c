### 解题思路
1.使用队列找出所有的取值和链表起点值相同的点
2.从满足条件的点开始执行dfs

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_NODE 2501
bool Dfs(struct ListNode* head, struct TreeNode* root)
{
    if(root == NULL || head == NULL) {
        return false;
    }
    if (head->next == NULL) {
        if (head->val == root->val) {
            return true;
        }
        return false;
    }
    //printf("%d, %d\n ", root->val, head->val);
    if (root->val == head->val) {
        bool check1 = Dfs(head->next, root->left);
        bool check2 = Dfs(head->next, root->right);
        if (check1 || check2) {
            return true; 
        }
        return false;
    }
    return false;
}

bool isSubPath(struct ListNode* head, struct TreeNode* root){
    struct TreeNode* tree = NULL;
    if(root == NULL || head == NULL) {
        return false;
    }
    tree = root;
    struct TreeNode* queue[MAX_NODE] = { 0 };
    int begin = 0;
    int end = 0;
    end++;
    queue[0] = root;
    while (begin < end) {         
        tree = queue[begin++];
        if (tree->val == head->val) {
            bool check = Dfs(head, tree);
            if (check) {
                return true;
            }
        }
        if (tree->left != NULL) {
           queue[end++] = tree->left;
        }
        if (tree->right != NULL) {
           queue[end++] = tree->right;
        }
    }
    return false;

}
```