### 解题思路
使用vector存放数据，实现最小堆的pop和push方法
1. 首先依次调用push方法将lists中非null指针存入vector
2. vector不为空时，使用pop取指针tmp存入结果当前链表；如果tmp->next不为null，将tmp->next push到vector中。

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
    vector<ListNode*> min_heap;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto* headptr : lists) {
            if (headptr) push(headptr);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (min_heap.size()) {
            cur->next = pop();
            cur = cur->next;
            if (cur->next) push(cur->next);
            cur->next = 0;
        }
        return dummy->next;
    }

    ListNode* pop() {
        ListNode* result = min_heap[0];
        min_heap[0] = min_heap[min_heap.size()-1];
        min_heap.resize(min_heap.size()-1);
        int i = 0;
        while (2*i+1 < min_heap.size()) {                          // 自顶向下调整堆
            int pos = 2*i+1;
            if (pos+1 < min_heap.size() && min_heap[pos+1]->val <= min_heap[pos]->val) {
                pos ++;
            }
            if (min_heap[i]->val <= min_heap[pos]->val) break;     // 小于左右子较小值时跳出
            swap(min_heap[i], min_heap[pos]);                      // 否则和左右子较小值交换
            i = pos;                                               // 位置调整到左右子较小位置
        }
        return result;
    }
    
    void push(ListNode* p) {
        min_heap.push_back(p);
        int pos = min_heap.size()-1;
        while (pos) {                                              // 自底向上调整
            if (min_heap[pos]->val >= min_heap[(pos-1)/2]->val) {  // 如果当前位置值大于根的值，跳出
                break;
            }
            swap(min_heap[pos], min_heap[(pos-1)/2]); 
            pos = (pos-1)/2;                                       // 位置调整到根位置
        }
    }
};
```