C++ 32 ms; 先来个无耻的版本， 这道题可以用快慢指针找链表中间点， 可是费那个劲干嘛， 直接放进vector里， 省力多了。
```cpp
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head != nullptr){
            v.push_back(head->val);
            head = head->next;
        }
        return buildTree(v, 0, v.size());
    }
    TreeNode * buildTree(vector<int> & v, int begin, int end){
        if(begin == end) return nullptr;
        int middle = (begin+end)/2;
        TreeNode * root = new TreeNode(v[middle]);
        root->left = buildTree(v, begin, middle);
        root->right = buildTree(v, middle+1, end);
        return root;
    }
};
```

好吧，写个正经点的， 好像没那么的麻烦， 不用断开链表， 只要采用半开半闭区间就可以， 这也是STL等很多地方的惯用做法。速度还比第一种做法快了点。24 ms
```cpp
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
    TreeNode * buildTree(ListNode* head, ListNode * tail){
        if(head == tail) return nullptr;
        ListNode* slow = head, *fast = head;
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode * root = new TreeNode(slow->val);
        root->left = buildTree(head, slow);
        root->right = buildTree(slow->next, tail);
        return root;
    }
};
```