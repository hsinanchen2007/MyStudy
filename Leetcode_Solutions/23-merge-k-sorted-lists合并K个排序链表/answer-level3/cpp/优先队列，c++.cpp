### 解题思路
1. 遍历链表数组，push到优先队列pq中，注意入参lists要判空
2. 创建一个链表ans，头结点存放pq弹出来的首元素。将ans赋值给tmp，循环遍历pq的元素，循环内容是：pq弹出元素创建链表节点，将tmp->next指向该节点，tmp移动到下一节点。注意，pq弹出之前需要判空
3. 返回ans

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (!k)
            return nullptr;
        priority_queue<int, vector<int>, greater<int>> pq;
        int val;
        for (int i = 0; i < k; i++) {
            while (lists[i]) {
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        ListNode *ans;
        ListNode *tmp;
        if (pq.empty())
            return nullptr;
        ans=new ListNode(pq.top());
        pq.pop();
        tmp = ans;
        int ks = pq.size();
        for (int j = 0; j < ks; j++) {
            tmp->next = new ListNode(pq.top());
            pq.pop();
            tmp = tmp->next;
        }
        return ans;
    }
};

```