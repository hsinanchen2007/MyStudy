### 如果死套排序数组的快排，那么肯定难了（因为：链表交换两个节点比数组复杂太多了），而且链表的遍历方式是单向的，使用左右指针并不好处理。让我们回想一下，快排的定义：
1、选取一个基准值
2、遍历，将小于基准的放到左边，大于的放到右边
3、递归执行
#### 那么对于链表，条件一不需要变，条件三也不需要，需要变的只有第二个条件。如何将小的大的分开呢？一个好方法是我们只需要重新定义三个哨兵节点，分别指向小于，等于，大于的链表的节点即可：以 -1->5->3->4->0为例，以3为基准，lhead:{-1,0} , mhead{3}, rhead{4,5}.将这三个连起来即可
```
//链表快排(分为三部分实现)
func sortList(head *ListNode) *ListNode {
    return quicksort(head)
}

func quicksort(head *ListNode)*ListNode{
    //出递归条件（没有节点或者只有一个节点时，不需要再分）
    if head==nil || head.Next==nil{
        return head
    }
    //遍历链表，将其分为三部分（三个哨兵节点）
    lhead:=&ListNode{-1,nil}//小于基准值
    mhead:=&ListNode{-1,nil}//等于基准值
    rhead:=&ListNode{-1,nil}//大于基准值
    left,mid,right:=lhead,mhead,rhead
    //基准值不一定非以最左边为基准
    pivot:=head.Val//基准值（以最左边的节点为基准）
    //遍历链表
    for p:=head;p!=nil;p=p.Next{
        if p.Val<pivot{ //小于给左边
            left.Next=p
            left=left.Next
        }else if p.Val > pivot{ //大于给右边
            right.Next=p
            right=right.Next
        }else{ //等于去中间
            mid.Next=p
            mid=mid.Next
        }
    }
    //将左中右节点值最后设为nil（防止后面还连着东西）
    left.Next=nil
    mid.Next=nil
    right.Next=nil
    //递归处理左右段
    lhead.Next=quicksort(lhead.Next)
    rhead.Next=quicksort(rhead.Next)
    //将左右段拼接起来
    //找到左端的尾节点
    getTail(lhead).Next=mhead.Next
    //找到中间的尾节点
    getTail(mhead).Next=rhead.Next
    return lhead.Next
}
//取得尾节点
func getTail(head *ListNode)*ListNode{
    for head.Next!=nil{
        head=head.Next
    }
    return head
}
```
### 本题解只是为了解决面试可能会问到这个，并不满足题意，空间复杂度为O(log(n))