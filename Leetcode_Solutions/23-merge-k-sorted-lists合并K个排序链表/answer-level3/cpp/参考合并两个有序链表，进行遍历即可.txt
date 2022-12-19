### 解题思路
纯小白第一次独立写出困难级的算法有点感动，哈哈哈，这两周刷题没白刷。就是很简单的思路。有很多地方可以优化，欢迎指出，与君共勉！
参考了合并两个有序链表的思路。用循环来对原来表进行调整（删除数组中空的项）。

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
    //对原数组进行遍历，将里面空的项清除
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] == NULL) {
                lists.erase(lists.begin() + i);
            }
        }
    //分别对0、1、2个元素的情况下单独判断
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        if(lists.size() == 2) return func(lists[0],lists[1]);
    //初始化初值
        ListNode *newList = func(lists[0],lists[1]);
    //遍历数组单独拿出来进行两两合并（参考合并两个有序链表）
        for(int i = 2; i < lists.size(); i++) {
            newList = func(newList, lists[i]);
        }
        return newList;
    }

    //（递归）合并两个有序链表
    ListNode* func(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        if(l1->val <= l2->val) {
            l1->next = func(l1->next, l2);
            return l1;
        }else {
            l2->next = func(l1, l2->next);
            return l2;
        }
    }
};
```