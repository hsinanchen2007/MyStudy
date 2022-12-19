**将链表看做一个数组,题目就变为《翻转数组》,用双指针解法**
**利用递归的"回溯"性质,自然生成一个尾指针,再人为设置一个首指针,二指针所指元素互相交换即可**
```
class Solution {
public:
    ListNode* low;
    ListNode* reverseList(ListNode* p) {
        low=p;
        operate(p);
        return p;
    }
    void operate(ListNode* high){
        if(high){
            operate(high->next);    // 递归到顶,生成尾指针
            if(low<high)
                swap(low->val,high->val),low=low->next; // 交换元素,移动指针
        }
    }
};
```
