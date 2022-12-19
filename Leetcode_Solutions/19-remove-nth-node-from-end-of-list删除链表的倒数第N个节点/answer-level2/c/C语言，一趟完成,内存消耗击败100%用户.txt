![image.png](https://pic.leetcode-cn.com/825824de5d74780d374298bbb5639886730588cf8acd1a9dde7bde2535c26ec3-image.png)


算法核心：将链表节点放入数组中
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    /*
        方法1：数下链表的个数，然后将正数第num - n个删除；
        方法2：一趟实现， 将各个节点放在数组中；
    */

    //实现方法2
    struct ListNode* cur = head;
    struct ListNode* Node[10000] = {NULL};

    int i = 0;
    //将链表放入数组中
    while(cur){
        Node[i] = cur;
        cur = cur -> next;
        i++;
    }

    //释放头结点
    if (i == n){
        free(Node[i - n]);
        return Node[i - n + 1];
    }

    //需要删除的节点Node[i - n + 1]，让他前面节点Node[i - n]直接指向Node[i - n + 2]即可；
    if (Node[i - n] -> next){
        Node[i - n - 1] -> next = Node[i - n + 1];
    }else{
        Node[i - n - 1] -> next = NULL;
    }

    free(Node[i - n]);
    return head;
}
```
