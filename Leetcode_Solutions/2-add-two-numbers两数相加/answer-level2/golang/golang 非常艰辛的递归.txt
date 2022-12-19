### 解题思路
1. 非常艰辛的递归实现，说一下几个容易出错的点：
2. 第一，很容易忘了array=array+Val(l1)+Val(l2)中的第二个array，也就是双进位的情况；
3. 第二，针对两个链表长度不同，增加判断，这里比较麻烦增加了为空的时候的值判断和是否有next判断，可以合并为一个，会让代码更漂亮。
4. 第三，一开始写的时候总会发现链表最后多个节点，后来参考python的写法，去掉了，还在研究为什么会多节点的问题。欢迎探讨。
原来的主函数代码如下：
```
func addTwoNumbersRec(array int,l1 *ListNode, l2 *ListNode, lNode *ListNode) {
 if l1==nil && l2==nil{
   if array>0{
      lNode=&ListNode{Val:1}
  }else{
       lNode=nil
  }
  return
 }
 s:=array+isVal(l1)+isVal(l2)
 lNode=&ListNode{Val:s%10}
 array=s/10
 addTwoNumbersRec(array,isNil(l1),isNil(l2),lNode.Next)
}
```

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
  lNode:=ListNode{Val:0}
  array:=0
  addTwoNumbersRec(array,l1,l2,&lNode)
  return lNode.Next
}
func isVal(l *ListNode) int{
    if l==nil{
        return 0
    }else{
        return l.Val
    }
}
func isNil(l *ListNode) *ListNode{
 if l!=nil{
  return l.Next
 }else{
  return nil
 }
}
func addTwoNumbersRec(array int,l1 *ListNode, l2 *ListNode, lNode *ListNode) {
 if l1==nil && l2==nil{
   if array>0{
      lNode.Next=&ListNode{Val:1}
  }else{
       lNode=nil
  }
  return
 }
 s:=array+isVal(l1)+isVal(l2)
 lNode.Next=&ListNode{Val:s%10}
 array=s/10
 addTwoNumbersRec(array,isNil(l1),isNil(l2),lNode.Next)
}
```