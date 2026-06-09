### 1. 借用数组

不得不说，这个题就是上一个题目的翻版 **[108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)**

所以只要先遍历一次链表，将所有的节点值保存到一个数组里，就变成了上面的那个题。

> 时间复杂度为 O(n)，空间复杂度为 O(n)

**代码：**

```cpp
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        // 1. 使用数组
        vector<int> v;
        while(head){ v.push_back(head->val); head = head->next; }
        return helper(v, 0, v.size());
    }
private:
    TreeNode* helper(vector<int>& v, int start, int end){
        if(start >= end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = helper(v, start, mid);
        root->right = helper(v, mid + 1, end);
        return root;
    }
};
```

### 2. 快慢指针查找链表中点

说到底，借用数组只是为了可以方便的查找链表的中点；但是对于链表的中点查询，也是比较简单的。可以参考 **[876. 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/)**，具体的就是使用**快慢双指针**。

> 时间复杂度为 O(nlog(n))，空间复杂度为 O(1)

```cpp
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // 2. 链表求中点
        return helper(head, nullptr);
    }
private:
    TreeNode* helper(ListNode* head, ListNode* tail){
        if(!head || head == tail) return nullptr;
        // 开始查找中点
        ListNode* slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow指向即为当前head - tail 的中点
        TreeNode* root = new TreeNode(slow->val);
        root->left = helper(head, slow);
        root->right = helper(slow->next, tail);
        return root;
    }
};
```