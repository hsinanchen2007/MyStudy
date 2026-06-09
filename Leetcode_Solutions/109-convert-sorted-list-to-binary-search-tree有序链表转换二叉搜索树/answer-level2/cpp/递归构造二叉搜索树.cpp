### 解题思路
同[108题](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/solution/di-gui-gou-zao-er-cha-shu-by-jarvis1890/)

1. 找出链表的中点，将其作为树根root
2. 中点以前的元素作为树根root的左子树
3. 中点以后的元素作为树根root的右子树

#### 注意
108题用数组下标，当left > right时，说明当前的节点没有左子树或者右子树了，返回null。而这里使用head == tail作为退出条件：左边递归等于tail(此时tail上一层树根)时退出，返回null；右子树递归到null时退出，返回null.




### 代码

```
class Solution {
public:

    TreeNode* dfs(ListNode *head, ListNode *tail){
        if(head == tail) return nullptr;
        ListNode *slow = head, *fast = head;
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = dfs(head, slow);
        root->right = dfs(slow->next, tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        return dfs(head, nullptr);
    }
};
```

