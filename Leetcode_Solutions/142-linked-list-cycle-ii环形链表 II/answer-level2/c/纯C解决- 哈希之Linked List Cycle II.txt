### 解题思路
哈希表解决，我看了一下题解，我是唯一一个C语言实现hash的方法的。。。就是刚......

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MaxSize 10000
struct ListNode *detectCycle(struct ListNode *head) {  
    if(!head)
    return NULL;
    int hash_address[MaxSize]={0};
    int i;
    int mark=0;

    while(head->next)
    {
        int addr=((int )head%MaxSize);//哈希函数
        
        if(hash_address[addr]==0)//空
        {
            hash_address[addr]=head;
        }
        else
        {
            while(hash_address[addr]!=0)
            {
            if((int )head==hash_address[addr])
            {
                return head;
            }
            else
            {
                addr++; //解决冲突
                addr%=MaxSize;
            } 
            }
            hash_address[addr]=head; 
        }
        head=head->next;
        mark++;
    }
    return  NULL;
}
```