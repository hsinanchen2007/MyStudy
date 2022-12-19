### 解题思路
想到一个很骚的思路，就是利用静态存储作为乘法算子，但是由于提交时，连续测试用例没有释放div的内存，所以通过不了
哈哈哈

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    if(!head)
        return 0;
    static int div=1;
    int ans;
    ans=getDecimalValue(head->next);
    ans+=div*(head->val);
    div*=2;
    return ans;
}
```