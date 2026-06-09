
思路
- 和归并排序是一样的道理
- 不过这里由于有k个，每次都扫一边的话会有很多重复的，所以需要从k个中找到最小的哪个，用堆结构就可以了

复杂度
- T=O（N*logk）//因为每合并一个元素都需要对有限队列进行一个pop或者push，这两个都是logk的
- M=O（k）//堆用了k个

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
protected:
    struct Compare{
        bool operator()(ListNode*& a, ListNode*& b){
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        }
        while(!pq.empty()){
            ListNode* min_node=pq.top();
            pq.pop();
            if(min_node->next!=NULL)
                pq.push(min_node->next);
            //temp接到尾部
            if(tail==NULL)//无节点
                head=min_node;
            else{
                tail->next=min_node;
            }
            tail=min_node;
        }
        return head;
    }
};
```
