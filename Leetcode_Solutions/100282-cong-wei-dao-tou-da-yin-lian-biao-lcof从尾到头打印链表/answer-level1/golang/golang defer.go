## golang defer

使用golang defer特性
代码如下

```
func reversePrint(head *ListNode) (a []int) {
	for head != nil {
		defer func(head *ListNode) {
			a = append(a, head.Val)
		}(head)
        head=head.Next
	}
	return

}
```

golang的defer本质上应该也是使用的栈

需要注意的是，要在函数声明中把返回值给定义了，不然无法做到defer修改返回值的效果