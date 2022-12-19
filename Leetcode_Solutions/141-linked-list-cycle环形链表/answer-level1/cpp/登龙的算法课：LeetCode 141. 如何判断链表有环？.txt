### 一、题目描述
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）， 如果 pos 是 -1，则在该链表中没有环。

示例 1 ：

- 输入：head = [3,2,0,-4], pos = 1
- 输出：true

解释：链表中有一个环，其尾部连接到第二个节点。

### 二、解题思路

2 种方法，其中一定要掌握快慢指针法！

#### 2.1 快慢指针法
- 设置两个指针，一个走的快（2 步），一个走的慢（1 步）
- 当两个指针没相遇时保持循环
- 如果链表存在环，则快指针一定会在某个时刻与慢指针相遇
- 如果链表无环，则快指针会首先达到链表尾部
- 如果循环结束则快慢指针相遇，则存在环

详细过程见代码注释：

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
      // 0. 空链表和只有一个节点的链表没有环
      if (head == nullptr || head->next == nullptr)
        return false;
      
      // 1. 快慢指针法
      auto faster = head->next;
      auto slower = head;

      // 2. 如果存在环则快慢指针最终会相遇
      while (slower != faster) {
        // 3. 快指针先到达链表尾部则不存在环
        if (faster == nullptr || faster->next == nullptr)
          return false;

        // 4. 快指针每次走两步
        faster = faster->next->next;

        // 5. 慢指针每次走一步
        slower = slower->next;
      }

      return true;
    }
};
```

##### 复杂度分析
- 时间复杂度：O(n)，不存在环遍历 n 个节点，存在环遍历 n + k 个节点
- 空间复杂度：O(1)，不使用额外内存空间

#### 2.2 哈希表法
思路很简单：
- 建立哈希表存储已经访问过的节点
- 检查当前遍历的节点是否在哈希表中
- 如果在则说明之前访问过，链表存在环
- 如果一直遍历到链表尾端，循环结束，则不存在环

详细过程见代码注释：

```cpp
class Solution {
public:
  bool hasCycle(ListNode *head) {
    // 1. 用哈希表存储已经访问过的节点
    unordered_set<ListNode*> s;
    ListNode *cur = head;

    while (cur != nullptr) {
      // 2. 当前节点之前已经被访问过说明链表有环
      if (s.find(cur) != s.end())
        return true;
      else // 3. 当前节点第一次被访问后添加到哈希表中
        s.insert(cur);
      
      cur = cur->next;
    }

    // 4. 链表遍历结束没有找到环
    return false;
  }
};
```

##### 复杂度分析
- 时间复杂度：O(n)，遍历 n 个节点
- 空间复杂度：O(n)，使用了最多存储 n 个节点的哈希表


### 三、最后
感谢你的阅读，如果文章对你有帮助，可以扫描下方二维码或者微信搜索「登龙」，关注公众号「登龙」查看更多人工智能、编程算法等技术干货！也可以访问我的个人博客：[登龙的技术博客](https://dlonng.com/) 感谢支持！

![](https://pic.leetcode-cn.com/38d3abae6e2b38daa6f52898299c049049d82787f9b1c46345b48fc6f711889e.png)
