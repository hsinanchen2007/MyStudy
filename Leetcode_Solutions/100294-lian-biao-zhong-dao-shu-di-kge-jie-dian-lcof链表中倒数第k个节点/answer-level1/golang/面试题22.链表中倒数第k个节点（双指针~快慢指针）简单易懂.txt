### 解题思路
学习[@jyd](/u/jyd/)大佬 
[大佬详细分析](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/solution/mian-shi-ti-22-lian-biao-zhong-dao-shu-di-kge-j-11/)

### 知识点：双指针（快慢指针）

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKthFromEnd(head *ListNode, k int) *ListNode {
    	former, latter := head, head
	
	// former 先走k步
	for i := 0; i < k; i++ {
		former = former.Next
	}

	// latter 和 former 共同走 n - k 步，n代表链表长度，直到former走出链表
	for former != nil {
		former, latter = former.Next, latter.Next
	}

	return latter
}
```