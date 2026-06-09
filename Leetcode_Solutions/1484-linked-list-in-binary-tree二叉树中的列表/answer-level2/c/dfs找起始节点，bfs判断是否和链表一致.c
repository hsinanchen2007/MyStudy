### 解题思路
1. 深度搜索，找到树中和链表首节点相同的节点。
2. 找到后，建一个队列进行广度搜索，把每一层加到队列里，并判断每一层是否有和链表对应节点相等。

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

struct MyQueNode {
    int level;
    struct TreeNode *tnode;
    struct MyQueNode *next;
};


bool bfs(struct ListNode *head, struct TreeNode *root) {
    struct MyQueNode *que = NULL;
    struct MyQueNode *last = NULL;
    struct ListNode *curlnode = head;
    struct TreeNode *curtnode;
    
    int curlvl = 0;
    struct MyQueNode *tmp = (struct MyQueNode*)malloc(sizeof(struct MyQueNode));
    if (!tmp) return false;

    tmp->level = curlvl;
    tmp->tnode = root;
    tmp->next = NULL;
    que = last = tmp;

    while (tmp) {
        if (!curlnode) return true;
        curtnode = tmp->tnode;
        if (curlnode->next == NULL && curlnode->val == curtnode->val) return true;//////
        if (curtnode->val != curlnode->val) {
            tmp = tmp->next;
            if (!tmp && curlnode) {
                return false;
            }
            if (tmp->level != curlvl) {
                curlvl++;
                curlnode = curlnode->next;
            }
            continue;
        }

        if (curtnode->left) {
            struct MyQueNode *qtmp = (struct MyQueNode*)malloc(sizeof(struct MyQueNode));
            qtmp->level = curlvl + 1;
            qtmp->tnode = curtnode->left;
            qtmp->next = NULL;
            last->next = qtmp;
            last = qtmp;
        }

        if (curtnode->right) {
            struct MyQueNode *qtmp = (struct MyQueNode*)malloc(sizeof(struct MyQueNode));
            qtmp->level = curlvl + 1;
            qtmp->tnode = curtnode->right;
            qtmp->next = NULL;
            last->next = qtmp;
            last = qtmp;
        }
        tmp = tmp->next;
        if (tmp && tmp->level != curlvl) {//tmp!= NULL
            curlvl++;
            curlnode = curlnode->next;
        }
    }

    return false;
}


bool isSub(struct ListNode* head, struct TreeNode* root) {
    if ((root->val == head->val) &&
        bfs(head, root)) return true;

    if (root->left &&
        isSub(head, root->left)) return true;

    if (root->right &&
        isSub(head, root->right)) return true;

    return false;
}

bool isSubPath(struct ListNode* head, struct TreeNode* root){
    if (!head || !root) return false;
    return isSub(head, root);
}


```