#### 复杂度

计算复杂度 $O(n)$，空间复杂度 $O(1)$。

关于计算复杂度的计算，后文会作额外说明。

成环求解题目的灵感来自于 [裴坚](https://www.zhihu.com/question/27741181) 老师的教诲 (可能玩梗有点过分了哈 =w=)。成环最高！

一般的做法相信大家都看过官方题解或者 [王小二](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/tu-jie-xiang-jiao-lian-biao-by-user7208t/)。双指针确实是很漂亮的做法。成环的做法是我在自己解题的时候想到的做法。

#### 灵感说明

下面是一个简单的负碳离子的羰基加成成环反应示意图：

![e0160-chem.png](https://pic.leetcode-cn.com/fc5acc42304c9fa1a74e2f6042b4a2c04d14bf01b51580f61c3bbde10bf0cae3-e0160-chem.png)

再回顾原始的题目，我们会发现
- 酯基部分 EtOOC- 很像 List A 的前段，
- 羰基 O=C- 很像 List B 的前段，
- 任意基团 ~R 很像 List A 与 List B 的重合部分 C。

当然像角鲨烯这种复杂的成环我是搞不定的，但是拿这样简单的加成成环的例子作类比还是很有意思的哈~

#### 思路说明

我们用类似于题目描述的图像来说明问题：

1. 我们先计算 List A 的长度为 `lA = 6`，List B 的长度为 `lB = 5`；
2. 随后，我们反转 List B，让列表成环；
3. 成环后，相交节点以后的列表就不在遍历范围之内了。求出环的长度为 `lL = 6`；并推断得到 `lC = 3`；
4. 还原列表，以满足题目要求；
5. 从 List B 的头节点 `headB` 出发走 `lB - lC = 2` 步，得到相交的节点位置。

<![幻灯片1.PNG](https://pic.leetcode-cn.com/75821177b9abfa05a7ddb43584194861ac1461e2c5fd159fedded73fc7ab3e16-%E5%B9%BB%E7%81%AF%E7%89%871.PNG),![幻灯片2.PNG](https://pic.leetcode-cn.com/507e843bf84dd1164e8a98bd73e9c96b7fb2de5a22a27520b611954646988257-%E5%B9%BB%E7%81%AF%E7%89%872.PNG),![幻灯片3.PNG](https://pic.leetcode-cn.com/a7cd921854d96f844e0da94040b94308e151da36d28e76385bfc712a354eb0cf-%E5%B9%BB%E7%81%AF%E7%89%873.PNG),![幻灯片4.PNG](https://pic.leetcode-cn.com/4c32e426b4525dbd3ad09ddabf9ba4cf00a22277ce7ebb604c65612bdef7fc5c-%E5%B9%BB%E7%81%AF%E7%89%874.PNG),![幻灯片5.PNG](https://pic.leetcode-cn.com/96e73f9ad46204a99efaedfd94a07ce4cbe1f33196706dd535db5d521aafe2a1-%E5%B9%BB%E7%81%AF%E7%89%875.PNG),![幻灯片6.PNG](https://pic.leetcode-cn.com/ecc1f2293d8b31d5b376cc15307653a81a39deee19ce3cd4341811789fdb24d6-%E5%B9%BB%E7%81%AF%E7%89%876.PNG),![幻灯片7.PNG](https://pic.leetcode-cn.com/7d1459cba59f71c0c5d7911c1627244759078a2c6bd532073560c4762c209b98-%E5%B9%BB%E7%81%AF%E7%89%877.PNG),![幻灯片8.PNG](https://pic.leetcode-cn.com/c225b35c0467815d490d336253a4f1c8bfe4145f1df1f1d18a8b36b33a3bf232-%E5%B9%BB%E7%81%AF%E7%89%878.PNG)>

#### 复杂度分析

我们令 $A$ 为 List A 的长度，$B$ 为 List B 的长度，$C$ 为重合链表长度。

1. 遍历 List A 与 List B 的操作次数为 $A + B$；
2. 反转 List B 的操作次数为 $B$；
3. 求出环长度的操作次数约为 $A + B - C$；
4. 再次反转 List B 的操作次数为 $B$；
5. 找到相交节点的操作次数为 $B - C$。

因此，总的操作次数为 $(2A + 5B - 2C)$。大致地说，计算复杂度与链表长度呈线性相关，即 $O(n)$。整个过程没有额外开指针向量或映射表，因此内存复杂度为 $O(1)$。

利用双指针的总操作次数为 $(2A + 2B - 2C)$，因此双指针的做法实际上也比较省计算量。当然我实际在跑程序的时候，两种算法的耗时都在 40ms - 60ms 左右。

#### 代码

尽管思路我想并不比双指针复杂，但代码的实现会比较冗长。
- 首先，我们需要构造一个反转链表的函数 `reverseList`；
- 需要排除一些简单的与极端的情况
- 由于对链表 List B 的操作更多，因此如果 List B 的长度更长，就将其与 List A 互换。

具体的代码细节可以参考注释。

```c++
class Solution {
    // 反转从 `head` 到 `tail` 的链表，其中参数 `last = tail->next`
    void reverseList(ListNode* head, ListNode* last = nullptr) {
        if (head->next == last) return;
        ListNode* pp = head, * p = head->next, * pn;
        while (p != last) {
            pn = p->next;
            p->next = pp;
            pp = p;
            p = pn;
        }
        head->next = nullptr;
    }

public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // 0. 排除极端情况：链表为空，或者相交节点就是头节点
        if (!headA || !headB) return nullptr;
        if (headA == headB) return headA;
        // 1. 得到链表 A 长度 `lA` 与链表 B 长度 `lB`
        // 在这个过程中，如果发现链表 A 中的节点与 B 头节点 `headB` 相同，则返回 B 头节点
        // 链表 B 与 A 的头节点亦然
        // 如果链表尾节点不相同，则不可能有相交节点
        ListNode* lastA = headA, * lastB = headB;
        int lA = 1, lB = 1;
        while (lastA->next) {
            lastA = lastA->next; ++lA;
            if (lastA == headB) return headB;
        }
        while (lastB->next) {
            lastB = lastB->next; ++lB;
            if (lastB == headA) return headA;
        }
        if (lastA != lastB) return nullptr;
        // 2. 如果链表 A 长度小于 B，则交换链表 A 与 B 以提高效率
        bool reversed = lA < lB;
        if (reversed) swap(headA, headB);
        // 3. 反转 B 列表，将相交节点之后链表长度记为 `lC`
        reverseList(headB);
        headB->next = headA;
        int lL = 1; ListNode* node = headB;
        while (node->next != headB) {
            node = node->next;
            lL += 1;
        }
        int lC = (lA + lB - lL + 1) / 2;
        // 4. 还原 B 列表，并还原被交换的 A 与 B 链表
        reverseList(lastB, headA);
        if (reversed) swap(headA, headB);
        // 5. 通过 `lC` 与 `lB` 返回相交的节点。
        ListNode* result = headB;
        for (int i = 0; i < lB - lC; ++i)
            result = result->next;
        return result;
    }
};
```