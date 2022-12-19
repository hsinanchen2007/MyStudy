### 解题思路
观察链表可以看得出来，我们只需要同时遍历两个链表，然后累加成为一个新的链表，结果就出来了
但是建个新的链表也吃吃内存的，所以思路是直接以L1的基础链表上做累计，最后我们返回L1就好了，这样可以节省空间
下面是关于算法的思路图解，有区分两种情况
![addTwoNumbers.png](https://pic.leetcode-cn.com/f4b257c735ae1301f18d89229cf546fc94488d36f9fe460a72c5a62b448c9364-addTwoNumbers.png)

代码中有一些特殊的临界点处理，可看注释
### 代码

```golang
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var cur, lv2, nex int
	var l3 *ListNode
	l3 = l1
	//由于我们是拿l1来作为返回，这里我们这需要判断l1是否还有下一个就可以 了
	for l1 != nil {
		//l2不为空的话我们先保存val和遍历下一位
		if l2 != nil {
			lv2 = l2.Val
			l2 = l2.Next
		} else {
			//l2为nil的话我们直接赋为0，累加0
			lv2 = 0
		}
		//计算当前节点的值
		cur = l1.Val + lv2 + nex
		l1.Val = cur % 10
		//用于下一次累计是否有进位（>10）
		nex = cur / 10

		//只需要判断l1是否遍历完，遍历完了拿剩余的l2部分直接拼接到l1的尾部
		if l1.Next == nil {
			l1.Next = l2
			//如果l2也遍历完了，说明结束了，break
			if l2 == nil {
				//结束了最后一为还需要进位的话我们得加上再break
				if nex > 0 {
					l1.Next = &ListNode{
						Val: nex,
					}
				}
				break
			} else {
				//我们把l2拼到l1上了，这个时候l2已经没有用了，我们把它置空，继续遍历l1
				l2 = nil
				l1 = l1.Next
			}
		} else {
			//如果l2为nil且没有进位的话，我们直接返回原l1剩下的值
			if l2 == nil && nex == 0 {
				break
			}
			l1 = l1.Next
		}
	}
	return l3
}

```