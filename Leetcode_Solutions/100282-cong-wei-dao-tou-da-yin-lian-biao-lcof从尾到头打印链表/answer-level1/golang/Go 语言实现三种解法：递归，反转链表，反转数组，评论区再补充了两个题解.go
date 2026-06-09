> 题目：从尾到头打印链表
>
> 要求：输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
>
> 示例：
>
> ```
> 输入：head = [1,3,2]
> 输出：[2,3,1]
> ```
>
> 限制：
>
> 0 <= 链表长度 <= 10000



题解1：递归法



思路：因为是从尾到头返回每一个节点的值，所以很容易想到如果从最后的节点将值放入数组中，然后再往前逐步将数据放入数组，最后回到头节点返回即可，可以想到递归就能轻松做到，只要注意递归函数的结束条件即可。



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
        return nil
    }

    return appendData(head)
}

func appendData(head *ListNode) []int {
    if head.Next != nil{
        list := appendData(head.Next)
        list = append(list, head.Val)
        return list
    }

    return []int{head.Val}
}
```



自然而然，效率不会很高~

![image-20200225162851962.png](https://pic.leetcode-cn.com/6f3119fc07e7601cddd5b35d62ef75e1928e1206bb3fe4c673fd3f79157b4e25-image-20200225162851962.png)




题解2：



想了一下，这样不行啊，耗时这么长，试试不用递归吧~



然后就想，如果我反转链表呢，再生成数组返回，这样也可以实现吧？



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
        return nil
    }

    var newHead *ListNode
    res := []int{}
    for head != nil {
        node := head.Next
        head.Next = newHead
        newHead = head
        head = node
    }

    for newHead != nil {
        res = append(res, newHead.Val)
        newHead = newHead.Next
    }

    return res
}
```



结果如下：

![image-20200225165712153.png](https://pic.leetcode-cn.com/116458472b5ca2d496b78e16f9835fa1a6281a3a8c468fa9151610e32f1287ff-image-20200225165712153.png)




解法3：



反转链表再获取数值，可以是可以，会不会有点多余？还不如直接顺序获取值放到数组，再反转结果呢~



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
        return nil
    }

    res := []int{}
    for head != nil {
        res = append(res, head.Val)
        head = head.Next
    }

    for i, j := 0, len(res)-1; i < j; {
        res[i], res[j] = res[j], res[i]
        i++
        j--
    }

    return res
}
```



至此，结果有了很大的提升：

![image-20200225170439975.png](https://pic.leetcode-cn.com/858b7a85d1106165e61c98b77442c87ae2075a2080e412dae9fe5440d5c5aaa0-image-20200225170439975.png)


走过路过点个赞啊，希望能帮助到你~