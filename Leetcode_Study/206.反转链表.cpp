/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

/*

https://leetcode.cn/problems/reverse-linked-list/

206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 

示例 1：

输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：

输入：head = [1,2]
输出：[2,1]

示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000
 

进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

通过次数1,069,647提交次数1,465,235

*/

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution100 {
public:
    // 2022.6.4, from 极客时间覃超算法训练營
    ListNode* reverseList(ListNode* head) {
        // define two nodes for previous and current node
        ListNode *prevNode = NULL;
        ListNode *currNode = head;

        // below while loop code os a standard template
        // to reverse linked list node
        while (currNode) {
            // save current node's next node
            ListNode *tmp = currNode->next;

            // reverse node happened here
            currNode->next = prevNode;

            // current node becomes previous node
            prevNode = currNode;

            // next node becomes current node
            currNode = tmp;
        }

        // inside while loop, tmp may be NULL node, and once that
        // loop finished and assign tmp to current node, current
        // node will become NULL, so we must return previous
        // node here, not current node
        return prevNode;
    }
};


class Solution99 {
public:
    // 2022.6.5, from AcWing https://www.acwing.com/video/1584/
    ListNode* reverseList(ListNode* head) {
        // corner case when head itself is NULL
        if (!head) return NULL;

        // define two nodes
        auto a = head, b = head->next;

        // keep next one until b is NULL
        while (b) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }

        // trick, remember set head's next to NULL as it is now end node
        // below statement is must have
        head->next = NULL;

        // why a not b? Because above while condition is b, so when
        // it stops, that means b is NULL and a is the node before b,
        // so return a not return b
        return a;
    }
};


class Solution98 {
public:
    //2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/reverse-linked-list.cpp
    // Time:  O(n)
    // Space: O(1)
    ListNode* reverseList(ListNode* head) {
        auto dummy = ListNode{0};

        while (head) {
            auto tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }

        return dummy.next;
    }
};


class Solution97 {
public:
    // 2022.6.14, from https://ke.algomooc.com/detail/v_625c124fe4b09dda125c1519/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_624d3a91e4b01a4851edb490
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    ListNode* reverseList(ListNode* head) {

        // 寻找递归终止条件
        // 1、head 指向的结点为 null 
        // 2、head 指向的结点的下一个结点为 null 
        // 在这两种情况下，反转之后的结果还是它自己本身
        if( head == NULL || head->next == NULL)  return head;

        // 不断的通过递归调用，直到无法递归下去，递归的最小粒度是在最后一个节点
        // 因为到最后一个节点的时候，由于当前节点 head 的 next 节点是空，所以会直接返回 head
        ListNode *cur = reverseList(head->next);

        // 比如原链表为 1 --> 2 --> 3 --> 4 --> 5
        // 第一次执行下面代码的时候，head 为 4，那么 head.next = 5
        // 那么 head.next.next 就是 5.next ，意思就是去设置 5 的下一个节点
        // 等号右侧为 head，意思就是设置 5 的下一个节点是 4
        
        // 这里出现了两个 next
        // 第一个 next 是「获取」 head 的下一节点
        // 第二个 next 是「设置」 当前节点的下一节点为等号右侧的值
        head->next->next = head;


        // head 原来的下一节点指向自己，所以 head 自己本身就不能再指向原来的下一节点了
        // 否则会发生无限循环
        head->next = nullptr;

        // 我们把每次反转后的结果传递给上一层
        return cur;

    }
};


class Solution96 {
public:
    // 2022.7.27, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.md
    /*
        本题我录制了B站视频，帮你拿下反转链表 | LeetCode：206.反转链表，相信结合视频在看本篇题解，更有助于大家对链表的理解。
        如果再定义一个新的链表，实现链表元素的反转，其实这是对内存空间的浪费。

        其实只需要改变链表的next指针的指向，直接将链表反转 ，而不用重新定义一个新的链表，如图所示:

        206_反转链表

        之前链表的头节点是元素1， 反转之后头结点就是元素5 ，这里并没有添加或者删除节点，仅仅是改变next指针的方向。
        那么接下来看一看是如何反转的呢？

        我们拿有示例中的链表来举例，如动画所示：

        首先定义一个cur指针，指向头结点，再定义一个pre指针，初始化为null。

        然后就要开始反转了，首先要把 cur->next 节点用tmp指针保存一下，也就是保存一下这个节点。

        为什么要保存一下这个节点呢，因为接下来要改变 cur->next 的指向了，将cur->next 指向pre ，此时已经反转了第一个节点了。
        接下来，就是循环走如下代码逻辑了，继续移动pre和cur指针。

        最后，cur 指针已经指向了null，循环结束，链表也反转完毕了。 此时我们return pre指针就可以了，pre指针就指向了新的头结点。

        双指针法
    */
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur) {
            temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre; // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};


class Solution95 {
public:
    // 2022.7.27, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.md
    /*
        递归法相对抽象一些，但是其实和双指针法是一样的逻辑，同样是当cur为空的时候循环结束，不断将cur指向pre的过程。
        关键是初始化的地方，可能有的同学会不理解， 可以看到双指针法中初始化 cur = head，pre = NULL，在递归法中可
        以从如下代码看出初始化的逻辑也是一样的，只不过写法变了。具体可以看代码（已经详细注释），双指针法写出来之后，
        理解如下递归写法就不难了，代码逻辑都是一样的。

        递归法
    */
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);
    }
    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head);
    }

};


