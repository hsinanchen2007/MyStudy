/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

/*

https://leetcode.cn/problems/linked-list-cycle-ii/

142. 环形链表 II
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 
pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，
仅仅是为了标识链表的实际情况。

不允许修改 链表。


示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：

输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
 

提示：

链表中节点的数目范围在范围 [0, 104] 内
-105 <= Node.val <= 105
pos 的值为 -1 或者链表中的一个有效索引
 

进阶：你是否可以使用 O(1) 空间解决此题？

通过次数511,080提交次数906,761

*/

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution100 {
public:
    // 2022.8.8, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.md
    ListNode *detectCycle(ListNode *head) {
        /*
            思路
            为了易于大家理解，我录制讲解视频：B站：把环形链表讲清楚！ 。结合视频在看本篇题解，事半功倍。
            这道题目，不仅考察对链表的操作，而且还需要一些数学运算。

            主要考察两知识点：

            判断链表是否环
            如果有环，如何找到这个环的入口
            判断链表是否有环
            可以使用快慢指针法，分别定义 fast 和 slow 指针，从头结点出发，fast指针每次移动两个节点，slow指针每次移动一个节点，
            如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。

            为什么fast 走两个节点，slow走一个节点，有环的话，一定会在环内相遇呢，而不是永远的错开呢

            首先第一点：fast指针一定先进入环中，如果fast指针和slow指针相遇的话，一定是在环中相遇，这是毋庸置疑的。

            那么来看一下，为什么fast指针和slow指针一定会相遇呢？

            可以画一个环，然后让 fast指针在任意一个节点开始追赶slow指针。

            会发现最终都是这种情况， 如下图：

            142环形链表1

            fast和slow各自再走一步， fast和slow就相遇了

            这是因为fast是走两步，slow是走一步，其实相对于slow来说，fast是一个节点一个节点的靠近slow的，所以fast一定可以和slow重合。

            动画如下：

            141.环形链表

            如果有环，如何找到这个环的入口
            此时已经可以判断链表是否有环了，那么接下来要找这个环的入口了。

            假设从头结点到环形入口节点 的节点数为x。 环形入口节点到 fast指针与slow指针相遇节点 节点数为y。 从相遇节点 再到环形入口
            节点节点数为 z。 如图所示：

            142环形链表2

            那么相遇时： slow指针走过的节点数为: x + y， fast指针走过的节点数： x + y + n (y + z)，n为fast指针在环内走了n圈才
            遇到slow指针， （y+z）为 一圈内节点的个数A。

            因为fast指针是一步走两个节点，slow指针一步走一个节点， 所以 fast指针走过的节点数 = slow指针走过的节点数 * 2：

            (x + y) * 2 = x + y + n (y + z)

            两边消掉一个（x+y）: x + y = n (y + z)

            因为要找环形的入口，那么要求的是x，因为x表示 头结点到 环形入口节点的的距离。

            所以要求x ，将x单独放在左面：x = n (y + z) - y ,

            再从n(y+z)中提出一个 （y+z）来，整理公式之后为如下公式：x = (n - 1) (y + z) + z 注意这里n一定是大于等于1的，因为 
            fast指针至少要多走一圈才能相遇slow指针。

            这个公式说明什么呢？

            先拿n为1的情况来举例，意味着fast指针在环形里转了一圈之后，就遇到了 slow指针了。

            当 n为1的时候，公式就化解为 x = z，

            这就意味着，从头结点出发一个指针，从相遇节点 也出发一个指针，这两个指针每次只走一个节点， 那么当这两个指针相遇的时候就是 
            环形入口的节点。

            也就是在相遇节点处，定义一个指针index1，在头结点处定一个指针index2。

            让index1和index2同时移动，每次移动一个节点， 那么他们相遇的地方就是 环形入口的节点。

            动画如下：

            142.环形链表II（求入口）

            那么 n如果大于1是什么情况呢，就是fast指针在环形转n圈之后才遇到 slow指针。

            其实这种情况和n为1的时候 效果是一样的，一样可以通过这个方法找到 环形的入口节点，只不过，index1 指针在环里 多转了(n-1)圈，
            然后再遇到index2，相遇点依然是环形的入口节点。

            补充
            在推理过程中，大家可能有一个疑问就是：为什么第一次在环中相遇，slow的 步数 是 x+y 而不是 x + 若干环的长度 + y 呢？

            即文章链表：环找到了，那入口呢？中如下的地方：

            142环形链表5

            首先slow进环的时候，fast一定是先进环来了。

            如果slow进环入口，fast也在环入口，那么把这个环展开成直线，就是如下图的样子：

            142环形链表3

            可以看出如果slow 和 fast同时在环入口开始走，一定会在环入口3相遇，slow走了一圈，fast走了两圈。

            重点来了，slow进环的时候，fast一定是在环的任意一个位置，如图：

            142环形链表4

            那么fast指针走到环入口3的时候，已经走了k + n 个节点，slow相应的应该走了(k + n) / 2 个节点。

            因为k是小于n的（图中可以看出），所以(k + n) / 2 一定小于n。

            也就是说slow一定没有走到环入口3，而fast已经到环入口3了。

            这说明什么呢？

            在slow开始走的那一环已经和fast相遇了。

            那有同学又说了，为什么fast不能跳过去呢？ 在刚刚已经说过一次了，fast相对于slow是一次移动一个节点，所以不可能跳过去。

            好了，这次把为什么第一次在环中相遇，slow的 步数 是 x+y 而不是 x + 若干环的长度 + y ，用数学推理了一下，算是对链表：环找到了，
            那入口呢？的补充。

            总结
            这次可以说把环形链表这道题目的各个细节，完完整整的证明了一遍，说这是全网最详细讲解不为过吧，哈哈。
        */

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return NULL;
    }
};


