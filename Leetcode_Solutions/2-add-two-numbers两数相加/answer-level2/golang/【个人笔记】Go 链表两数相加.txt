## 看题思路

看到这个题目的时候，我的最初想法是，分别遍历两个链表，计算出每个链表代表的数字，然后相加后，再拆分为新的链表作为结果。

这个题目应该可以扩展下：

1. 如何将一个非负整数的每一位转储为链表（LSB 或者 HSB）
2. 如何将链表中表示的数字转为非负整数
3. 整数按位求和的代码实现

实现了以上需求，就可以写出来一个通用的转换代码。

## 想法

- 作者出这个题目的初衷是什么？
- 为了达到测试什么的目的？
- 通过该题目能锻炼你哪方便的能力

**猜测：**

- 初衷和目的
    - 检查链表结构的掌握及应用能力
    - 检查逻辑思维
    - 检查编程的严谨程度（思维是否严谨）
    - 检查对大数的处理（比 uint64 类型能表示的最大数还要大）
- 题目得到的锻炼
    - 链表结构的遍历
    - 基本算法的锻炼

## 题解代码

最初，我的想法是将每一个链表中存储的数转化出来，合成一个数，并用一个变量存储。但是，代码写完后，发现如果链表中存储的是一个大数（比 uint64 的表示范围还要大），那么就会出现数据类型溢出，无法使用 uint64 来表示。问题代码如下：

```
import "fmt"
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    
    var num1 uint64 = uint64(0)
    var num2 uint64 = uint64(0)
    var sum uint64 = uint64(0)
    ret_list := &ListNode{0, nil}
    ret_list_bak := ret_list
    
    var i uint64 = uint64(1)

    for {
        fmt.Println(i)
        if l1 != nil {
            num1 = num1 + uint64(l1.Val) * i
            l1 = l1.Next
        }
        
        if l2 != nil {
            num2 = num2 + uint64(l2.Val) * i
            l2 = l2.Next
        }
        
        if l1 == nil && l2 == nil {
            break
        }
        
        i *= 10
    }
    sum = num1 + num2
    
    for {
        zhengshu := sum / 10
        yushu := sum % 10
        
        ret_list_bak.Val = int(yushu)
        
        if zhengshu == 0 {
            break
        }
        ret_list_bak.Next = &ListNode{0, nil}
        ret_list_bak = ret_list_bak.Next
        sum = zhengshu
    }
    return ret_list
}
```

因此，合适的解题思路就是小学学习的整数的加法运算法则，用竖式的方式运算。

正确思路的解题代码如下：

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    num1 := 0
    num2 := 0
    sum := 0
    ret_list := &ListNode{0, nil}
    ret_list_bak := ret_list

    jinwei_flag := 0

    for {
        num1 = 0
        num2 = 0

        if l1 != nil {
            num1 = l1.Val
            l1 = l1.Next
        }
        
        if l2 != nil {
            num2 = l2.Val
            l2 = l2.Next
        }

        sum = num1 + num2 + jinwei_flag
        jinwei_flag = sum / 10
        ret_list_bak.Val = sum % 10

        if l1 == nil && l2 == nil && jinwei_flag == 0 {
            break
        }

        ret_list_bak.Next = &ListNode{0, nil}
        ret_list_bak = ret_list_bak.Next
    }
    return ret_list
}
```

平台参考用时 4 ms，参考内存 5MB