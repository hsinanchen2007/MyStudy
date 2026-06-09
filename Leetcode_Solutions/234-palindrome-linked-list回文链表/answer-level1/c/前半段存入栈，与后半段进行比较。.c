### 解题思路
将前半段存入栈，逐个出栈与后半段逐个对比。
注意总长度的奇偶关系，差一个next的事儿。
### 代码

```c
/* 请自行实现栈代码 */
bool isPalindrome(struct ListNode* head){

    struct ListNode* tmp = head;
    int lstNum = 0;
    int helfNum = 0;
    int helfFlag = 0;

    if (head == NULL || head->next == NULL) {
        return true;
    }

    while (tmp) {
        tmp = tmp->next;
        lstNum++;
    }

    if (lstNum % 2 == 0) {
        helfNum = lstNum / 2;
        helfFlag = 0;
    } else {
        helfNum = lstNum / 2;
        helfFlag = 1;
    }

    tmp = head;

    StackNode *stack = (StackNode *)malloc(sizeof(StackNode));
    if (stack == NULL) {
        return false;
    }
    memset(stack, 0, sizeof(StackNode));
    StackInit(stack, helfNum);

    for (int i = 0; i < helfNum; i++) {
        StackPush(stack, tmp->val);
        tmp = tmp->next;
    }

    if (helfFlag == 1) {
        tmp = tmp->next;
    }

    for (int i = 0; i < helfNum, tmp != NULL; i++) {
        int stackPopNum = 0;
        StackPop(stack, &stackPopNum);
        if (stackPopNum != tmp->val) {
            return false;
        }
        tmp = tmp->next;
    }

    return true;

}
```