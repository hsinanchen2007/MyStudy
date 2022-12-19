
这个问题，一开始思路不对劲，导致代码写的过于复杂，最终各种错误。

下面是错误演示，不要模仿

```c
struct TreeNode *createTree(int val){
    struct TreeNode *node;
    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *helper(struct ListNode *start, struct ListNode *end){

    if (end != NULL) printf("%d, %d\n", start->val, end->val);
    if (end == NULL) printf("%d\n", start->val);
    //终止条件
    //一个节点
    if ( start  == end || start->next == NULL){
        struct TreeNode *node = createTree(start->val);
        return node;
    }
    //两个节点
    if (start->next == end){
        struct TreeNode *root, *child;
        root = createTree(start->next->val);
        child = createTree(start->val);
        root->left = child;
        return root;
    }
    struct ListNode *slow = start, *fast=start;
    while ( true ){
        fast = fast->next->next;
        if ( fast != end || fast->next != end ) break;
        slow = slow->next;
    }
    struct TreeNode *root;
    root = createTree(slow->next->val);
    root->left = helper(start, slow);
    root->right = helper(slow->next->next ,fast);
    return root;
  
}
```

当然这已经是改过之后的代码，之前的代码错误更多，我把错误总结一下

**终止条件不对**，这是最严重的错误，也是导致后续代码非常冗余的祸因

最开始我认为条件是star->next == NULL 或是 start->next->next == NULL, 就考虑了右边的情况，而没有考虑左边的情况。 后来，我把NULL修改成end。

但是即便如此，条件也是过于复杂，我把条件分成了两种情况，也就是最后还剩下一个节点，以及最后还剩下两个节点，这两种情况。这其实并不正确，这两个情况应该是递归没有结束的前一个情况，还可以继续合并成一个情况，也就是 start == end 。 以1 2 为例， start = 1, end = 2, 按照我的代码，手动建立两个节点，然后把他们连在一起。 但是按照start == end，我们可以通过递归的方式，让程序把这两个节点连在一起。

**右半部分的起点不对**： 一开始直接用了slow， 实际上应该是slow->next;

**右半部分的终点不对**， 一开始我都是把终点设置成fast，认为fast就是end，但是fast不是end。因为fast每次移动可能为NULL，也可能不为NULL，而end是固定的参数。

还有一些小错误，比如说判断语句中，写了 A = B这种 低级错误

最后参考 <https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--24/> 完成了正确代码

```c
struct TreeNode *createTree(int val){
    struct TreeNode *node;
    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *helper(struct ListNode *start, struct ListNode *end){

    if (start == end ) return NULL;

    struct ListNode *slow = start, *fast = end;
    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    struct TreeNode *root = createTree(slow->val);
    root->left = helper(start, slow);
    root->right = helper(slow->next, end);
    return root;
  
}
struct TreeNode* sortedListToBST(struct ListNode* head){
    struct TreeNode *root;
    root = helper(head, NULL);
    return root;
}
```