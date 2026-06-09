1、复杂度o(nlogn)很容易想到用快速排序，
刚开始想通过指针的断裂链接实现排序；操作后发现递归过程中指针的连接会出现问题，暂时放下；
将链表看作静态数组，链表顺序不变，通过改变其中的值实现快排。不过失去了链表的意义。
2、使用归并排序，自底向上。
ListNode* merge(ListNode* A, ListNode* B)，将两段有序链表合成一段有序链表，并返回首元素地址
ListNode* cut(ListNode* list, int n)函数，将链表前n个元素切下来存在list中， 返回剩余元素的首元素
3、自底向上非递归的归并排序，要注意cut()各段的连接，通过建立一个空的头元素，将排好序的各段尾接法接在后面解决。

遗留问题：
1、如何将快速排序的递归写法写成非递归的？
2、链表形式的快速排序怎么写？
3、写一下数组形式的归并排序？

```
快速排序
class Solution {
public:
    ListNode* sortList(ListNode* head);
private:
    void QuickSort(ListNode* begin, ListNode* end);
    ListNode* quick(ListNode* begin, ListNode* end);
    template<class T>
    void swap(T& a, T& b);
};

template<class T>
void Solution::swap(T& a, T& b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

ListNode* Solution::quick(ListNode* begin, ListNode* end)
{
    ListNode* p = begin->next;
    ListNode* ok = begin;
    while (p != end)
    {
        if (p->val < begin->val)
        {
            ok = ok->next;
            if (ok != p)
                swap(ok->val, p->val);
            p = p->next;
        }
        else
            p = p->next;
    }
    swap(ok->val, begin->val);
    return ok;
}

void Solution::QuickSort(ListNode* begin, ListNode* end)
{
    if (begin == end || begin->next == end)
        return;
    ListNode* pivotpoint = quick(begin, end);
    QuickSort(begin, pivotpoint);
    QuickSort(pivotpoint->next, end);
}

ListNode* Solution::sortList(ListNode* head)
{
    QuickSort(head, nullptr);
    return head;
}
```
```
归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head);
private:
    ListNode* cut(ListNode* list, int num);
    ListNode* merge(ListNode* A, ListNode* B);
};

ListNode* Solution::merge(ListNode* A, ListNode* B)
{
    ListNode headnull(-1);
    ListNode* p = &headnull;
    while (A && B)
    {
        if (A->val < B->val)
        {
            p->next = A;
            p = p->next;
            A = A->next;
        }
        else
        {
            p->next = B;
            p = p->next;
            B = B->next;
        }
    }
    p->next = A ? A : B;
    return headnull.next;
}

ListNode* Solution::cut(ListNode* list, int num)
{
    if (!list)
        return nullptr;
    ListNode* p = list;
    int i = 1;
    while (i < num && p)
    {
        p = p->next;
        i++;
    }
    if (!p)
        return nullptr;
    ListNode* temp = p->next;
    p->next = nullptr;
    return temp;
}

ListNode* Solution::sortList(ListNode* head)
{
    ListNode headnull(-1);
    ListNode* p = &headnull;
    p->next = head;          
    ListNode* cur = head;
    int step = 1;
    int size = 0;
    while (cur)
    {
        size++;
        cur = cur->next;
    }

    while (step < size)
    {
        cur = headnull.next;   //*必须将head接到头节点headnull后面，否则只有一个节点时将出错；例如：输入：1；会输出空
        ListNode* cur = head;
        p = &headnull;         //*每轮排序都是新的，cur，p都要初始化
        p->next = nullptr;     //*
        while (cur)
        {
            ListNode* left = cur;
            ListNode* right = cut(left, step);
            cur = cut(right, step);

            p->next = merge(left, right);
            while (p->next)
                p = p->next;
        }
        step *= 2;
    }
    return headnull.next;
}
```

