### 解题思路
第一个是双指针，建两个指针，都等于head。
rear指针每次走两个，front每次走一个。
当rear指向NULL，或者自己就是NULL时front就在中间节点
返回front就好了。
第二个方法遍历一次，获得链表的总长度，然后再走len/2就是中间节点了。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* rear = malloc(sizeof(struct ListNode));
    struct ListNode* front = malloc(sizeof(struct ListNode));
    front = rear = head;
    while(rear!=NULL&&rear->next!=NULL){
        front = front ->next;
        rear = rear ->next -> next;
    }
    return front;
}

/*
struct ListNode* middleNode(struct ListNode* head){
    int cou=0;
    struct ListNode* rear = malloc(sizeof(struct ListNode));
    rear = head;
    while(rear!=NULL){
        ++cou;
        rear = rear ->next;
    }
    rear = head;
    int k = cou/2;
    for(int i =1;i<=k;i++){
        rear = rear->next;
    }
    return rear;
}
*/
```