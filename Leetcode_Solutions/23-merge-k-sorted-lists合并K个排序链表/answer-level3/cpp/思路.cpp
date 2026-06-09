### 解题思路
需要注意两两合并和归并合并的复杂度分析

4. 两两合并和分治合并时间复杂度解析
假设有K条链表，所有链表等长，每个链表长度为N，这里只是为了方便演示，实质上无所谓。

合并两个有序链表的时间复杂度是O(n)，n是两个链表的总节点数。

两两合并

两两合并需要进行 K-1 次合并，时间复杂度求和为：

2N + 3N + 4N + ... + KN = (K+2) * (K-1) * N / 2

这里近似看为 K * K*N , 也就是K * n 【n是链表总节点数】

分治合并

K个有序链表，每次分割一半，总共需要分割logK次，而每一轮merging的时间复杂度为O(n)，注意这里的n是所有链表的节点总数，因为每一次merging所有的节点都需要比较一次，可参考上述分治合并过程的图片。则时间复杂度求和为：

logK * O(n) = O(n* logK)

作者：zuo-10
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/c-you-xian-dui-lie-liang-liang-he-bing-fen-zhi-he-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if(!l1 || !l2)  return l1 == NULL ? l2 : l1;

      ListNode* head = new ListNode(0);
      ListNode* cur = head;

      while(l1 && l2){
        if(l1->val >= l2->val){
          cur->next = l2;
          l2 = l2->next;
        }else{
          cur->next = l1;
          l1 = l1->next;
        }
        cur = cur->next;
      }
      if(l1)
        cur->next = l1;
      if(l2)
        cur->next = l2;

      return head->next;
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right){
      if(left == right) 
        return lists[left];
      int mid = left + (right - left) / 2;
      ListNode* head1 = merge(lists, left, mid);
      ListNode* head2 = merge(lists, mid + 1, right);
      return mergeTwoLists(head1, head2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if(lists.size() == 0)  return NULL;

      return merge(lists, 0, lists.size() - 1);
    }
};
```