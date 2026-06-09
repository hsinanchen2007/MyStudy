
![微信图片_20190922155527.jpg](https://pic.leetcode-cn.com/eac101a4039d571ea071d17aaf4b944e46053a8a611420ab138ac0a0ea2ad1b6-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190922155527.jpg)



```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL)return head;
    
    struct ListNode* p = head;
    struct ListNode* final = NULL;
    struct ListNode* p__ = p;// 新的结尾
    
    int count = 0;
    while(p->next != NULL)//遍历整个链表得到长度
    {
        count++;
        p = p->next;
    }
    
    count++;
    final = p;//将最后一个元素保存，最后要接到开头
    if(count < k) k = k%count;//求余，得实际要旋转次数
    if(count == 1)return head;
    else if(count == k || k == 0)return head;//当链表长度为k时，或者k为0时原地不动

    p = head;
    int i = 0;
    for(int i = 0; i <= count;)//遍历整个链表
    {
        i++;
        if(i == count-k)//倒数的第k+1个元素，用来当做新链表的结尾
        {   
            p__ = p;
        }
        else if(i == count-k+1) break;//新的开头 //当找到倒数的第k个数时就跳出，用来当做新链表的开头
        p = p->next;
    }
    
    final->next = head;
    head = p;
    p__->next= NULL;//将新的结尾作为空
   
    return head;
}


```
