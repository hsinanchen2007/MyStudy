执行用时 :
0 ms
, 在所有 c 提交中击败了
100.00%
的用户
内存消耗 :
7.6 MB
, 在所有 c 提交中击败了
40.43%
的用户
/***
问题的核心还是要找到不重复的结点，通过进行for循环找到当前元素与前后元素都不相等的指针位置
***/
```
struct ListNode* deleteDuplicates(struct ListNode* head){

    if(!head||!(head->next))  return head;

    struct ListNode * preHead = (struct ListNode *)malloc(sizeof(struct ListNode));//虚拟头结点
    struct ListNode * curNode = NULL;
    struct ListNode * slowP   = NULL;
    struct ListNode * quickP  = NULL;
    int n = 0;
    preHead->next = head;
    curNode = preHead;
    slowP = head;

    while (slowP != NULL) {
        //循环，用来找出不重复的结点，不相等时跳出循环，n=0为初始值，两个元素不相等n就为0
        for (n = 0,quickP = slowP->next; quickP != NULL; n++, quickP = quickP->next) {
            if (slowP->val != quickP->val) {
                break;
            }
        }
        if (n == 0)//当前元素与下一个元素值不相等
        {
            curNode->next = slowP;
            curNode = curNode->next;
        } 
        else if (quickP == NULL) //特殊情况
        {
            curNode->next = NULL;
            break;
        }
        slowP = quickP;//继续进行遍历
    }
    return preHead->next;
}

```
