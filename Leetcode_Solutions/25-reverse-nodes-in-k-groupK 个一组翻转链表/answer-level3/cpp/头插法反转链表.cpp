![提交记录.png](https://pic.leetcode-cn.com/cae5d03328151e3011fa8a6b9ff419a4cc13bc654404aba6c84d9865099fb68a-%E6%8F%90%E4%BA%A4%E8%AE%B0%E5%BD%95.png)

### 解题思路
共四步
1. 计算链表总长度 len
2. 计算 len/k 向下取整，得到 k 个一组，共几组
3. 使用头插法反转链表。每翻转 k 个节点，更新一次头的位置
4. 将剩余的节点接在新链表尾部

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1) return head;
        ListNode *dummyHead=new ListNode(0); // dummyHead
        ListNode *tmp,*tmpHead,*work;
        int listLength=0;
        tmpHead=head;
        while(tmpHead!=NULL){ // 计算链表长度
            listLength++;
            tmpHead=tmpHead->next;
        }
        int turns=listLength/k; // 计算以 k 个节点一组，共有多少组
        work=head; // 指向原链表的工作指针
        tmpHead=dummyHead; // 头插法工作时的链表头
        for(int i=0;i<turns;i++){ // k 个一组，反转 turns 次
            for(int j=0;j<k;j++){ // 头插法反转 k 个节点
                tmp=work->next;
                work->next=tmpHead->next;
                tmpHead->next=work;
                work=tmp;
            }
            for(int j=0;j<k;j++){ // 更新临时链表头
                tmpHead=tmpHead->next;
            }
        }
        tmpHead->next=work; // 将剩余的节点接在新链表的尾部
        return dummyHead->next;
    }
};
```