### 解题思路
这道题有三种解法。 首先想到的是两两合并在归并，看了解题里的归并和队列方法
首先两两合并，就和剑指offer的25题合并两个排序链表类似，。主要的是循环了lists向量，把前两个合并后放到lists[0]中，再让lists[0]和后续的链表合并。

其次是归并，主要的是封装了一个函数，把lists向量分成两半最后再合并。

最后是队列。和两两合并的不同就是使用了一个队列来存储lists向量，速度快了超级多！！看来取队列首部的操作比读取向量内部的操作快很多啊。值得借鉴。

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
    // 执行用时 :152 ms, 在所有 C++ 提交中击败了30.28% 的用户
    // 内存消耗 :8.6 MB, 在所有 C++ 提交中击败了100.00%的用户
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return nullptr;
        if(n==1) return lists[0];
        for(int i = 1;i<lists.size();++i){
            if(lists[i]!=nullptr) lists[0] = mergeCore(lists[0], lists[i]);
        }
        return lists[0];
        queue<ListNode*> temp(deque<ListNode*>(lists.begin(), lists.end()));
        while(temp.size()>1){
            ListNode* pHead1 = temp.front();
            temp.pop();
            ListNode* pHead2 = temp.front();
            temp.pop();
            temp.push(mergeCore(pHead1, pHead2));
        }
        return temp.front();
    }

    ListNode* mergeCore(ListNode* pHead1, ListNode* pHead2){
        ListNode* pRes = new ListNode(0);
        ListNode* pNode = pRes;
        while(pHead1!=nullptr&&pHead2!=nullptr){
            if(pHead1->val < pHead2->val){
                pNode->next = pHead1;
                pHead1 = pHead1->next;
                pNode = pNode->next;
            }
            else{
                pNode->next = pHead2;
                pHead2 = pHead2->next;
                pNode = pNode->next;
            }
        }
        pNode->next = pHead1 == nullptr?pHead2:pHead1;
        return pRes->next;
    }


    // 执行用时 :188 ms, 在所有 C++ 提交中击败了23.53% 的用户
    // 内存消耗 :344.5 MB, 在所有 C++ 提交中击败了5.04%的用户
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return nullptr;
        return merge(lists, 0, n-1);
    }
    ListNode* merge(vector<ListNode*> lists, int start, int end){
        if(start==end) return lists[start];
        if(start+1==end) return mergeCore(lists[start], lists[end]);
        int mid = (end-start)/2+start;
        ListNode* left = merge(lists, start, mid);
        ListNode* right = merge(lists, mid+1, end);
        return mergeCore(left, right);
    }

    ListNode* mergeCore(ListNode* pHead1, ListNode* pHead2){
        ListNode* pRes = new ListNode(0);
        ListNode* pNode = pRes;
        while(pHead1!=nullptr&&pHead2!=nullptr){
            if(pHead1->val < pHead2->val){
                pNode->next = pHead1;
                pHead1 = pHead1->next;
                pNode = pNode->next;
            }
            else{
                pNode->next = pHead2;
                pHead2 = pHead2->next;
                pNode = pNode->next;
            }
        }
        pNode->next = pHead1 == nullptr?pHead2:pHead1;
        return pRes->next;
    }



    // 执行用时 :16 ms, 在所有 C++ 提交中击败了96.95% 的用户
    // 内存消耗 :9.4 MB, 在所有 C++ 提交中击败了100.00%的用户
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return nullptr;
        if(n==1) return lists[0];
        queue<ListNode*> temp(deque<ListNode*>(lists.begin(), lists.end()));
        while(temp.size()>1){
            ListNode* pHead1 = temp.front();
            temp.pop();
            ListNode* pHead2 = temp.front();
            temp.pop();
            temp.push(mergeCore(pHead1, pHead2));
        }
        return temp.front();


    ListNode* mergeCore(ListNode* pHead1, ListNode* pHead2){
        ListNode* pRes = new ListNode(0);
        ListNode* pNode = pRes;
        while(pHead1!=nullptr&&pHead2!=nullptr){
            if(pHead1->val < pHead2->val){
                pNode->next = pHead1;
                pHead1 = pHead1->next;
                pNode = pNode->next;
            }
            else{
                pNode->next = pHead2;
                pHead2 = pHead2->next;
                pNode = pNode->next;
            }
        }
        pNode->next = pHead1 == nullptr?pHead2:pHead1;
        return pRes->next;
    }
};
```