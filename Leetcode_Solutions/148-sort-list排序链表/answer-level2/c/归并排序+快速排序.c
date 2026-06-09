# 解题思路

首先，回顾一下常见排序算法及各自的时间、空间复杂度：

![](https://pic.leetcode-cn.com/b40e0623a1f8836318d60e6beba93ea89c6453675cbb86b4f1612df52f4de628.png)

根据题意，本题要求时间复杂度$O(nlgn)$，因此可以排除选择排序和插入排序，而冒泡排序本身不适合单链表，也可以一并排除，剩下来主要有归并排序、快速排序和堆排序。其中堆排序需要新开一个数组转存数据来构建堆，空间复杂度为$O(n)$，也不符合题意要求。

归并排序在对数组进行排序时，需要一个临时数组来存储所有元素，空间复杂度为$O(n)$。但是利用归并算法对单链表进行排序时，可以通过next指针来记录元素的相对位置，因此时间复杂度也为$O(1)$。 

## 快速排序

快速排序的主要思路如下：

- 对于一个数组A，选定一个基准元素
- 遍历剩余元素，并与基准元素进行比较
- 按比较结果的大小将剩余元素分成两组，一组全部比基准元素大，记为B，另外一组全部基准元素小，记为S
- 将基准元素的位置挪到比它小的那组元素的最后
- 分别对B和S重复以上4个步骤，直到所有的元素都已经排序成功

我们来分析下算法的时间复杂度，由于单链表只能从链表头节点向后遍历，必须选择头节点作为基准元素。这样第二步的遍历操作的时间复杂度就是$O(n)$，而第三、第四步会将链表划分为$lgn$段，因此总体的时间复杂度为$O(nlgn)$。

示意图如下：

![](https://pic.leetcode-cn.com/038669520c28abb89efe76fdb9925e1f9d9f59719b76d2bbd2abfcf0eb45beae.png)

![](https://pic.leetcode-cn.com/9e8a5f91282234aca81194da0c6b0b021a03ff0d3059b33cd78f7d70aa713d55.png)

**图片来自[www.w3resource.com](https://www.w3resource.com/csharp-exercises/searching-and-sorting-algorithm/searching-and-sorting-algorithm-exercise-9.php)**

## 归并排序

和快排一样，归并排序也是基于分治的思想，但是不同的是，分完了以后后面还需要从底层开始向上合并，主要思想如下：

- 遍历链表L，找到链表中间节点将链表分成两部分L1，L2
- 分别对L1、L2重复进行遍历并分组，直到每个链表近含有一个元素为止
- 然后调用合并两个有序链表的函数将链表两两合并，直到全部完成为止

示意图如下：

![归并排序](https://pic.leetcode-cn.com/920dcde1f66ee293a552980cf5189f5e67cfafcb816348865938db7c19a56e64.jpg)

链表的归并排序除了找到中间节点的操作必须遍历链表外，其它操作与数组的归并排序基本相同，而对于中间节点的寻找也是关键所在。可以采用slow，fast遍历的方法来确定链表的中间节点。简单说就是slow指针每次移1位，fast指针每次移2位，到了fast指向Null的时候，slow的位置就是链表的中间节点。下面是一个寻找7个元素链表中间节点的示意图：

![](https://pic.leetcode-cn.com/793094449246f7ee18af8c24e47be2d281189e3ec946bbba47e8b2189b176ae6.png)

接下来是以上两种算法的代码部分，其中归并算法需要参考[Task3](http://datacruiser.io/2019/08/05/Leetcode-%E8%85%BE%E8%AE%AF%E7%B2%BE%E9%80%8950%E9%A2%98-No-4-23-%E5%90%88%E5%B9%B6K%E4%B8%AA%E9%93%BE%E8%A1%A8/)中的合并两个有序链表的函数。

# 代码

## 快速排序

需要注意的是，在一般实现的快排单中，我们通过首尾指针来对元素进行切分，正如上面的示意图所示。但是本题是单链表，只能够单向遍历，下面采用快排的另外一种方法来对元素进行切分，思路是一样的，实现细节略有不同。

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//指针交换辅助函数
void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

struct ListNode *partion(struct ListNode *left,struct ListNode *right)
{
    if(left == right || left->next == right)    //如果只有一个元素或者两个元素，则直接返回第一个指针
        return left;
    int pivot = left->val;    //选择头节点作为基准元素
    struct ListNode *p1 = left ,*p2 = left->next; 
    /*定义两个辅助指针p1，p2,这两个指针均往next方向移动，移动的过程中保持p1之前的值都小于选定的pivot，
    p1和p2之间的值都大于选定的pivot，那么当p2走到末尾时交换p1的值与pivot便完成了一次切分*/
    
    while(p2 != right)
    {   
    //从left开始向后进行一次遍历，大于pivot值时，p1向前走一步，交换p1与p2的值
        if(p2->val < pivot)
        {
            p1 = p1->next;
            swap(&p1->val, &p2->val);
        }
        p2 = p2->next;
    }
    swap(&p1->val, &left->val);
    return p1;
    free(p2); //释放p2指针的内存

}
    
void quick_sort(struct ListNode *left,struct ListNode *right)
{
    if(left == right||left ->next == right)    
        return;
    struct ListNode *mid = partion(left, right);
    quick_sort(left, mid);
    quick_sort(mid->next, right);
}
   
struct ListNode* sortList(struct ListNode* head) 
{
    if(head==NULL||head->next==NULL)    
        return head;
    quick_sort(head, NULL);
    return head;
}
```

## 归并排序

```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *cur = head;
    
    while(l1 && l2)
    {
        if(l1->val > l2->val)
        {
            cur->next = l2;
            l2 = l2->next;
        }
        else
        {
            cur->next = l1;
            l1 = l1->next;
        }
        cur = cur->next;
    }
    
    cur->next = l1 ? l1:l2;
    return head->next;
}

struct ListNode* sortList(struct ListNode* head)
{
	if(!head || !head->next)
		return head;
	struct ListNode *slow = head, *fast = head, *pre = head;
	while(fast && fast->next)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = NULL;
	return mergeTwoLists(sortList(head), sortList(slow));//slow为原链表的中间节点
}


```
