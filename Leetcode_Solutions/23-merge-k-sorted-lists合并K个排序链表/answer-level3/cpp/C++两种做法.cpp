## 优先队列 priority_queue
运行时间`28ms`
非常容易想到的做法，把所有节点都压到优先队列中，然后依次选出，相当于堆排序
时间复杂度 `O(nlog(n))` ,可以通过每次放k个元素优化为`O(n(log(k)))`
```c++
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int> > q;
        for(auto it : lists){
            ListNode* now = it;
            while(now){
                q.push(now->val);
                now = now->next;
            }
        } 
        ListNode *ans = NULL;
        if(!q.empty()){
            ans = new ListNode(q.top());
            q.pop();
        }
        ListNode *temp = ans;
        while(!q.empty()){
            temp->next = new ListNode(q.top());
            q.pop();
            temp = temp->next;
        }
        return ans;
    }
};
```
## 分治
运行时间`16ms`
相邻两个链表两两合并，从k个链表合并到 k / 2，k / 4 ....一直合并到1个
时间复杂度`O(nlog(k))`
```c++
class Solution {
public:
    ListNode* merge2List(ListNode* l1, ListNode* l2)
    {
        //merge l2 to l1
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        if(l2->val < l1->val){
            swap(l2, l1);
        }
        ListNode* cur = l1;
        while(l2){
            if(l2->val >= cur->val && (!cur->next || l2->val < cur->next->val)){
                ListNode* temp = l2;
                l2 = l2->next;
                temp->next = cur->next;
                cur->next = temp;
            }
            cur = cur->next;
        }
        return l1;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        vector<ListNode*> newList;
        int i = 1;
        for(; i < lists.size(); i += 2){
            ListNode* temp = merge2List(lists[i - 1], lists[i]);
            newList.push_back(temp);
        }
        if(i == lists.size()){
            newList.push_back(lists[i - 1]);
        }
        if(newList.size() == 1){
            return newList[0];
        }
        return mergeKLists(newList);
    }
};
```
