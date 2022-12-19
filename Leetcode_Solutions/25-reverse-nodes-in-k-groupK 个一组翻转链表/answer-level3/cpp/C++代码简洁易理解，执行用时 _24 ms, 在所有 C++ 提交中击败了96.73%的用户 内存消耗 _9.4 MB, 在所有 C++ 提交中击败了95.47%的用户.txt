```
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //步骤1,计算长度
        int len = 0;
        auto t = head;
        while(t){
            t = t->next;
            ++len;
        }
        //步骤2,局部翻转
        auto dummy = ListNode(-1);
        dummy.next = head;
        auto pre = &dummy;
        for(int i = 0;i < len/k;++i){   //以k为单位,需要进行len/k次局部翻转
            auto cur = pre->next;       //这里局部翻转用的是翻转链表II中的pre固定法
            for(int j = 0;j < k-1;++j){ //一次逆转将cur后面的节点挪到pre后面去,k个节点需要挪k-1次
                auto tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            pre = cur;
        }
        return dummy.next;
    }
};
```
