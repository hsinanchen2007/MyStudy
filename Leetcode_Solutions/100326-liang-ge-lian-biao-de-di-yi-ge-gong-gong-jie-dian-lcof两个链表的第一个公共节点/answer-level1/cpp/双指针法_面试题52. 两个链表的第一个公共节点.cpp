### 解题思路 双指针法
    /*
     * 本题思路有：
     * 1. 暴力解决
     *    直接对两链表的数据进行逐一比较
     *    时间复杂度O(mn)，空间复杂度O(1)
     *
     * 2. 空间换时间
     *    使用哈希表、栈或数组存储其中一个链表，
     *    再跟另一链表逐一比较
     *    时间复杂度O(m+n)，空间复杂度O(n)或O(m)
     *
     * 3. 双指针
     *    因为如果两链表相交，那么从相交点开始，两链表相同，
     *    倒过来思考，如果从尾部向前遍历，指向两链表的指针，
     *    在链表的步调是一致的，那么只要终止条件一致就能在一轮循环中结束，
     *    所以只要找到两链表的长度距离，时间复杂度就是O(n)
     * */
### 代码

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // 两链表为空的情况
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    unsigned int alen = getListLength(headA);
    unsigned int blen = getListLength(headB);
    int distance = alen - blen;

    ListNode *longnode = headA;
    ListNode *shortnode = headB;

    // 确定长链表，并计算长链表与短链表间的距离
    if (blen > alen) {
        longnode = headB;
        shortnode = headA;
        distance = blen - alen;
    }

    // 长链表指针先遍历distance个节点，
    // 保证两链表接下来遍历长度相等
    for (int i = 0; i < distance; i++) {
        longnode = longnode->next;
    }

    // 普通遍历，如果指针相等或遍历结束即停止
    while (longnode != nullptr && shortnode != nullptr && longnode != shortnode) {
        longnode = longnode->next;
        shortnode = shortnode->next;
    }

    return longnode;
}

unsigned int getListLength(ListNode *head) {
    unsigned int length = 0;
    ListNode *node = head;
    // 计算链表的长度
    while (node != nullptr) {
        ++length;
        node = node->next;
    }

    return length;
}
```
### 巧妙思路
    /*
     * 双指针
     * 找到两链表的差异意图是让遍历时两链表等长，
     * 让两链表都加长为同一长度也是一个解决思路，
     * 巧妙的是，让指向两链表的指针都遍历(m+n)长度，
     * 则必然返回两链表是否有公共节点的结果，
     * 如果不相交返回null，相交则返回指针相等时指向的节点
     * */
### 代码

```cpp
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    // 两链表为空的情况
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    ListNode *pa = headA, *pb = headB;

    // 如果pa与pb不相等就继续遍历
    // 指针循环遍历必然出结果
    // 如果两指针等长且不相交，则第一轮均遍历到pa==pb==nullptr
    while (pa != pb) {
        // 当pa遍历到链表A的末尾，就转向链表B继续遍历
        pa = (pa == nullptr ? headB : pa->next);
        // 当pb遍历到链表B的末尾，就转向链表A继续遍历
        pb = (pb == nullptr ? headA : pb->next);
    }

    return pa;
}

```