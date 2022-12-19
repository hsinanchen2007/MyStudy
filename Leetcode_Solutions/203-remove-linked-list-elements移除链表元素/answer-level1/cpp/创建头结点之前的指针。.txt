### 解题思路

自己写了第一种方法。效率太低。看了解题就是第二种也不是什么快速的方法。。。
第二种就是多了一个while循环来判断头指针的值是否等于val。不用再去创建指向头结点之前的指针。


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
    // 执行用时 :36 ms, 在所有 C++ 提交中击败了24.26% 的用户
    // 内存消耗 :13.5 MB, 在所有 C++ 提交中击败了5.21%的用户
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return nullptr;
        ListNode* pNode = new ListNode(0);
        pNode->next = head;//pNode指向头结点之前。
        ListNode* p1 = pNode; //使用p1指向前一个节点
        ListNode* p2 = p1->next;//p2指向当前节点。
        while(p2){
            if(p2->val == val){
                p1->next = p2->next;
                
            }
            else{
                p1 = p2;
            }
            p2 = p2->next;
        }
        return pNode->next;//返回Next
    }

    // 执行用时 :28 ms, 在所有 C++ 提交中击败了45.01% 的用户
    // 内存消耗 :13.2 MB, 在所有 C++ 提交中击败了5.21%的用户
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        while(head->val==val){//若头结点的值就等于val，就要移动指针。
            head = head->next;
            if(!head) return nullptr;
        }
        ListNode* pNode = head;
        while(pNode->next){
            if(pNode->next->val==val){//若下一个节点的值等于val，则指向下下个节点、
                pNode->next = pNode->next->next?pNode->next->next:nullptr;
            }else{
                pNode = pNode->next;
                if(!pNode) return head;
            }
        }
        return head;
    }


};
```