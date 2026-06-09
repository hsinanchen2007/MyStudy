# 解法一：遍历两次head

**第一次记录链表的数量,第二次进行将链表中的值取出并逆序摆放进数组**

**--执行用时：0 ms --内存消耗：2.8 MB**

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
    cur:=head//备份链表
    n:=0
    //遍历链表记录链表数
    for head!=nil{
        head=head.Next
        n++
    }
    //再次遍历链表逆序摆放进数组
    nums:=make([]int,n)//申请一个数组,n可作用在这里预申请空间,大大减少了内存消耗
    for {
        if cur==nil{
            break
        }
        nums[n-1]=cur.Val
        cur=cur.Next
        n--
    }
    return nums
}
```

# 解法二：反转链表后再按序加入数组

**--执行用时：4 ms --内存消耗：3.1 MB**

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
    pre:=new(ListNode)
    //反转链表
    for head!=nil{
        pre,head,head.Next=head,head.Next,pre
    }
    //遍历链表
    nums:=make([]int,0)//申请一个数组
    for pre.Next!=nil{
        nums=append(nums[:],pre.Val)
        pre=pre.Next
    }
    return nums
}
```

# 解法三：递归解法

**--执行时间：4 ms--消耗内存：4.6 MB**

**（代码简洁，但相对于执行时间和内存消耗，都要比“代码量最多的解法一”多）**

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
    if head == nil {
        return []int{}
    }
    return append(reversePrint(head.Next), head.Val)
}
```

