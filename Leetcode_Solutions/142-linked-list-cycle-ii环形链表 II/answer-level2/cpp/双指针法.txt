![image.png](https://pic.leetcode-cn.com/2c80fb51f4adcec6332134e47a317e35b9758e188fd5bb0653ae2a7d188d5d04-image.png)
前后两个指针，步频都是1，若没有环则后指针率先指向nullptr；若有环，则后指针位于前指针前的时候说明循环了，此时后指针指向入环处。

```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == nullptr) return head;
        ListNode *pin1 = head;
        ListNode *pin2 = head->next;
        while(pin2 != nullptr){
            if (pin2 <= pin1)
                return pin2;
            pin1 = pin1->next;
            pin2 = pin2->next;
        }
        
        return pin2;
    }
};
```



