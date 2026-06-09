### 解题思路
此处撰写解题思路
1.首先统计链表长度，如果链表长度小于3则无需插入直接返回。
2.计算在当前链表长度下最多能从尾部获取几个节点，比如：假设n为链表长度，m为尾部可用节点个数，则有 
n=3, m=1; 
n=4, m=1;
n=5, m=2;
n=6, m=2;
n=7, m=3;
n=8, m=3
 ....
以此类推。
3.遍历链表找到待插入节点的位置并从该位置开始截断链表，前一部分为主体 后一部分为待插入部分但需要做反向处理
4.执行子链表插入操作
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void reorderList(struct ListNode* head){

    struct ListNode *p = head;
    struct ListNode *q = NULL;
```javascript []
console.log('Hello world!')
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
    int totalLen = 0;
    //首先统计链表长度
    while(NULL != p) {
        totalLen++;
        p = p->next;
    }
    //如果链表长度小于3则无需插入直接返回
    if (totalLen < 3) {
        return;
    }
    //计算在当前链表长度下最多能从尾部获取几个节点，比如：假设n为链表长度，m为尾部可用节点个数，
    //则有 n=3, m=1; n=4, m=1;n=5,m=2;n=6,m=2;n=7,m=3;n=8,m=3 ....以此类推。
    int revCount = floor(totalLen / 2.0f - 0.5f);
    int keepLen = totalLen - revCount;
    int i = 0;
    p = head;
    //遍历链表找到待插入节点的位置并从该位置开始截断链表，前一部分为主体 后一部分为待插入部分
    while(NULL != p) {
        i++;
        if (i < keepLen) {
            p = p->next;
        } else if(i == keepLen){ //找到分界点截断链表
            struct ListNode* tmp = p->next;
            p->next = NULL;
            p = tmp;
        } else {//分界点以后的节点反向为一个待插入的子链表
                struct ListNode* tmp = p->next;
                p->next = q;
                q = p;
                p = tmp;
        } 
    }
    p = head;
    //执行子链表插入操作
    while(NULL != p && NULL != q) {
        struct ListNode* tmp1 = p->next;
        struct ListNode* tmp2 = q->next;
        p->next = q;
        q->next = tmp1;
        p = tmp1;
        q = tmp2;
    }


}
```