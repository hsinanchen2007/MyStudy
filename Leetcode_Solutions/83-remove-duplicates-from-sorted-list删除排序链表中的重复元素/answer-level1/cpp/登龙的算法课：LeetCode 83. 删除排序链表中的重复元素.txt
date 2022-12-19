### 一、题目描述
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1：
- 输入: 1->1->2
- 输出: 1->2

示例 2：
- 输入: 1->1->2->3->3
- 输出: 1->2->3


### 二、解题思路
本题考查的是对链表的基础指针操作，只要在遍历链表的同时找到要删除的节点指针，然后删除即可，步骤如下：
- 对链表的头结点副本 current 进行遍历
- 循环遍历直到到最后一个节点
- 每次遍历判断当前节点值是否等于下一节点值
- 如果相等则删除下一节点
- 如果不等则继续遍历下一节点
- 最终返回链表头结点

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 0. 空链表返回 nullptr
        if (head == nullptr)
            return nullptr;

        // 1. 不对头指针操作，头指针用于返回结果
        ListNode *cur = head;
        ListNode *del_node = nullptr;

        while (current->next != nullptr) {
            // 2. 找到元素相同的节点
            if (cur->val == cur->next->val) {
                // 3. 保存待删除的节点
                del_node = cur->next;
                
                // 4. 断开 del_node 节点
                cur->next = del_node->next;
                
                // 5. 删除节点
                delete del_node;

                // 6. 编程规范：防止出现野指针
                del_node = nullptr;
            } else {
                // 7. 没找到相同元素就继续向后遍历
                cur = cur->next;
            }
        } 

        return head;
    }
};
```

#### 复杂度分析
- 时间复杂度：O(n)，只需要一次遍历 n 个链表节点
- 空间复杂度：O(1)，只使用常数的内存指针单位


### 三、最后
感谢你的阅读，如果文章对你有帮助，可以扫描下方二维码或者微信搜索「登龙」，关注公众号「登龙」查看更多人工智能、编程算法等技术干货！也可以访问我的个人博客：[登龙的技术博客](https://dlonng.com/) 感谢支持！

![](https://pic.leetcode-cn.com/38d3abae6e2b38daa6f52898299c049049d82787f9b1c46345b48fc6f711889e.png)