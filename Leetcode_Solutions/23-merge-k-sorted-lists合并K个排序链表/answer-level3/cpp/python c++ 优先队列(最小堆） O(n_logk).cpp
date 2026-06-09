最暴力的做法是把N个数放到一个数组里，再一起排序，O(NlogN)。

当然由于k个链表是有序的，我们实际上只需要维护k个指针从k个链表的头向尾滑动，每次选取k个链表的表头里的最小加入新的有序链表里。

这里我们就可以借用最小堆(优先队列)维护k个链表的当前头位置的值。

时间复杂度就变成O(N*logK)

这里我利用python自带```heapq```实现最小堆的时候，直接把（node.value,node)组成元组放进队列里，结果leetcode编译器报错,显示```<```无法对```LISTNode```类型数据进行操作.....服了....

```python
class Solution(object):
    def mergeKLists(self, lists):
        import heapq
        que = []
        for node in (lists):
            if node != None : 
                heapq.heappush(que ,(node.val, node))
        dummy_node = ListNode(-1)
        cur = dummy_node
        while que:
            val, node =  heapq.heappop(que)
            cur.next = node
            cur = cur.next
            if node.next != None:
                heapq.heappush(que, (node.next.val, node.next))
        return dummy_node.next
```
但更坑的是我发现虽然```python3```提交编译器报错，但```python```提交可以通过..... 

好在```python3```里```heapq```可以对编译器**自有变量类型**组成的**元组**进行比较。

同时查资料发现元组在```heapq```里比较的机制是**从元组首位0**开始，即遇到相同，就比较元组下一位，比如(1,2), (1,3)，前者比后者小。

这题刚好node值有重复的，同时```ListNode```无法被比较，所以可以解释编译器为什么报错。

于是把代码修改一下，存的是节点值和节点的索引，都是```int```类型，当node.val相同时，索引小的先弹出。

```python
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        import heapq
        que , curs = [] , [] # curs存K个链表滑动的头指针
        for index, node in enumerate(lists):
                if node!=None:
                    heapq.heappush(que ,(node.val, index))
                curs.append(node)

        dummy_node = ListNode(-1)
        cur = dummy_node
        while que:
            val, index =  heapq.heappop(que)
            cur.next = lists[index]
            cur = cur.next
            lists[index] = lists[index].next
            if lists[index] != None:
                heapq.heappush(que, (lists[index].val, index))
        return dummy_node.next

```
还是C++强大，任何数据类型都可以对```<```重载一下，都可以实现排序，即我们只要重写一个```cmp```函数，丢到优先队列即可。
C++
```c++
class Solution {
public:
    struct cmp{  //对新的数据类型的<进行重写
       bool operator()(ListNode *a,ListNode *b){
          return a->val > b->val;
       }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode* ,vector<ListNode*> , cmp> heapk;
       for(auto p:lists){
        if(p!=NULL){
            heapk.push(p);
        }
       }
       ListNode *pHead = new ListNode(-1);
       ListNode *pCur = pHead;
       while(!heapk.empty()){
          ListNode *top = heapk.top();heapk.pop();
          pCur->next = top;
          pCur = pCur->next;
          if(top->next!=NULL){
            heapk.push(top->next);
          } 
       }
       pCur = pHead->next;
       delete pHead;
       return pCur;
    }
};
```
