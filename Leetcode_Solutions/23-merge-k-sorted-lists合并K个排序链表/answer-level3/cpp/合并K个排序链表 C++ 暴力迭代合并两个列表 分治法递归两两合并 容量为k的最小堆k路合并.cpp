### 解题思路
此处撰写解题思路

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

/**
 * 思路1：合并两个有序链表，暴力迭代。
 *
 * 思路2：分治法。链表两两合并。
 *
 * 思路3：用容量为K的最小堆或着优先级队列，把链表的头结点都放进去，然后出队当前优先队列中最小的，挂上链表，然后让出队的那个节点的下一个入队，再出队当前优先队列中最小的，直到优先队列为空。时间复杂度：O(n*log(k))，n是所有链表中元素的总和，k是链表个数。空间复杂度：O(K)
 *
 */

// 最小堆
class MyHeap {
public:
    // 堆构造函数
    MyHeap(uint64_t k) {
        // 申请k个元素的数组
        _heap.reserve(k);
    }

    // 堆的插入，插入至末尾，由下至上调整
    void insert(ListNode *node) {
        // 不同于push_back()，emplace_back()不是拷贝插入，而是引用插入
        _heap.emplace_back(node);
        uint64_t child = _heap.size() - 1;
        while (child > 0) {
            uint64_t pa = (child - 1) / 2;
            // 每次都跟中间的比较向前调整，_heap不用保持有序，只要保证_heap[0]是最小的即可
            if (_heap[child]->val < _heap[pa]->val) {
                swap(_heap[child], _heap[pa]);
            }else break;
            child = pa;
        }
    }
    
    // 堆的删除，首尾交换，由上至下调整
    void pop() {
        // 头尾交换
        swap(_heap[0], _heap[_heap.size() - 1]);
        // 末尾pop掉
        _heap.pop_back();
        uint64_t pa = 0, child = 1;
        // 把交换上来的头，向后调整
        while (pa * 2 + 1 < _heap.size()) {
            child = pa * 2 + 1;
            if (child + 1 < _heap.size())
                child = _heap[child]->val <= _heap[child + 1]->val ? child : child + 1;
            if (_heap[child]->val < _heap[pa]->val)
                swap(_heap[child], _heap[pa]);
            else break;
            pa = child;
        }
    }

    // 返回堆顶元素
    ListNode *top() {
        if(_heap.empty()) return NULL;
        return _heap[0];
    }

    // 判断堆是否为空，即判断数组是否为空
    bool empty() {
        return _heap.empty();
    }

private:
    vector<ListNode *> _heap;
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 分治法
        // return merge(lists,0,lists.size()-1);
        // 最小堆
        return mergeByHeap(lists);
    }
    
    // 分治法
    // lists：需要合并的链表数组 
    // left：链表数组的左边界 
    // right：链表数组的右边界
    ListNode* merge(vector<ListNode*> &lists,int left,int right) {
        if(lists.empty()) return NULL;
        if(left == right) return lists[left];
        int mid = left + (right - left)/2;
        // 递归调用
        ListNode *l1 = merge(lists,left,mid);
        ListNode *l2 = merge(lists,mid+1,right);
        // 合并两个有序链表
        return mergeTwoLists(l1, l2);
    }
    
    // 最小堆(或者优先队列)
    ListNode* mergeByHeap(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        MyHeap heap(lists.size());
        // 循环获取链表数组里的链表，将每一个链表头插入到堆中
        for (auto &it : lists) {
            if (it) heap.insert(it);
        }
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        // 堆非空
        while (!heap.empty()) {
            // 获取堆顶
            ListNode *temp = heap.top();
            // 堆顶出堆
            heap.pop();
            p->next = temp;
            // 如果堆顶链表存在下一个节点，下一个节点插入堆
            if (temp->next)
                heap.insert(temp->next);
            p = p->next;
        }
        return dummy->next;
    }
    
    // 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 头节点
        ListNode dummyHead(0);
        // p指针指向头节点，用以指针操作
        ListNode *p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;       
            } 
            else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        // 当l1或l2有一个指向null了，把另一个的加进p链表里
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};




#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MyHeap {
private:
    vector<ListNode *> _heap;
    
public:
    MyHeap(uint64_t k) {
        _heap.reserve(k);
    }

    void insert(ListNode *node) {
        _heap.emplace_back(node);
        uint64_t child = _heap.size() - 1;
        while (child > 0) {
            uint64_t pa = (child - 1) / 2;
            if (_heap[child]->val < _heap[pa]->val) {
                swap(_heap[child], _heap[pa]);
            }else break;
            child = pa;
        }
    }
    
    void pop() {
        swap(_heap[0], _heap[_heap.size() - 1]);
        _heap.pop_back();
        uint64_t pa = 0, child = 1;
        while (pa * 2 + 1 < _heap.size()) {
            child = pa * 2 + 1;
            if (child + 1 < _heap.size())
                child = _heap[child]->val <= _heap[child + 1]->val ? child : child + 1;
            if (_heap[child]->val < _heap[pa]->val)
                swap(_heap[child], _heap[pa]);
            else break;
            pa = child;
        }
    }

    ListNode *top() {
        if(_heap.empty()) return NULL;
        return _heap[0];
    }

    bool empty() {
        return _heap.empty();
    }
};

ListNode* mergeByHeap(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    MyHeap heap(lists.size());
    for (auto &it : lists) {
        if (it) heap.insert(it);
    }
    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;
    while (!heap.empty()) {
        ListNode *temp = heap.top();
        heap.pop();
        p->next = temp;
        if (temp->next) 
            heap.insert(temp->next);
        p = p->next;
    }
    return dummy->next;
}

int main() {
    ListNode node1(1); ListNode node2(4); ListNode node3(5); 
    ListNode *l1 = &node1; node1.next = &node2; node2.next = &node3;
    ListNode node4(1); ListNode node5(3); ListNode node6(4);
    ListNode *l2 = &node4; node4.next = &node5; node5.next = &node6;
    ListNode node7(2); ListNode node8(6);
    ListNode *l3 = &node7; node7.next = &node8;
    vector<ListNode*> lists = {l1, l2, l3};
    ListNode *res = mergeByHeap(lists);
    while (res) {
        if (res->next) cout << res->val << "->";
        else cout << res->val;
        res = res->next;
    }
}




```