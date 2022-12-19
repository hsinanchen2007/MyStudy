### 解题思路
1. 算出链表的长度i，并设置first和last指针。
2. 如果i<k,则表示链表长度小于移动次数，此时需要取模运算，算出最小移动个数
3. 根据i和k的取值，则最小移动步数为：i-k
4. 将`last->next = first;`，将链表串联起来
5. 从first指针开始行走i-k步，并将first的前一个元素的next设置为NULL，也就是说first的前一个元素是last了


### 执行时间
执行用时：4ms，击败了92.56%的用户
内存消耗：7.5MB，击败了74.34%的用户

时间复杂度为：O(n)
空间复杂度为：O(1)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){

    struct ListNode *first = head;
    struct ListNode *last = head;

    int i = 0;
    int step = k;

    if (NULL == head || 0 == k) {
        return head;
    }

    while(NULL != last->next) {
        i++;
        last = last->next;
    }
    i++; //加上最后一个

    if (i < k) {
        step = k%i;
    }
    step = i - step;

    last->next = first;
    
    for(int i = 0; i<step;i++) {
        last = first;
        first = first ->next;
    }

    if (NULL != last && NULL != last->next ) {
        last->next = NULL;
    }

    return first;

}
```