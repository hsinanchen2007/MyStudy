### 思路
- 这种对称配对题很自然想到使用栈`stack`来进行前半段和后半段对比
### 步骤
1. 将前半段的值压入栈内，应用栈后入先出`LIFO`的性质，对比对称轴左右两边的`val`
2. 遇到不相同的值，返回`false`
- 注意：若节点个数为奇数，正中间的值只有一个，需要跳过
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* count = head;
        int i = 0;
        stack <int> value;
        while(count){
            ++ i;
            count = count -> next;
        }
        if(i == 1)  return true;
        for(int j = i / 2; j > 0; -- j){
            value.push(head -> val);
            head = head -> next;
        }
        if(i % 2 == 1)  head = head -> next;
        for(int j = i / 2; j > 0; -- j){
            if(value.top() != head -> val)  return false;
            else{
                head = head -> next;
                value.pop();
            }
        }
        return true;
    }
};
```