### 解题思路
问题难点在与开头的节点是要删除的怎么判，因此先找到第一个不为val的节点。
同时记录pre和cur。
我的写法比较繁琐，官方题解的”哨兵“方法更为简便。

### 代码

```golang
func removeElements(head *ListNode, val int) *ListNode {
	if head==nil{
		return head
	}
	if head.Next==nil{
		if head.Val==val{
			return nil
		}else {
			return head
		}
	}
	firstValidNode:=head
	tmpNode:=head
	for tmpNode!=nil{
		if tmpNode.Val!=val{
			firstValidNode=tmpNode
			break
		}
		tmpNode=tmpNode.Next
	}
	if tmpNode==nil{
		return nil
	}
	preNode:=firstValidNode
	curNode:=firstValidNode.Next
	for curNode!=nil  {
		if curNode.Val!=val{
			preNode=curNode
			curNode=curNode.Next
			continue
		}
		preNode.Next=curNode.Next
		curNode=curNode.Next
	}
	return firstValidNode
}

```