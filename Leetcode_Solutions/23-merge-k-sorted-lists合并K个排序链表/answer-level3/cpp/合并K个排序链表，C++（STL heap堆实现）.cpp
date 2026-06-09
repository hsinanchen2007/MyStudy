这个题如果使用STL的heap（堆）类会非常简单，核心思想就是利用堆的高效插入和堆序性质进行排序。

思路：
    我们知道最小堆的根节点是最小元素，而利用堆的核心优势就是：插入元素到堆的开销只有O(logN)。这一问题中我们可以使堆的大小保持不变（保持为需要合并的链表数量k），这是因为我们每插入一个元素到堆中，就可以把之前的根节点（最小值）弹出到我们的目标链表中。

方法：
    1. 创建一个vector用以储存我们的最终目标链表
    2. 创建一个最小堆，包含k个待合并链表的头元素(O(k))
    3. 弹出堆的根节点至目标链表，并将这一节点移至堆底，将其替换为原所在链表的下一节点
    4. 若原链表下一节点为空，从堆中删去这一链表的索引
    5. 将堆底元素插入堆(O(logk))
    6. 当所有待合并链表的索引都从堆中删去时，合并结束，目标链表生成完毕

时间复杂度分析
向堆中插入一次元素的开销是O(logk),共插入N个元素（所有链表中元素的总和），总复杂度**O（Nlogk）**，创建堆的开销可不计。
```
class Comp
{
 public:
    bool operator() (const ListNode* left, const ListNode* right) const
    {
        return (left->val > right->val);
    }
};

class Solution {//使用STL的Heap实现
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>::iterator it = lists.begin();
        while(it!=lists.end()){//删除空表
            if(*it == NULL)
                lists.erase(it);
            else
                it++;
        }
        if(lists.size()==0)
            return NULL;
        ListNode *head = NULL;//创建目标链表
        ListNode *curr = NULL;
        make_heap(lists.begin(), lists.end(), Comp());
        while(lists.size()>0){
            ListNode *smallest = lists[0];
            if(head == NULL){
                head = smallest;
                curr = smallest;
            }
            else{
                curr->next = smallest;
                curr = curr->next;
            }
            pop_heap(lists.begin(), lists.end(), Comp());//当前smallest移至lists最后
            if(lists[lists.size()-1]->next == NULL){//若当前smallest所在链表已到达最末，弹出该链表
                lists.pop_back();
            }
            else{
                lists[lists.size()-1] = lists[lists.size()-1]->next;
                push_heap(lists.begin(), lists.end(), Comp());
            }
        }
        return head;
    }
};

    