class Solution99 {
public:
    // 2022.8.9, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/142.%20Linked%20List%20Cycle%20II
    // OJ: https://leetcode.com/problems/linked-list-cycle-ii/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        auto p = head, q = head;
        while (p && p->next) {
            p = p->next->next;
            q = q->next;
            if (p == q) break;
        }
        if (!p || !p->next) return nullptr; // The list is finite
        p = head;
        for (; p != q; p = p->next, q = q->next);
        return p;
    }
};


class Solution98 {
public:
    // 2022.8.9, from https://github.com/grandyang/leetcode/issues/142
    /*
        这个求单链表中的环的起始点是之前那个判断单链表中是否有环的延伸，可参之前那道 Linked List Cycle。这里还是要设快慢指针，
        不过这次要记录两个指针相遇的位置，当两个指针相遇了后，让其中一个指针从链表头开始，一步两步，一步一步似爪牙，似魔鬼的步伐
        。。。哈哈，打住打住。。。此时再相遇的位置就是链表中环的起始位置，为啥是这样呢，这里直接贴上热心网友「飞鸟想飞」的解释哈，
        因为快指针每次走2，慢指针每次走1，快指针走的距离是慢指针的两倍。而快指针又比慢指针多走了一圈。所以 head 到环的起点+环的
        起点到他们相遇的点的距离 与 环一圈的距离相等。现在重新开始，head 运行到环起点 和 相遇点到环起点 的距离也是相等的，相当于
        他们同时减掉了 环的起点到他们相遇的点的距离。代码如下：
    */
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return NULL;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};


class Solution97 {
public:
    // 2022.8.9, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/linked-list-cycle-ii.cpp
    // Time:  O(n)
    // Space: O(1)
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next, fast = fast->next->next;
            if (slow == fast) {  // There is a cycle.
                slow = head;
                // Both pointers advance at the same time.
                while (slow != fast) {
                    slow = slow->next, fast = fast->next;
                }
                return slow;  // slow is the begin of cycle.
            }
        }
        return nullptr;  // No cycle.
    }
};


class Solution96 {
public:
    // 2022.8.9, from https://walkccc.me/LeetCode/problems/0142/
    // Time: O(n)
    // Space: O(1)
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
            }
            return slow;
        }
        }

        return nullptr;
    }
};


class Solution95 {
public:
    // 2022.8.9, from https://github.com/wisdompeak/LeetCode/blob/master/Linked_List/142.Linked-List-Cycle-II/142.Linked-List-Cycle-II.cpp
    /*
        从第141题已知，用快慢指针的方法可以判断是否链表存在环。

        假设两个指针相遇时，快指针走过了m步进入环的入口然后转了k1圈（每圈n步）又多p步；同理，慢指针走过了m步进入环的入口然后
        转了k2圈又多p步。由于两者是两倍关系，所以 m+k1*n+p = 2*(m+k2*n+p)。

        化简之后得到 m = (k1-2k2)*n-p，变换一下 p+m = (k1-2k2)*n

        因为慢指针目前已经比整数圈多走了p步，结合这个数学式子，这说明如果慢指针再走m步的话，又会凑成整数圈，即到了环的入口。
        怎么确定m呢？只要另开一个指针从head开始与慢指针一齐走，它们相遇的地方就是环的入口。

        本题的算法还有一个非常巧妙的应用：287. Find the Duplicate Number
    */
    ListNode *detectCycle(ListNode *head) 
    {
        if (head==NULL) return NULL;
        
        ListNode* slow=head;
        ListNode* fast=head;
        int flag=0;
        
        while (fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if (fast==slow) 
            {
                flag=1;
                break;
            }
        }
        
        if (flag==0) return NULL;
        
        fast=head;
        while (fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        
        return fast;
        
    }
};


class Solution94 {
public:
    // 2022.8.9, from https://www.guozet.me/leetcode/Leetcode-142-Linked-List-Cycle-II.html?h=cycle
    /*
        这道题目，感觉更多的是考虑数学公式的推导的样子，如果是一个环，可以得到下面这个图形：
        图片来自于博客: [算法][LeetCode]Linked List Cycle & Linked List Cycle II——单链表中的环

        先对图中符号做下面的定义：

        X是链表头
        Y是环的第一个节点，也就是环的起点
        'Z'是快慢节点的相遇位置
        环的长度是r = c + b
        slow指针走过的距离是 s = a + b
        fast指针走过的距离是 2s = a + n(c+b) + b
        相遇的时候fast指针在环里面已经走了n圈了
        根据上面的图形，得到下面的推导：

        2s = a + n(c+b) + b
        2(a+b) = a + n(c+b) + b
        a+b = n(c+b)
        a = n(c+b) - b = （n-1)×（c+b） + c = (n-1)*r + c
        所以如果在相遇的时候，重新定义一个slow2的慢指针，每次走一步，那么他们一定可以在环的起点位置相遇的。
    */
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *slow2 = head;
                while (slow2 != slow) {
                    slow2 = slow2->next;
                    slow = slow->next;
                }
                return slow2;
            }
        }
        return nullptr;
    }
};


