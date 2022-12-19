### 解题思路一 快慢指针法
    /*
     * 方法1 快慢指针法
     * 设置两个指针都指向头节点
     * 快指针先移动到第k个节点，
     * 剩下n-k个节点未访问
     * 之后快慢指针一起移动，
     * 当快指针指向最后一个节点，
     * 慢指针访问过n-k个节点，
     * 即慢指针指向倒数第k个节点
     * */
### 代码

```cpp
//两遍循环
ListNode getKthFromEnd(ListNode *head, int k) {
    if (head == nullptr || k == 0) {
        return nullptr;
    }

    ListNode *pa = head;
    ListNode *pb = head;

    for (int i = 1; i < k; i++) {
        if (pa->next != nullptr) {
            pa = pa->next;
        } else {
            return nullptr;
        }
    }

    while (pa->next != nullptr) {
        pa = pa->next;
        pb = pb->next;
    }

    return pb;
}

//修改为一遍循环
ListNode getKthFromEnd_2(ListNode *head, int k) {
    if(head == nullptr || k == 0){
        return nullptr;
    }

    ListNode *pa = head;
    ListNode *pb = head;

    //计数访问的节点数
    //只有pa访问到第k个时，pa才开始移动
    int count = 0;
    while (pa != nullptr){
        if(count >= k){
            pb = pb->next;
        }

        pa = pa->next;
        count++;
    }

    //k可能比链表的长度要大
    if(count < k){
        return nullptr;
    }

    return pb;
}
```

### 解题思路二 递归法
    /*
     * 方法2 递归法
     * 用递归访问链表的最后一个节点，
     * 再依次递归出栈，访问每个节点并将k减1，
     * 当k等于0时，就找到了倒数第k个节点。
     *
     * WARNing1 : 当链表很长时，会导致递归栈过深，
     * 栈溢出，运行时间超时的问题
     *
     *  WARNing2 : int &k 的使用
     * 设置为引用，每次递归k的值才能改变
     * */
### 代码

```cpp
ListNode *getKthFromEnd2(ListNode *head, int &k) {
    if(head == nullptr || k == 0){
        return nullptr;
    }

    ListNode* res = getKthFromEnd2(head->next, k);
    k--;

    if(k == 0){
        return head;
    }

    return  res;
}

```