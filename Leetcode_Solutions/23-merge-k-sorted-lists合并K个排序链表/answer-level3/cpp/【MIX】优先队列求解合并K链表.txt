### 解题思路
1. 归并法(自底向上)
2. 分治法(自顶向下))
3. 优先队列合并
4. 时间复杂度为$O(NlgK)$

### 代码

```java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        // 使用辅助优先队列
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b)->(a-b));
        ListNode dummy = new ListNode(-1);
        ListNode p = dummy;
        for(ListNode L: lists){
            while(L != null){
                pq.offer(L.val);
                L = L.next;
            }
        }

        while(!pq.isEmpty()){
            p.next = new ListNode(pq.poll());
            p = p.next;
        }


        return dummy.next;
    }
}
```
```c++ []
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 归并法(自底向上)
        int N = lists.size();
        if(N == 0)
            return nullptr;

        while(lists.size() > 1){
            vector<ListNode *> newLists;
            for(int i=0; i+1<lists.size(); i+=2){
                ListNode *mergeList = merge(lists[i], lists[i+1]);
                newLists.push_back(mergeList);
            }
            if(lists.size() & 0x01)
                newLists.push_back(lists.back());
            lists = vector<ListNode*>(newLists.begin(), newLists.end());
        }
        return lists[0];
    }

private:
    // 合并两个链表
    ListNode *merge(ListNode *L1, ListNode *L2){
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        while(L1 != nullptr && L2 != nullptr){
            if(L1->val < L2->val){
                p->next = L1;
                L1 = L1->next;
            }
            else{
                p->next = L2;
                L2 = L2->next;
            }
            p=p->next;
        }
        if(L1 != nullptr)
            p->next = L1;
        if(L2 != nullptr)
            p->next = L2;

        return dummy->next;
    }
};
```
```python []
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if lists==None or len(lists)==0:
            return None

        def merge(L1, L2):
            dummy = ListNode(-1)
            p = dummy
            while(L1 != None and L2 != None):
                if L1.val < L2.val:
                    p.next = L1
                    L1 = L1.next

                else:
                    p.next = L2
                    L2 = L2.next
                
                p = p.next
            if L1 != None:
                p.next = L1
            if L2 != None:
                p.next = L2
            return dummy.next

        while lists.__len__() > 1:
            newLists = []
            for i in range(0, len(lists)-1, 2):
                mergeList = merge(lists[i], lists[i+1])
                newLists.append(mergeList)

            if len(lists)&0x01==1:
                newLists.append(lists[-1])

            lists = newLists

        return lists[0]

```