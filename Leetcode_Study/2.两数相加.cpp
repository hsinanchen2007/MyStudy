/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

/*

https://leetcode.cn/problems/add-two-numbers/

2. 两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。


示例 1：


输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.

示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]

示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
 

提示：

每个链表中的节点数在范围 [1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零
通过次数1,364,296提交次数3,262,480

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
    // 2022.5.31 from LG solution, use two pointers
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // define pointers to iterate and trace current pointer
        ListNode* p = l1;
        ListNode* q = l2;

        // define head node with value -1
        ListNode* result = new ListNode(-1);

        // define current node, starts from head node
        ListNode* current = result;

        // to trace if the sum is equal or over 10
        int carry = 0;

        // need below or condition as we don't know size of p or q list
        // the given data structure didn't provide size() function
        while (p !=NULL || q != NULL) {
            // get values from nodes
            int x = (p != NULL)? p->val : 0;
            int y = (q != NULL)? q->val : 0;
            int sum = x + y + carry;

            // determine whether carry is equal or over 10
            // for carry, use "/ 10"
            // for example, (5 + 5) / 10 = 1, so carry will be 1
            // for example, (7 + 8) / 10 = 1, so carry will be 1
            // for example, (3 + 4) / 10 = 0, so carry will be 0 
            carry = sum / 10;

            // get the number we need to put into new node
            // for the sum of nodes, we only need to put last digital
            // so we use "% 10" to get its number
            // for example, (3 + 6) % 10 = 9, we put 9 into node value
            // for example, (5 + 7) % 10 = 2, we put 2 into node value
            // carry will be 1 and will be applied to next iteration
            int num = sum % 10;
            current->next = new ListNode(num);
            current = current->next;

            // next iteration
            p = (p == NULL) ? p : p->next;
            q = (q == NULL) ? q : q->next;
        }

        // add new node due to carry > 0, carry should be 1 in general
        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        // return the next node of head node. head node has invalid number -1
        // when we create it at the beginning
        return result->next;
    }
};


class Solution99 {
public:
    // 2022.6.4, from AcWing https://www.acwing.com/video/1318/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // a trick that use auto to declare two ListNodes here
        auto dummy = new ListNode(-1), cur = dummy;

        // t can be used as sum and determine whether it is equal or 
        // larger 10 or not
        int t = 0;

        // this while condition covers l1, l2 or if t is 1, aka needed to add 1 to next
        while (l1 || l2 || t) {
            if (l1) t = l1->val + t, l1 = l1->next;
            if (l2) t = l2->val + t, l2 = l2->next;
       
            // we only assign number between 0~9, and update cur
            cur->next = new ListNode(t % 10);
            cur = cur->next;

            // whether it is equal or over 10, this one will tell
            t = t / 10;
        }

        // current is at dummy->next, dummy is just a dummy head w/ value -1
        // we declare it at the beginning
        return dummy->next;
    }
};


class Solution98 {
public:
    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/add-two-numbers.cpp
    // Time:  O(n)
    // Space: O(1)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy{0};
        auto curr = &dummy;

        auto carry = 0;
        while (l1 || l2 || carry) {
            auto a = l1? l1->val : 0, b = l2? l2->val : 0;
            auto val = carry + a + b;
            curr->next = new ListNode(val % 10);
            carry = val / 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            curr = curr->next;
        }

        return dummy.next;
    }
};


class Solution97 {
public:
    // 2022.6.14, from https://ke.algomooc.com/detail/v_626e7fc2e4b01c509aaaf545/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_626e7eeee4b01c509aaaf51e
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 两数相加(2)：https://leetcode.cn/problems/add-two-numbers/     
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // 构建一个链表用来存放 l1 和 l2 两个链表相加的结果
        // 其中 dummy 这个节点为虚拟头结点
        ListNode *dummy = new ListNode(-1);

        // 设置一个进位，初始化为 0
        // 两个个位数相加，进位只能是 1 或者 0
        // 比如 7 + 8 = 15，进位是 1
        // 比如 2 + 3 = 6，没有进位，或者说进位是 0
        int carryBit = 0;

        // l1 和 l2 有可能为空，所以先默认结果链表从虚拟头结点位置开始
        ListNode *cur = dummy;

        // 同时遍历 l1 和 l2
        // 只要此时 l1 和 l2 两个链表中的任意链表中节点有值，就一直加下去
        // 直到两个链表中的所有节点都遍历完毕为止
        while (l1 != NULL || l2 != NULL) {
            // 获取 l1 链表中节点的值
            int x;

            // 观察此时 l1 中的节点是否有值
            // 如果节点不存在，那么就用 0 来占位
            if(  l1 == NULL) {
                // 用 0 来占位
                x = 0;
            } else {
                // 否则，将 l1 的节点值赋值给 x
                x = l1->val;
            }

            // 获取 l2 链表中节点的值
            int y;

            // 观察此时 l2 中的节点是否有值
            // 如果节点不存在，那么就用 0 来占位
            if ( l2 == NULL) {
                // 用 0 来占位
                y = 0;
            } else {
                // 否则，将 l2 的节点值赋值给 y
                y = l2->val;
            }
   
            // 每一位计算的同时需要考虑上一位的进位情况
            int sum = x + y + carryBit;
            
            // 获取当前计算结果的十位数
            // 比如 7 + 8 = 15
            // 那么 sum / 10 = 1，进位为 1
            carryBit = sum / 10;

            // 获取当前计算结果的个位数
            // 比如 7 + 8 = 15
            // 那么 sum % 10 = 5
            int digit = sum % 10;

            // 构建一个节点用来存放这个个位数
            ListNode *digitNode = new ListNode(digit);

            // 把这个节点加入到结果链表中
            cur->next = digitNode;

            // 移动 cur 的位置，观察后面应该存放什么节点
            cur = cur->next;
            
            // l1 链表中还有节点未遍历完毕就继续遍历下去
            if (l1 != NULL) l1 = l1->next;

            // l2 链表中还有节点未遍历完毕就继续遍历下去
            if (l2 != NULL) l2 = l2->next;
        }

        // 两个链表的尾节点相加之后，有可能产生进位的情况
        // 所以，需要构建一个新的节点用来存放这个进位的结果
        if (carryBit == 1) {
            // 构建一个节点用来存放这个进位
            ListNode *carryBitNode = new ListNode(carryBit);

            // 把这个节点加入到结果链表中
            cur->next = carryBitNode;
        }

        // 最后返回结果链表的头节点就行，即虚拟头结点的下一个节点
        return dummy->next;

    }
};


class Solution96 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/2.%20Add%20Two%20Numbers
    // OJ: https://leetcode.com/problems/add-two-numbers/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        int carry = 0;
        ListNode dummy, *tail = &dummy;
        while (a || b || carry) {
            if (a) {
                carry += a->val;
                a = a->next;
            }
            if (b) {
                carry += b->val;
                b = b->next;
            }
            tail->next = new ListNode(carry % 10);
            tail = tail->next;
            carry /= 10;
        }
        return dummy.next;
    }
};


class Solution95 {
public:
    // 2022.7.25, from https://walkccc.me/LeetCode/problems/0002/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(carry % 10);
            carry /= 10;
            curr = curr->next;
        }

        return dummy.next;
    }
};


class Solution {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/2
    /*
        这道并不是什么难题，算法很简单，链表的数据类型也不难，就是建立一个新链表，然后把输入的两个链表从头往后撸，每两个相加，
        添加一个新节点到新链表后面。为了避免两个输入链表同时为空，我们建立一个 dummy 结点，将两个结点相加生成的新结点按顺序
        加到 dummy 结点之后，由于 dummy 结点本身不能变，所以用一个指针 cur 来指向新链表的最后一个结点。好，可以开始让两个
        链表相加了，这道题好就好在最低位在链表的开头，所以可以在遍历链表的同时按从低到高的顺序直接相加。while 循环的条件两个
        链表中只要有一个不为空行，由于链表可能为空，所以在取当前结点值的时候，先判断一下，若为空则取0，否则取结点值。然后把两
        个结点值相加，同时还要加上进位 carry。然后更新 carry，直接 sum/10 即可，然后以 sum%10 为值建立一个新结点，连到 
        cur 后面，然后 cur 移动到下一个结点。之后再更新两个结点，若存在，则指向下一个位置。while 循环退出之后，最高位的进位
        问题要最后特殊处理一下，若 carry 为1，则再建一个值为1的结点，代码如下：

        C++ 解法： 
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        int carry = 0;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1);
        return dummy->next;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