class Solution94 {
public:
    // 2022.7.27, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.md
    /*
        我们可以发现，上面的递归写法和双指针法实质上都是从前往后翻转指针指向，其实还有另外一种与
        双指针法不同思路的递归写法：从后往前翻转指针指向。
    */
    ListNode* reverseList(ListNode* head) {
        // 边缘条件判断
        if(head == NULL) return NULL;
        if (head->next == NULL) return head;
        
        // 递归调用，翻转第二个节点开始往后的链表
        ListNode *last = reverseList(head->next);
        // 翻转头节点与第二个节点的指向
        head->next->next = head;
        // 此时的 head 节点为尾节点，next 需要指向 NULL
        head->next = NULL;
        return last;
    }
}; 


class Solution93 {
public:
    // 2022.7.27, from https://ke.algomooc.com/detail/v_625c124fe4b09dda125c1519/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_624d3a91e4b01a4851edb490
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    ListNode* reverseList(ListNode* head) {

        // 寻找递归终止条件
        // 1、head 指向的结点为 null 
        // 2、head 指向的结点的下一个结点为 null 
        // 在这两种情况下，反转之后的结果还是它自己本身
        if( head == NULL || head->next == NULL)  return head;

        // 不断的通过递归调用，直到无法递归下去，递归的最小粒度是在最后一个节点
        // 因为到最后一个节点的时候，由于当前节点 head 的 next 节点是空，所以会直接返回 head
        ListNode *cur = reverseList(head->next);

        // 比如原链表为 1 --> 2 --> 3 --> 4 --> 5
        // 第一次执行下面代码的时候，head 为 4，那么 head.next = 5
        // 那么 head.next.next 就是 5.next ，意思就是去设置 5 的下一个节点
        // 等号右侧为 head，意思就是设置 5 的下一个节点是 4
            
        // 这里出现了两个 next
        // 第一个 next 是「获取」 head 的下一节点
        // 第二个 next 是「设置」 当前节点的下一节点为等号右侧的值
        head->next->next = head;


        // head 原来的下一节点指向自己，所以 head 自己本身就不能再指向原来的下一节点了
        // 否则会发生无限循环
        head->next = nullptr;

        // 我们把每次反转后的结果传递给上一层
        return cur;

    }
};


class Solution92 {
public:
    // 2022.7.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/206.%20Reverse%20Linked%20List
    // OJ: https://leetcode.com/problems/reverse-linked-list/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Solution 1. Iterative
    ListNode* reverseList(ListNode* head) {
        ListNode h;
        while (head) {
            auto p = head;
            head = head->next;
            p->next = h.next;
            h.next = p;
        }
        return h.next;
    }
};


class Solution91 {
    // 2022.7.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/206.%20Reverse%20Linked%20List
    // OJ: https://leetcode.com/problems/reverse-linked-list/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    // Solution 2. Recursive
    array<ListNode*, 2> reverse(ListNode *head) {
        if (!head->next) return {head, head};
        auto [h, t] = reverse(head->next);
        t->next = head;
        head->next = NULL;
        return {h, head};
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        return reverse(head)[0];
    }
};


class Solution90 {
public:
    // 2011.7.27, from https://walkccc.me/LeetCode/problems/0206/
    // Time: O(n)
    // Space: O(n)
    // Approach 1: Recursive
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
        return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};


class Solution89 {
public:
    // 2011.7.27, from https://walkccc.me/LeetCode/problems/0206/
    // Time: sO(n)
    // Space: O(1)
    // Approach 2: Iterative
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
        }

        return prev;
    }
};


class Solution88 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/206
    /*
        之前做到 Reverse Linked List II 的时候我还纳闷怎么只有二没有一呢，原来真是忘了啊，现在才加上，
        这道题跟之前那道比起来简单不少，题目为了增加些许难度，让我们分别用迭代和递归来实现，但难度还是不大。
        我们先来看迭代的解法，思路是在原链表之前建立一个空的newHead，因为首节点会变，然后从head开始，将
        之后的一个节点移到newHead之后，重复此操作直到head成为末节点为止，代码如下：

        解法一：
    */
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        while (head) {
            ListNode *t = head->next;
            head->next = newHead;
            newHead = head;
            head = t;
        }
        return newHead;
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/206
    /*
        下面我们来看递归解法，代码量更少，递归解法的思路是，不断的进入递归函数，直到head指向倒数第二个节点，
        因为head指向空或者是最后一个结点都直接返回了，newHead则指向对head的下一个结点调用递归函数返回的
        头结点，此时newHead指向最后一个结点，然后head的下一个结点的next指向head本身，这个相当于把head
        结点移动到末尾的操作，因为是回溯的操作，所以head的下一个结点总是在上一轮被移动到末尾了，但head之后
        的next还没有断开，所以可以顺势将head移动到末尾，再把next断开，最后返回newHead即可，代码如下：

        解法二：
    */
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

