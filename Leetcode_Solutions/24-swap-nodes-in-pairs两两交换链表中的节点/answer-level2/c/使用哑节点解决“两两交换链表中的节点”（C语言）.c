### 解题思路
典型的单链表体型，设置哑节点方便处理。

1.设置哑元节点dummy

2.设置4个指针，分别时前驱节点hh，待处理节点mm，待处理节点tt，下一组节点tail

3.主要控制hh和tt，指向前驱节点；

4.移动tt两步（注意不要指向下一组节点，会使处理复杂化）

5.这时各个节点情况：【pp】|【mm】【tt】|【tail】【】【】【】

6.调整节点：【pp】|【tt】【mm】|【tail】【】【】【】

7.准备下一次处理:【pp,tt】|【tail】【】【】【】

![image.png](https://pic.leetcode-cn.com/89e7f4a42cbccb522aa3357a9517aeebc15379915982b19500127e7172ba7d32-image.png)


### 代码

```c
/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ln_st;

//【算法思路】链表。设置哑节点，方便处理
struct ListNode* swapPairs(struct ListNode* head){
    ln_st dummy;
    dummy.next = head;

    // hh记录动态头节点，tt记录动态尾节点，mm记录中间节点
    ln_st *hh = &dummy, *tt = &dummy, *mm, *tail;

    //先移动尾节点，并进行计数
    int cnt = 0;
    while(tt != NULL)
    {
        if(cnt != 2)
        {
            cnt++;
            tt = tt->next;
            continue;
        }

        cnt = 0;

        // [hh] | [mm] [tt] | [tail]
        mm = hh->next;
        tail = tt->next;

        // 开始调换
        hh->next = tt;
        tt->next = mm;
        mm->next = tail;

        hh = mm;
        tt = hh;
    }

    return dummy.next;
}


// @lc code=end


```