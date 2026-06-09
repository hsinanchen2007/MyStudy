
# 问题思路：

问题是

![搜狗截图20年02月13日1308_1.png](https://pic.leetcode-cn.com/e5dcec55ce3724cf99e440e2adae21f63e44c940945cde2442698902a09b82f5-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B402%E6%9C%8813%E6%97%A51308_1.png)

**注：abcdef所代表的是题目的输入链表，称为旧链表，以Tail作为结尾的是准备输出的链表作称为新链表。**


 算法可以分成两层遍历

1、外层：外层遍历是把当前已经调整好的链表尾部Tail连接到下一个调整好的子模块的首部并更新Tail为当前新链表的最后一个位置，图中的newTail；

![搜狗截图20年02月13日1310_2.png](https://pic.leetcode-cn.com/5ba8aa4b315666d9b035d9b4cf8844a5075f60374ad824379261b6bcace5143c-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B402%E6%9C%8813%E6%97%A51310_2.png)


2、内层:在每一步外层循环中需要有一个内层循环即把abcd变成dcba；

![搜狗截图20年02月13日1310_3.png](https://pic.leetcode-cn.com/87add9b530d8e6af53f2b298f21ca393d47ffc4a1985ceba489aba88302fd455-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B402%E6%9C%8813%E6%97%A51310_3.png)


# 代码过程

- 首先是有一个dummy哑结点，最后的输出应为dummy->next，同时这个dummy也可以是外层循环最早的初始Tail，在初始化的时候由于新链表中只有这一个节点，因此这个dummy不指向任何节点。
- head表示还没有确定的，接下来可能会连接的首部，在主函数第二个while循环中，判断旧链表的长度是否够一个小周期。如果不够的话，head就是最后一小块的首部，用上一个模块的Tail直接连接首部就可以（下图左Case1），然后可以安排输出了；如果够的话Tail应该指向下一个调整好的小模块的首部，这个首部的位置可以用下面的函数reversegroup来给出，连接好了以后记得要更新Tail，把Tail更新到指向为空（下图右Case2）。**注：reversegroup除了给出了调整好的小模块的首部，还把这个小模块最后位置指向NULL**
![搜狗截图20年02月13日1325_4.png](https://pic.leetcode-cn.com/01770f90f5290d01533c808e041b5e72fbaea3daefd5c3d2ce689235d2de6480-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B402%E6%9C%8813%E6%97%A51325_4.png)

- 关于reversegroup，需要三个变量tail，cur和ahead；这里的命名方法根据即将生成的两个连接的前后顺序即新生成的链表应该是ahead->cur->tail;在实现中tail（区别上面的Tail，这里t小写）指的是当前已经完成翻转的链表的第一个节点，这个节点以及它后面连接的节点不会再在循环中发生变化；cur是在这个循环中要调整的节点；但是由于在旧链表中cur指向的是ahead，当我们把cur指向tail时会丢失ahead这个节点，因此以ahead这个变量存储ahead这个点。如图
![搜狗截图20年02月13日1344_5.png](https://pic.leetcode-cn.com/e2a953bf3df03e0143c3e028328df80dc0a23f5237324a93a9a15489a69ec1c7-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B402%E6%9C%8813%E6%97%A51344_5.png)

# 运行结果
![搜狗截图20年02月13日1354_6.png](https://pic.leetcode-cn.com/0db1c7957f01e43261f85ba50d6a0884ea7611a0ed152ad023064a16292f95b2-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B402%E6%9C%8813%E6%97%A51354_6.png)


C++ Code：

```
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head == NULL)return head;
        ListNode* dummy = new ListNode(0);
        ListNode* Tail = dummy;//Tail是当前已经确定的尾部
        //ListNode* Head = head;//还没有确定的首部
        ListNode* p=head;//游标
        int count = 0;
        while (head) {
            count = 0;
            while ((p != NULL) & (count < k)) {
                p = p->next;
                count++;
            }
            if (count < k) {//如果小于k个，则用上一个模块的Tail直接连接首部就可以
                Tail->next = head;
                return dummy->next;//输出
            }
            else {//如果不小于k个，
                Tail->next = reversegroup(head, k);//更新已经确定的尾部
                while (Tail->next != NULL)Tail = Tail->next;//更新Tail，把Tail更新到指向为空
                head = p;//更新没有确定的首部
            }
        }
        return dummy->next;
    }
    ListNode* reversegroup(ListNode* head, int k) {//从abcd变成bcda
        ListNode* cur;
        ListNode* tail;//当前已经完成翻转的链表的第一个节点
        ListNode* ahead;//存储旧链表中cur指向的节点
        tail = NULL;
        cur = NULL;
        ahead = head;
        int count = 1;
        while (count < k) {
            cur = ahead;
            ahead = cur->next;//存储旧链表中cur指向的节点
            cur->next = tail;//指向已经完成翻转的链表的第一个节点
            tail = cur;//更新tail
            count++;
        }
        ahead->next = tail;
        return ahead;//返回小模块的第一个节点，用以作为连接外层循环Tail指向的对象
    }
};
```
