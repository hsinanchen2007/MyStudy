
### 83.删除排序链表中的重复元素 - C 语言实现 | 非递归

题目描述：给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例1：

```c
输入: 1->1->2
输出: 1->2
```

示例2：

```c
输入: 1->1->2->3->3
输出: 1->2->3
```

代码：

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL)
        return head;
    
    struct ListNode * point = head;
    while (point != NULL && point->next != NULL) {
        if (point->val == point->next->val) {
            struct ListNode * DeletNode = point->next;
            point->next = point->next->next;
            free(DeletNode);
        } else {
            point = point->next;
        }
    }

    return head;
}
```
![oBHrNd9YdO.png](https://pic.leetcode-cn.com/212d4b96c0a5627f86e8271d751b30c69cbcdc6acaf42f867d89e54f6c632e13-oBHrNd9YdO.png)


解题思路：

​		题目要求是，让我们删除掉一条有序链表中的重复元素，正因为是有序链表，所以我们可以直接从前向后的顺序检查元素间的重复性。
​		基本的算法描述便是，从左向右依次对链表中的节点进行检查，每次检查同时操作两个节点（左：A，右：B），并比较两个节点中的元素是否相同。是，则让 A 节点指向 B 节点的下一个节点，并释放掉 B 节点的空间；不是，则前进一个节点，开始比较下一组节点。
​		但是需要注意几个地方：
​		1.B 节点被释放的时间。当 A 节点的 val 等于 B 节点的 val 时，我们需要先用一个新的变量空间来暂存 B 节点指向的下一个节点的地址，再来释放 B 节点的内存空间，不然的话，会导致 A 节点将无处可指。
​		2.程序结束的条件。因为我们每次在进行判断时，都是同时操作两个节点，并且 A B 节点而言，如果 B 节点为 NULL，则链表肯定到达终点。所以，我们需要将对 B 节点进行的判空操作作为判断链表是否完结的标识。
​		3.特殊情况。在我们上述的设想中，遗漏了一种情况——链表为空。解决办法则是，在获取到链表后，便理解对列表执行判空操作。
 
踩到的坑：

​		1.没有考虑注意到自己是同时操作两个节点，忘记了对 B 节点执行判空操作
​		2.遗漏了空链这一特殊情况