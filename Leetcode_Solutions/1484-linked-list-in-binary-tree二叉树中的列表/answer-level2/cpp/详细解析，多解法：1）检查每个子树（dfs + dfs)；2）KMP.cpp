比赛时这个题目没绕过弯来，所以赛后决定要“杀死”这种题目，把所有解法都过一遍。

### 解法一：暴力法 [超出时间限制]
#### 思路
对于每一个节点，记录当前匹配到的 链表节点，如果 当前节点的值 == 链表节点的值 ，则可以继续向下匹配；
另外，每个子节点都可以从链表头开始匹配。
例如：
```
list = 1->2->3
tree = 
      1
     / \
    2   1
   /   / \
  1   5   2
         / \
        6   3
```
首先当前节点是顶端的 "1"，当前链表节点是首节点 "1"（记为 [1, 1]）。然后 "1" == "1"，因此可以继续向下匹配（[2, 2]，[1, 2]）。另外子节点也可以从头匹配（[2, 1], [1, 1]）。
#### 代码
```cpp
class Solution {
public:
    ListNode* listHead;
    bool isSubPath2(ListNode* head, TreeNode* root) {
        if(head == NULL) return true;
        if(root == NULL) return false; // 无论如何不可能
        // 如果当前节点值 == head.val, 则可以继续往下搜索
        if(head->val == root->val)
        {
            if(isSubPath2(head->next, root->left)) return true;
            if(isSubPath2(head->next, root->right)) return true;
        }
        if(isSubPath2(listHead, root->left)) return true;
        if(isSubPath2(listHead, root->right)) return true;
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        listHead = head;
        return isSubPath2(head, root);
    }
};
```
### 解法二：检查每个子树 [通过，60 ms]
#### 思路
对于每个树中的节点，检查 **以该节点为根的子树**，是否存在 **起始于根节点** 的路径，与链表 **完全匹配**。
例如：
```
list = 1->2->3
tree = 
      1
     / \
    2   1
   /   / \
  1   5   2
         / \
        6   3
             \
              8
```
首先检查根节点 1。起始于根节点 1 的路径有:
1->2->1
1->1->5
1->1->2->6
1->1->2->3
发现没有路径与 1->2->3 匹配。

然后检查左子节点 2。由于 2 != 1，故显然无路径与 1->2->3 匹配。

然后检查右子节点 1。类似上面的讨论，最后发现有一条路径为 1->2->3 （无需检验后面的 8）。返回 true。

#### 代码
```cpp
class Solution {
public:
    bool isSame(ListNode* head, TreeNode* root)
    {
        if(!head) return true;
        if(!root) return false;
        return head->val == root->val
            && (isSame(head->next, root->left) || isSame(head->next, root->right));
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        return isSame(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
```

### 解法三： KMP [通过，40 ms]
#### 思路
参考字符串模式匹配算法。将链表的节点当成 “模式串”，而 二叉树的某一路径 为 “待匹配字符串”。有关 KMP 算法的详细解析参考 [https://www.cnblogs.com/zhangtianq/p/5839909.html](https://www.cnblogs.com/zhangtianq/p/5839909.html)。
题目中说链表中的节点的数目 <= 100，因此，我们可以花很少的时间，首先将链表的节点放到一个数组中，然后应用 KMP 算法构建 next 数组。
然后，对树中的每条路径，都当成一个待匹配字符串，对该字符串应用 KMP 算法来匹配，如果匹配成功，返回 true。
#### 代码
```cpp
class Solution {
    vector<int> list, ne;
public:
    bool hasPath(int p, TreeNode* root)
    {
        if(p == list.size()) return true;
        if(root == NULL) return false;
        while(p != -1 && root->val != list[p]) p = ne[p];
        if(hasPath(p + 1, root->left)) return true;
        if(hasPath(p + 1, root->right)) return true;
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        for(; head; head = head->next)
            list.push_back(head->val);
        ne.resize(list.size());
        ne[0] = -1;
        int i = 0, j = -1;
        while(i < list.size() - 1)
        {
            if(j == -1 || list[i] == list[j])
            {
                i++;
                j++;
                ne[i] = (list[i] == list[j])? ne[j] : j;
            }
            else
                j = ne[j];
        }
        return hasPath(0, root);
    }
};
```
