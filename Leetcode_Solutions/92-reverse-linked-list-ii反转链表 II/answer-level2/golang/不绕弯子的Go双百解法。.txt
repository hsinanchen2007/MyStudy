### 解题思路
Go的双百解法，简单聊聊吧。
执行用时 :
0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :
2.1 MB, 在所有 Go 提交中击败了100.00%的用户

总体思路首先在头部增加一个哑巴指针，防止题目坑人，接下来声明3个指针，分别是
1.m左侧的node bleft
2.m所在的node left
3.n所在的node right

接下来就是循环替换，
bleft.next变成left.next,
right.next暂做临时变量，
right.next变成left，
left.next变成之前的临时变量，
left赋值bleft.next
周而复始，直到执行n-m次结束。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    dumb:=&ListNode{-1,nil}
	dumb.Next=head
    length:=1
	temp:=dumb
	for{
		if temp.Next!=nil{
			temp=temp.Next
			length++
		} else {
			break
		}
	}

	bleft:= &ListNode{-1,nil}
	left:=  &ListNode{-1,nil}
	right:= &ListNode{-1,nil}
	temp=dumb
	index:=0
	for{
		if index<length{
			if index==m-1 {
				bleft = temp
			}else if index==m{
				left=temp
			}else if index==n{
				right=temp
			}
			temp=temp.Next
			index++
		}else {
			break
		}
	}

	index=0
	for{
		if index==n-m{
			break
		} else{
			afterRight:=right.Next
			bleft.Next=left.Next
			left.Next=afterRight
			right.Next=left
			left=bleft.Next
			index++
		}
	}
    return dumb.Next
}
```