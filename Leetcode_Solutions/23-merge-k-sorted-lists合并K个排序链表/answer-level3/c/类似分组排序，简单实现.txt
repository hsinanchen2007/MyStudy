### 解题思路
![image.png](https://pic.leetcode-cn.com/79a2e1c12458c4fa02f3f30e5ce94083bd4b53b248d039b9ed49779bbba87e1a-image.png)


从题目的描述来理解看，很类似分组排序，只是这里给出的是若干个已经排好序的链表。

最搓一点的办法，就是把所有的的链表都合并到第一个链表上去，但是想当然，这个不是最优的，因为第一个链表会越来越长，每次循环的次数会很大，影响执行效率。

那么怎么能快一些呢，简单一点的办法：
是从两头开始合并，直至相遇；
然后再不断的循环这一过程，直至只有一个链表；

之所以从两头开始合并，是为了简化实现，当然也可以采取其他策略，比如算出中位数，再依次合并也可以。算法效率上差不多。

### 代码

```c
// merge2Lists,顾名思义，把两个链表合并到一起，需要考虑到各种可能的异常
struct ListNode* merge2Lists(struct ListNode* head1, struct ListNode* head2)
{
    struct ListNode * head = NULL;
    struct ListNode * tail = NULL;

    if (head1 == NULL) {
        return head2;
    }

    if (head2 == NULL) {
        return head1;
    }

    if (head1->val <= head2->val) {
        head = tail = head1;
        head1 = head1->next;
    } else {
        head = tail = head2;
        head2 = head2->next;
    }

    while (1) {
        if ((head1 == NULL) && (head2 != NULL)) {
            tail->next = head2;
            head2 = NULL;
            break;
        }
        if ((head2 == NULL) && (head1 != NULL)) {
            tail->next = head1;
            head1 = NULL;
            break;
        }

        if (head1->val <= head2->val) {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;            
        } else {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }

    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int left = 0;
    int right = 0;
    int count = 0;

    if (listsSize <= 0) {
        return NULL;
    }

    do {
        count = 0;
        left = 0;
        right = listsSize-1;
        while (left < right) {
            lists[count++] = merge2Lists(lists[left++], lists[right--]);
        }   
        listsSize = (left == right)? left+1:left;
    } while (listsSize != 1);

    return lists[0];
}
```

