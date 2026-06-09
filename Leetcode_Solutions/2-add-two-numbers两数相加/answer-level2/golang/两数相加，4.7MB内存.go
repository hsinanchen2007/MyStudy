解题思路，不创建临时变量，结果保存在l1

```
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	for tmp := l1; ; tmp = tmp.Next {  	//tmp为当前工作位置
        if l2!=nil{ 					//当l2存在的时候，两数相加			
            tmp.Val += l2.Val
            l2 = l2.Next
        }
		if tmp.Val > 9 { 			//当结果大于9，就要进位
			tmp.Val -= 10
			if tmp.Next == nil { 	//l1链路走到尽头
				if l2 != nil {   	//l2后面还有值
                    tmp.Next = l2	//将l2尾链，接入l1
                    l2=nil			//清空l2
				} else {			
					tmp.Next = &ListNode{Val: 1}
                    return l1		//l2也没了，表示本次计算结束
				}   
			}
			tmp.Next.Val++			//满10进1
		} else if tmp.Next == nil {
			if l2 != nil {			
                tmp.Next = l2		//同理将l2尾链接入l1
			}
            return l1				//由于没有满10，无需判断后面尾链满10，直接返回
		}
	}
	return nil						//代码永远不可能走到这里
}
```
