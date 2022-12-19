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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||k<=0) return head;
        ListNode* pNode = head;
        int NodeNum = 1;
        while(pNode->next){
            pNode = pNode->next;
            ++NodeNum;
        }
        pNode->next = head;     //构建循环链表
        int CycleNum = NodeNum;   // 注意这里是需要考虑到CycleNum会不会超过int数据类型的！
        /*while(CycleNum<k+1){
            CycleNum *= 2;
        }*/
        CycleNum = CycleNum-(k%CycleNum)-1; //注意：利用取余来替代以往的22倍递乘的方法可以有效的提高时间效率。
        pNode = head;
        while(CycleNum){
            pNode = pNode->next;
            --CycleNum;
        }
        ListNode* pHead = pNode->next;
        pNode->next = nullptr;
        pNode = nullptr;
        return pHead;
    }
};
```