模仿C++写的golang版本，果然是快的一批

C++版本 https://leetcode-cn.com/problems/add-two-numbers/solution/li-jie-zui-jian-dan-de-ban-ben-by-feng_shuai/
![1.PNG](https://pic.leetcode-cn.com/57b0fb77a564d4fe19bdca3258ed989df66917d52dfe6a043ed45fd4b398934a-1.PNG)
```golang
通过设立两个指针 同时进行遍历，从左到右依次进行，低位加到高位，如果有进位的话和指针指向的值进行相加，一开始是3个值
加数，被加数，进位。
一旦某一个链表遍历到尾部，之后就没有这个加数了。但是不排除另一个加数还在，那么就只能虚拟一个假的链节点，其值为0，再与另外两个数相加。

终止条件是，连个链表遍历完成且没有进位存在。进位是每一次计算产生的，在每一次计算时设置。

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	res:=&ListNode{}
	cur:=&ListNode{}
	res.Next=cur
	tmp_value:=&ListNode{Val:0}
	carry:=0
	for{
		value:=l1.Val+l2.Val+carry
		cur.Next=&ListNode{Val:value%10}
		cur=cur.Next
		carry=value/10
		l1=l1.Next
		l2=l2.Next
		//精髓所在
		if l1==nil && l2==nil &&carry==0 {
			break
		}
		if l1==nil{
			l1=tmp_value
		}
		if l2==nil{
			l2=tmp_value
		}
	}
	return res.Next.Next
}
```