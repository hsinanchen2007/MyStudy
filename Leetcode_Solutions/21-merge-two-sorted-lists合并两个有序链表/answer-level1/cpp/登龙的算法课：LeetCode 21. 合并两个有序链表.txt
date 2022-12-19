### 一、题目描述
将两个升序链表合并为一个新的升序链表并返回，新链表是通过拼接给定的两个链表的所有节点组成的，比如：

- 输入：1->2->4, 1->3->4
- 输出：1->1->2->3->4->4


### 二、解题思路
### 2.1 迭代法
使用循环迭代的方法，依次找出较小的节点链接起来即可：
- 比较 l1 和 l2 当前节点值的大小
- 将较小的节点链接到 l3 尾部
- l1 或 l2 指针后移一位
- l3 指针后移一位
- 循环结束：l1 和 l2 其中一个遍历到尾部
- 将未遍历完的节点全部链接到 l3 尾部
- 返回保存的 l3 头指针 head->next

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 1. 升序链表 l3
        ListNode *l3 = new ListNode(0);

        // 2. 保存头指针用于返回结果
        ListNode *head = l3;

        while (l1 && l2) {
            // 3. 选择较小的节点连接到 l3 尾部
            if (l1->val <= l2->val) {
                l3->next = l1;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l2 = l2->next;
            }

            l3 = l3->next;
        }

        // 将多余的 l1 或者 l2 节点直接链接到 l3 尾部
        l3->next = (l1 == nullptr ? l2 : l1);

        return head->next;
    }
};
```
#### 复杂度分析
- 时间复杂度：O(m + n)，循环的次数等于 2 个链表的总长度 m + n
- 空间复杂度：O(1)，使用的变量内存为常数级别


### 2.2 递归法
递归法要注意递归表达式和循环结束条件：
- 当 l1 为空，返回 l2
- 当 l2 为空，返回 l1
- l1 和 l2 都不为空，比较节点 val
- 将较小的节点链接上，并递归调用函数来确定下一个链接的节点

递归法不是很好理解，建议用 vs 调试看下内存。

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 1. 递归结束条件
        if (l1 == nullptr)
            return l2;

        // 2. 递归结束条件
        if (l2 == nullptr)
            return l1;

        // 3. 递归表达式
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
```
#### 复杂度分析
- 时间复杂度：O(m + n)，每次递归都会添加一个链表节点，最终会递归 m + n 次
- 空间复杂度：递归的过程中，会将全部 m + n 个节点都保存一次在递归调用栈中


### 三、最后
感谢你的阅读，如果文章对你有帮助，可以扫描下方二维码或者微信搜索「登龙」，关注公众号「登龙」查看更多人工智能、编程算法等技术干货！也可以访问我的个人博客：[登龙的技术博客](https://dlonng.com/) 感谢支持！

![](https://pic.leetcode-cn.com/38d3abae6e2b38daa6f52898299c049049d82787f9b1c46345b48fc6f711889e.png)