### 快慢指针法
假设环外的长度为a，环内的长度为b，设置两个指针pfast和pslow，pfast每次走两步，pslow每次走一步，当pfast和pslow第一次相遇的时候，假设pslow走了s步，pfast走了f步，那么
（1）f=2s
（2）f=s+nb
则可以得到：s=nb
而且由于nb+a始终会在环的入口位置处，因此只要第一次相遇之后，pslow再走a步就可以了。
这个时候可以把pfast重新放到head处，当两个指针再相遇的时候，就是环的入口了。
### 时间/空间复杂度
时间：O（n）
空间：O（1）
### 代码

```cpp
//执行用时 :4 ms, 在所有 C++ 提交中击败了99.90%的用户
//内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode* pfast=head,*pslow=head;
        while(pfast && pfast->next){
            pfast=pfast->next->next;
            pslow=pslow->next;
            if(pfast==pslow){
                pfast=head;
                while(pfast!=pslow){
                    pfast=pfast->next;
                    pslow=pslow->next;
                }
                return pfast;
            }
        }
        return nullptr;
    }
};
```