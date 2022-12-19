### 解题思路

2020/3/31  更新的全新版本
双百分百版本

增加了哨兵，一个空的头节点res接受不重复的节点

核心方法：双指针，pre和curr

```
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil || head.Next == nil{
        return head
    }

    //哨兵res
    res := new(ListNode)
    p := res
    //双指针
    curr := head.Next
    pre := head
    
    for curr != nil {
        if pre.Val == curr.Val {
            for curr != nil && curr.Val == pre.Val {
                //找到第一个与pre不重复的节点
                curr = curr.Next
            }
            if curr == nil {
                //从pre开始到结束都是重复的节点
                p.Next = nil
                return res.Next
            }
            //更新pre和curr
            pre = curr
            curr = curr.Next
            //进入下一次判断
            continue
        } else {
            p.Next = pre
            curr = curr.Next
            pre = pre.Next
            p = p.Next
        }
    }

    if p.Val != pre.Val {
        p.Next = pre
        p = p.Next
        p.Next = nil
    }

    return res.Next
}
```




-------------------------------------------------------------------------------------------------------------------
对于链表处理，有两个比较特殊的情况，一头一尾。

因为leetcode所给链表都不包含为空的头节点，所以我比较倾向于在处理中间不对之前就对头部进行必要的处理。

0.边界处理：
```
if head == nil || head.Next == nil {
        return head
    }

```
1.处理头节点
由已知可得，本题所需要处理的是重复的节点，所以先要处理与投头节点相同的节点，且更新头节点的位置。
又因为存在这种:1,1,1,2,2,2,3,3,4 的需要多次循环处理头节点的情况，因此我选择用循环进行判断：
```
for head.Next != nil && head.Val == head.Next.Val {
        q := head.Next
        for q.Val == head.Val {
            if q.Next == nil {
                return nil
            }
            q = q.Next
        }
        head = q
    }

```
这样的处理能够保持head时刻为一个不重复的节点。

2.中间部分处理：
对于中间部分的处理，由于链表结构的特殊性，我选择双指针标记的方法。
指针curr指向现在遍历到的这个节点
指针pre指向curr前面的一个节点，保持pre.Next == curr
然后用指针 p 在curr的右边进行游走（实际上是三个指针，不过p指针没有标记的作用）

处理思路:
在经过1处理的head链表中，头节点不可能为一个重复节点，所以只需要从第二个节点开始查询。
初始时刻，设定pre = curr = head ,p 则在curr的右边 ， p = curr.Next
```
    curr := head
    pre := head
    p := curr.Next
    flag := false
```
把第二个节点作为curr，并总与p进行对比（p总是在curr的右边）
情况1：如果curr.val == p.val 说明curr是一个重复节点，最后结果中比不可能有它，所以我们找到第一个不等于curr.val来替换它，并对这个过程设置一个标记flag = true（是替换不是连接，所以需要单独处理）；
情况2：如果curr.val != p.val，则判断flag，如果flag == true ，则说明此前是找到了重复子节点，那么现在对curr进行替换操作（curr = p）而不是连接操作；如果flag == false ， 则说明此前没有重复节点，可以在curr后连接p。处理完毕后将flag 置为false

```
for p.Next != nil {
        if curr.Val != p.Val {
            if flag {   
                //curr为重复节点，进行替换再检查
                flag = false
                pre.Next = p
                curr = pre.Next
                p = p.Next
                continue
            }
            //curr不与前面的节点为重复节点，直接向后移
            //pre始终保持再curr前面
            pre = curr 
            //curr向后连接并后移
            curr.Next = p
            p = p.Next
            curr = curr.Next
        } else {
            //curr目前存在重复节点的情况
            flag = true
            p = p.Next
            continue
        }
    }

```

3.处理末尾节点
因为 p.Next != nil 的判断条件，2中并未对尾节点进行判断，所以需要进行单独处理。
```
//处理最后一个节点
    //因为最后一节点没有检查就直接跳出了循环，所以需要对最后一个节点的情况进行单独检查
    //情况1.倒数第二个节点为重复节点，且最后一个节点不为重复节点，则直接从pre连接p，因为此时的curr也为重复节点
    if curr.Val != p.Val && flag{ 
        pre.Next = p
    } else if curr.Val == p.Val {
        //情况2.最后一个节点为重复节点，则pre直接指向nil，因为此时的curr是和最后一个节点相同的重复节点
        pre.Next = nil
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
func deleteDuplicates(head *ListNode) *ListNode {
    //边界条件判断
    if head == nil || head.Next == nil {
        return head
    }

    //若头节点是重复节点:
    //类似 1,1,2,2,3,4   1,1,1,1   1,1,1,2
    //这种情况
    for head.Next != nil && head.Val == head.Next.Val {
        q := head.Next
        for q.Val == head.Val {
            if q.Next == nil {
                return nil
            }
            q = q.Next
        }
        head = q
    }

    //边界条件判断
    if head == nil || head.Next == nil {
        return head
    }

    curr := head
    pre := head
    p := curr.Next
    flag := false

    //中间处理
    //pre总是保持在curr的前面
    //curr会遇到三种情况：
    //1.curr不为重复节点，那么直接添加；
    //2.curr为重复节点，则需要发现第一个与curr不同的节点，并进行替换

    for p.Next != nil {
        if curr.Val != p.Val {
            if flag {   
                //curr为重复节点，进行替换再检查
                flag = false
                pre.Next = p
                curr = pre.Next
                p = p.Next
                continue
            }
            //curr不与前面的节点为重复节点，直接向后移
            //pre始终保持再curr前面
            pre = curr 
            //curr向后连接并后移
            curr.Next = p
            p = p.Next
            curr = curr.Next
        } else {
            //curr目前存在重复节点的情况
            flag = true
            p = p.Next
            continue
        }
    }

    //处理最后一个节点
    //因为最后一节点没有检查就直接跳出了循环，所以需要对最后一个节点的情况进行单独检查
    //情况1.倒数第二个节点为重复节点，且最后一个节点不为重复节点，则直接从pre连接p，因为此时的curr也为重复节点
    if curr.Val != p.Val && flag{ 
        pre.Next = p
    } else if curr.Val == p.Val {
        //情况2.最后一个节点为重复节点，则pre直接指向nil，因为此时的curr是和最后一个节点相同的重复节点
        pre.Next = nil
    }

    // if pre == curr && curr.Val == p.Val {
    //     return nil
    // }

    return head
}

func myPrint(l *ListNode) {
    for l.Next != nil {
        fmt.Println(l.Val)
        l = l.Next
    }
    fmt.Println(l.Val)
    fmt.Println("_------------------")
}
```