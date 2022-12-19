```
核心：是一道双指针与数字题目。
 1. 整个链表分为**非环部分**(a)和**环部分**(b)
 2. 快指针 f 与慢指针 s 的速度关系是 f = 2s
 3. 如果有环，快慢指针第一次相遇的时候，f = s + nb（非环部分+环部分的n次绕圈）
    > 为什么一定是 n 倍？首先 s 走过的 f 一定也走过，也就是 f = s + x，要重合就是要绕一个圈，故 x=nb
 4. 由 2、3 推导出 s = nb, f= 2nb
 5. 由于要走到链表入口的结点，就需要 a + nb，设为 k 步。目前已知 s = nb，就要设法让 s 走上 a 步，就能到达 k = a + nb 的入口节点位置了。
 6. 只需要再次使用双指针，设定 f = head，然后 f++,s++（s在环内绕圈到下一次环入口），只要相遇了，就求得 a 
    > 为什么相遇了能求得 a？通过数学推导可以得出（官方题解）

关键点：
 1. 走 a+nb 步一定是在环入口
 2. 第一次相遇时慢指针已经走了 nb 步

参考：
 1. https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode/
 2. https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
```

```go
func detectCycle(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return nil
	}

	fast, slow := head, head // 设定快慢指针
	for {
		if fast == nil || fast.Next == nil {
			return nil
		}
		fast = fast.Next.Next // 快指针 f 步进速度 2
		slow = slow.Next      // 慢指针 s 步进速度 1, f = 2s
		if fast == slow {     // 快慢指针的第一次相遇, f = a + nb
			break // 推导出 s = nb, f = 2nb
		}
	}

	fast = head        // 设定头指针为开始的头部，进行第二次相遇
	for fast != slow { // 因为 f = a + nb, s = nb, 那么设定 f = 0, 那么 f & s 依次递增就能求出 a
		slow = slow.Next
		fast = fast.Next
	}
	return fast
}
```
