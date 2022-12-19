这题是一道考察指针与链表操作基本功的题目，也就是说对数据结构（链表和栈）要求很高，对算法的要求其实不高。题目要求我们每隔k个结点翻转一次结点间指向，如果链表的最后一部分不足k个结点，则不进行翻转。且要求常数额外空间。举例如下：
有链表：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 ，给定 k = 3;
翻转后：3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 9 -> 8 -> 7 -> 10 -> 11 。

我们分解来看：
翻转前：(1 -> 2 -> 3) -> (4 -> 5 -> 6) -> (7 -> 8 -> 9) -> 10 -> 11 
翻转看：(3 -> 2 -> 1) -> (6 -> 5 -> 4) -> (9 -> 8 -> 7) -> 10 -> 11 

解决这个翻转问题的思路很简单，依次从原链表中读取k个结点，将这k个结点内部指向翻转后，与这部分结点前，后剩余的链表部分连接。观察其中k个结点内部的结点指向翻转问题，我们看到由 (1 -> 2 -> 3)，变成(3 -> 2 -> 1)，这是一个先进后出的结构，用栈很容易实现。那么整体思路就很清晰了，在原链表中依次读取k个结点时，将这些结点压入栈中，等栈中有k个结点后，再依次从栈顶弹出，并改变结点间指向。最后处理，翻转后这k个结点的第一个结点和原链表前部的连接关系，以及翻转后这k个结点的最后一个结点与原链表后部的连接关系。抓住这三个核心点，就不难写出整体的代码如下：
```
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* preHead = new ListNode(-1); // fake head
        preHead->next = head;
        int cnt = 0; // cnt counts to k
        stack<ListNode *> stemp;
        ListNode* p = head; // p is the pointer iterating through the whole linked list
        ListNode* preLog = preHead; //preLog deals with the linkage with the last part
        ListNode* preLogNext = preHead->next; //preLogNext deals with the linkage with the next part
        while(p != NULL){ //loop through the linked list, only once, so the time complexity is O(n)
            stemp.push(p);
            cnt++;
            if(cnt == k){   //using the maximum space of stack of size k
                ListNode* first = stemp.top();
                preLogNext = first->next; //record the linkage to the next part
                stemp.pop();
                ListNode* now = first;
                while(!stemp.empty()){
                    ListNode* top1 = stemp.top();
                    now->next = top1;
                    now = now->next;
                    stemp.pop();
                }
                preLog->next = first; //link to the last part
                preLog = now; // reset the preLog to the last node in the k nodes group
                preLog->next = preLogNext; //link to the next part
                cnt =0;
                p = now; // it's important to set p to the right position of reversed k nodes group
            }
            p = p->next;
        }

        return preHead->next; //taking advantage of the fake head
    }
};
```

总结：这道题本身思路不难，难在数据结构的基本功上。如何使用栈，如何进行链表结点间指向的改变，这道题中如果处理不好指向问题，就会出现循环链表的错误。最好的方式还是在整体思路出来后，考虑到一些小细节。