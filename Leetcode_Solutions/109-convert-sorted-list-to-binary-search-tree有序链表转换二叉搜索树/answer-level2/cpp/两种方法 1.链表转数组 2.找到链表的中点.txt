### 解题思路
1.链表转为数组再递归

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
private:

    TreeNode* sortedArr(vector<int>& nums, int start, int end)
    {
        if(start == end)
            return NULL;
        int mid = start + (end-start)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArr(nums,start,mid);
        root->right = sortedArr(nums,mid+1,end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        while(head)
        {
            arr.push_back(head->val);
            head=head->next;
        }
        return sortedArr(arr,0,arr.size());

    }
};
```

2.类似有序数组，通过快慢指针找到链表的中间节点元素，然后递归构建二叉搜索树。
```
class Solution {

public:
    ListNode* findMidEle(ListNode* head)
    {
        ListNode* l = NULL;
        ListNode* r = head;
        ListNode* m = head;
        while(r && r->next)
        {
            l = m;
            m=m->next;
            r=r->next->next;
        }
        if(l!=NULL)
            l->next=NULL;
        return m;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* mid = findMidEle(head);
        TreeNode* root = new TreeNode(mid->val);
        if(head == mid)
            return root;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;

    }
};
```
