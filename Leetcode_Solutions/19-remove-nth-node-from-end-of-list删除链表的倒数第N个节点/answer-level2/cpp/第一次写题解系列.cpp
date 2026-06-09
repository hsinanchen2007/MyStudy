### 解题思路
思考怎样能够获取节点倒着数的下标。dfs里完成这样的内容：如果从最后一个元素开始往前数，就可以在找到倒数第n个元素的时候，让前一个元素的next指针指向倒数第n-1个元素。这样也遇到一个问题，当链表元素个数m和n相等的时候，实际上是删除第一个元素，dfs完成不了，所以加了一个判断，返回head->next。

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
class Solution {
public:
    int dfs(ListNode* a,int n){
        if(a->next==NULL)
            return 1;
        int m=dfs(a->next,n);
        if(m==n){
            a->next=a->next->next;
        }
        return m+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m=dfs(head,n);
        if(m==n){
            return head->next;
        }
        return head;
    }
};
```