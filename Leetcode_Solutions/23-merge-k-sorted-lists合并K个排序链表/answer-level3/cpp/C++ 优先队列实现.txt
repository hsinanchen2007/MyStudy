仿powcai写的。主要在队列存储时存值与下标，取出时新建结点，这样就不用考虑自己写个比较函数的问题了。
```
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > queue; // 注意>>代表右移，所以空格不能少
        // greater对应小顶堆、less默认对应大顶堆
        for (int i=0;i<lists.size();i++)
            if (lists[i]!=NULL) {
                queue.push(pair<int,int>(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        ListNode* result = new ListNode(0);
        ListNode* p = result;
        while(!queue.empty()) {
            pair<int,int>tmp = queue.top();  // 获取队头
            p->next = new ListNode(tmp.first);
            p = p->next;
            queue.pop();  // 弹出
            if (lists[tmp.second]!=NULL) {
                queue.push(pair<int,int>(lists[tmp.second]->val, tmp.second)); // 不空，继续加入队
                lists[tmp.second] = lists[tmp.second]->next;
            }
        }
        return result->next;      
        
    }
};
```

再放个python分治
```
class Solution:
    # 分治
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists:
            return []
        if len(lists) == 1:
            return lists[0]
        elif len(lists) == 2:
            result = ListNode(0)
            p = result
            first = lists[0]
            second = lists[1]
            while first and second:
                if first.val<=second.val:
                    p.next = first
                    p = p.next
                    first = first.next
                else:
                    p.next = second
                    p = p.next
                    second = second.next
            if first:
                p.next = first
            if second:
                p.next = second
            return result.next
        else:
            left = self.mergeKLists(lists[:len(lists)//2])  
            right = self.mergeKLists(lists[len(lists)//2:])  
            return self.mergeKLists([left,right])     
```