class Solution {
public:
    // 2022.8.10, from https://www.acwing.com/solution/content/241/
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/241/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        题目描述
        给定一个链表，如果存在环，则返回环的入口；否则返回null。

        注意：请不要修改链表。

        进一步：能否只是用额外 O(1)O(1) 的空间？

        算法
        (链表，快慢指针扫描) O(n)O(n)
        本题的做法比较巧妙。
        用两个指针 first,secondfirst,second 分别从起点开始走，firstfirst 每次走一步，secondsecond 每次走两步。
        如果过程中 secondsecond 走到null，则说明不存在环。否则当 firstfirst 和 secondsecond 相遇后，让 firstfirst 
        返回起点，secondsecond 待在原地不动，然后两个指针每次分别走一步，当相遇时，相遇点就是环的入口。

        证明：如上图所示，aa 是起点，bb 是环的入口，cc 是两个指针的第一次相遇点，abab 之间的距离是 xx，bcbc 之间的距离是 yy。
        则当 firstfirst 走到 bb 时，由于 secondsecond 比 firstfirst 多走一倍的路，所以 secondsecond 已经从 bb 
        开始在环上走了 xx 步，可能多余1圈，距离 bb 还差 yy 步（这是因为第一次相遇点在 bb 之后 yy 步，我们让 firstfirst 
        退回 bb 点，则 secondsecond 会退 2y2y 步，也就是距离 bb 点还差 yy 步）；所以 secondsecond 从 bb 点走 x+yx+y 
        步即可回到 bb 点，所以 secondsecond 从 cc 点开始走，走 xx 步即可恰好走到 bb 点，同时让 firstfirst 从头开始走，
        走 xx 步也恰好可以走到 bb 点。所以第二次相遇点就是 bb 点。

        另外感谢@watay147提供的另一种思路，可以用公式来说明：a,b,c,x,ya,b,c,x,y 的含义同上，我们用 zz 表示从 cc 点顺时针
        走到 bb 的距离。则第一次相遇时 secondsecond 所走的距离是 x+(y+z)∗n+yx+(y+z)∗n+y, nn 表示圈数，同时 secondsecond 
        走过的距离是 firstfirst 的两倍，也就是 2(x+y)2(x+y)，所以我们有 x+(y+z)∗n+y=2(x+y)x+(y+z)∗n+y=2(x+y)，
        所以 x=(n−1)×(y+z)+zx=(n−1)×(y+z)+z。那么我们让 secondsecond 从 cc 点开始走，走 xx 步，会恰好走到 bb 点；
        让 firstfirst 从 aa 点开始走，走 xx 步，也会走到 bb 点。

        时间复杂度分析：firstfirst 总共走了 2x+y2x+y 步，secondsecond 总共走了 2x+2y+x2x+2y+x 步，所以两个指针总共走了 
        5x+3y5x+3y 步。由于当第一次 firstfirst 走到 bb 点时，secondsecond 最多追一圈即可追上 firstfirst，所以 yy 
        小于环的长度，所以 x+yx+y 小于等于链表总长度。所以总时间复杂度是  O(n)O(n) 。
    */
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return 0;
        ListNode *first = head, *second = head;

        while (first && second)
        {
            first = first->next;
            second = second->next;
            if (second) second = second->next;
            else return 0;

            if (first == second)
            {
                first = head;
                while (first != second)
                {
                    first = first->next;
                    second = second->next;
                }
                return first;
            }
        }

        return 0;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

