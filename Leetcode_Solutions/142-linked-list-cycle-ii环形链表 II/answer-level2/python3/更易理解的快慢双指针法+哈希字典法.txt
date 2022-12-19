链表嘛，有环就是能一直next下去，就一定有重复项，最自然的想法就是哈希表了：
```
class Solution(object):
    def detectCycle(self, head):

        visited = set()
        while head:
            if head not in visited:
                visited.add(head)
                head = head.next            
            else:
                return head
        return None
```
空间复杂度O(n),想搞成O(1)，那还得双指针。头尾双指针是不可能了，那就快慢双指针试试。

题解里有很多快慢双指针的方法，我最推荐这个[另类的快慢指针，未用Floyd 算法](https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/ling-lei-de-kuai-man-zhi-zhen-wei-yong-floyd-suan-/)，最好理解。下面来简洁说明下原理：

![image.png](https://pic.leetcode-cn.com/e952968dca831a683402a500b10bdebbb8d7f443aa33d4cd554763035aec6c79-image.png)

核心思路是，快指针（2倍速）和慢指针（1倍速）同时从起点出发，第一次相遇 和 第二次相遇 距离差一定是一圈，由此可以求出环的长度Y。

然后快指针重新由**起点+Y距离**开始走，并且速度为**1倍速**，
同时慢指针重新由**起点**开始走，并且速度为**1倍速**，
这样快慢指针相遇时，快慢指针同时走过的距离就是**X**。

![image.png](https://pic.leetcode-cn.com/146eceb90931dd7e36a2b1434f1f35924e7bcee8a9ef73fb5fdfdecd31454ec0-image.png)

剩下就是代码实现了：
```
class Solution(object):
    def detectCycle(self, head):
        ## 先求环长Y
        fast = slow = head
        count, step = [], 0
        while fast and fast.next:
            step += 1
            slow = slow.next
            fast = fast.next.next
            if slow==fast:
                count.append(step)
            if len(count)==2: ## 第二次相遇
                step = count[-1]-count[-2] ## 两次相遇距离相减即环长
                break    
        
        ## 再求X
        fast = slow = head
        for _ in range(step):fast = fast.next ## fast指针从环长处开始走
        while fast and fast.next:
            if slow==fast:return fast ## 相遇点即结果
            slow = slow.next
            fast = fast.next
```
以上两种方法通过结果都是：
执行用时 :40 ms, 在所有 Python 提交中击败了94.38%的用户
内存消耗 :18.1 MB, 在所有 Python 提交中击败了27.09%的用户