### 解题思路
剑指offer的一道原题

### 代码

```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */
func copyRandomList(head *Node) *Node {
    //1->2(4)->3->4->nil
    if head == nil {
        return nil
    }

    //1->1->2->2->3->3->4->4
    res := copyNextPoint(head)

    //1->1->2(4)->2(4)->3->3->4->4
    res = copyRandomPoint(res)

    //1->2(4)->3->4->nil
    res = listCut(res)

    return res
}

func copyNextPoint(head *Node) *Node {
    temp := new(Node)
    temp.Next = head
    p := head
    for p != nil {
        tmp := new(Node)
        tmp.Val = p.Val
        tmp.Next = p.Next
        p.Next = tmp
        p = p.Next.Next
    }
    return temp.Next
}

func copyRandomPoint(head *Node) *Node {
    temp := new(Node)
    temp.Next = head
    p := head

    for p != nil {
        if p.Random != nil {
            temp_random := p.Next
            temp_random.Random = p.Random.Next
        }
        p = p.Next.Next
    }
    return temp.Next
}

func listCut(head *Node) *Node {
    temp := new(Node)
    res := temp

    for old := head; old != nil;{
        res.Next = old.Next
        old.Next = res.Next.Next
        old, res = old.Next, res.Next
    }
    return temp.Next
}
```