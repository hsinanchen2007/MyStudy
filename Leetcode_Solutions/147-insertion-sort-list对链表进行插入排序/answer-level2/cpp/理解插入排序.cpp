
### 解题思路

解题的关键是需要理解清楚插入排序的思想，在题中已经有动画演示了。

把数组分为两个部分，有序部分和待排序的部分。把第一个结点放在有序部分，用sorted_head指向有序部分的第一个结点，sorted_tail指向有序部分的最后结点，
此时首尾结点都指向第一个结点。

从第二个元素开始考察，依次遍历链表每一个元素，并在有序部分找到合适的位置插入。

如何在有序部分找到合适的位置呢？假设当前考察的结点为cur
- 如果cur大于或者等于sorted_tail，cur直接放在sorted_tail后面;
- 否者从有序部分头结点开始遍历，找到第一个大于cur的结点，剩下的工作就是交换指针的工作了。

### 代码实现
```
ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr) return head;
    if (head->next == nullptr) return head;

    // 开始时，把第一个结点放在有序部分，有序部分的收尾结点都指向第一个结点
    ListNode *sorted_head = head;
    ListNode *sorted_tail = head;
    
    ListNode *cur = head->next; // 从第二个结点开始考察
    while (cur) {
        ListNode *next = cur->next;
        
        if (cur->val >= sorted_tail->val) { // cur大于等于最后一个结点，直接放在有序部分的后面
            sorted_tail->next = cur;
            sorted_tail = cur;
        } else {
            ListNode *pre = nullptr;
            ListNode *sorted_cur = sorted_head;
            
            // 遍历有序部分，找到第一个大于或等于cur的结点，循环结束之后，pre就是cur的前一个结点，sorted_cur就是下一个结点
            while (sorted_cur && sorted_cur->val < cur->val) { 
                pre = sorted_cur;
                sorted_cur = sorted_cur->next;
            }
            
            if (pre) {
                pre->next = cur;
                cur->next = sorted_cur;
            } else { // 比最小的结点还要小
                cur->next = sorted_head;
                sorted_head = cur;
            }
        }
        
        cur = next;
    }
    
    // 最后一个结点next指针可能还指向其它结点，为了安全，把next指针清空。
    sorted_tail->next = nullptr;
    
    return sorted_head;
}
```


### 复杂度分析

- 时间复杂度: 内外两层循环，时间复杂度为`O(n^2)`, 跟数组插入排序时间复杂度一样
- 空间复杂度：只需要几个临时的变量，时间复杂度为`O(1)`