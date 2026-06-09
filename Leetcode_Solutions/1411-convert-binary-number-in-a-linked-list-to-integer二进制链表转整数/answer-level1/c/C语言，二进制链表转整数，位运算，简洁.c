思路：位运算
1. 每取 1 位数字，将当前所有数位 `左移` 1 位
2. 通过位运算 `或` 将取出数字存入最低位

```C
int getDecimalValue(struct ListNode* head){
    int res = 0;
    for ( ; head; head = head->next) 
        res = (res << 1) | head->val;
    return res;
}
```
