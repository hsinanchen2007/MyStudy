比如说，给你以下 3 个有序链表：

1 -> 2 -> 4
1 -> 4 -> 8
0 -> 2

合并后的有序链表是：

0 -> 1 -> 1 -> 2 -> 2 -> 4 -> 4 -> 8


### 解题思路 
知道合并两个有序链表的思路，那么合并k个有序链表最容易想到的方法就是，

遍历链表数组，使用合并两个有序链表的方法，一个个合并过去即可。

假设这k个链表的平均长度是m，也就是平均下来，一个链表有m个节点。

则合并的节点总数 n 就是,n = k*m。合并两个有序链表的时间复杂度是他们长度之后。

那合并两个有序链表的时间复杂度是O(2m)，和第三条链表合并即时间复杂度是O(3m)。

一共k个链表，即总的时间复杂度是O(2m)+O(3m)+…+O(km) = O((k+2)(k-1)/2*m) = O(k^2*m),

因此k*m=n,所以总的时间复杂度是O(k*n),n是所有链表的节点总数。

这种方法是不需要使用额外的存储空间。因此空间复杂度是O(1)

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 辅助函数用于合并两个有序链表
func mergeTwoSortedLists(l1 *ListNode, l2 *ListNode) *ListNode {
   dummy := &ListNode{}
   p := dummy
   for l1 != nil && l2 != nil {
      if l1.Val < l2.Val {
         p.Next = l1
         l1 = l1.Next
      } else {
         p.Next = l2
         l2 = l2.Next
      }
      p = p.Next
   }
   // 连上l1剩余的链,连上l2剩余的链
   if l1 != nil {
      p.Next = l1
   }
   if l2 != nil {
      p.Next = l2
   }
   return dummy.Next
}

// Time: O(k*n), Space: O(1) n是所有链表的节点总数，k是链表个数
func mergeKLists(lists []*ListNode) *ListNode {
   if lists == nil || len(lists) == 0 {
      return nil // 链表为空或长度为0，直接返回空指针
   }
   var result *ListNode // 否则定义合并后的结果链表
   for _, list := range lists { // 定义链表数组
      // 和数组中的链表一个个合并
      result = mergeTwoSortedLists(result, list) 
   }
   return result // 最后返回合并后的链表
}
```

### 解题思路 - 最小堆
由于每个链表都是递增的，因此每次要拿的最小值都是在每个链表的头节点。

比如，上面3个有序链表第一个值应该在三个链表的头节点1，1，0中找最小值为0。

之后游标移动到 0 -> 2 节点0之后的节点2，然后要找1，1，2中的最小值。

使用这个方法依次取每个链表上的每一个节点，直到取完，就可以得到合并后的有序链表。

这种方法每一轮要对比k次。每一轮对比完可以确定一个节点，总共有n个节点。

因此时间复杂度是O(k*n)，这里可以做一点优化，使用最小堆来维护当前k个值的关系。

这样每次只需要O(1)的时间取得当前k个值的最小值。

则新的节点加入到大小为k的堆，则需要O(logK)的时间去调整堆的结构。

这样每一轮操作只能确定一个节点的位置，因此总时间复杂度是O(n*logk),

使用了大小为k的辅助堆，因此空间复杂度是O(k)

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// Time: O(n*log(k)), Space: O(k) n是总节点数量，k是链表个数
func mergeKLists2(lists []*ListNode) *ListNode {
   if lists == nil || len(lists) == 0 {
      return nil // 链表为空或长度为0，直接返回空指针
   }
   var h IntHeap // 最小堆用于维护当前k个节点
   heap.Init(&h) // 用于节点间的比较

   for _, list := range lists {
      // 数组中非空的链表加入到最小堆
      if list != nil {
         heap.Push(&h, list)
      }
   }
   // 定义dummy节点用于统一处理
   dummy := &ListNode{}
   p := dummy // p初始指向dummy节点

   // 当最小堆不为空时，不断执行以下操作
   for h.Len() > 0 { // 取出堆顶元素，即取出最小值节点
      min := heap.Pop(&h).(*ListNode)
      p.Next = min // 游标p指向最小值节点
      p = p.Next   // p向后移动一个位置
      // 这样就确定一个节点在合并链表中的位置
      if min.Next != nil { // 如果最小值节点后面的节点非空
         heap.Push(&h, min.Next) // 则把最小值节点后面的节点加入到最小堆中
      }
   }
   return dummy.Next // 最后只要返回dummy.Next即可
}

type IntHeap []*ListNode

func (h IntHeap) Len() int            { return len(h) }
func (h IntHeap) Less(i, j int) bool  { return h[i].Val < h[j].Val }
func (h IntHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) { *h = append(*h, x.(*ListNode)) }
func (h *IntHeap) Pop() interface{} {
   old := *h
   n := len(old)
   x := old[n-1]
   *h = old[0 : n-1]
   return x
}
```

### 解题思路 - 分治算法
像归并排序一样使用分治法处理，假如k个链表分别为a1, a2, a3,…, ak

不断递归直到只需要处理两个链表的合并，之后两两合并，得到b1, b2 , … , 新链表，

接着继续两两合并得到c1, c2,… 直到最后只剩下一条有序链表。

这个方法在每一层的合并中，都需要处理所有的n个节点，而每次处理后链表的数量变为原来的一半。

总共要处理logk次，总的时间复杂度是O(n*logk).

使用的辅助空间大小为递归调用的深度，总共有logk层，所以空间复杂度为O(logk)

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 辅助函数用于合并两个有序链表
// 辅助函数用于合并两个有序链表
func mergeTwoSortedLists(l1 *ListNode, l2 *ListNode) *ListNode {
   dummy := &ListNode{}
   p := dummy
   for l1 != nil && l2 != nil {
      if l1.Val < l2.Val {
         p.Next = l1
         l1 = l1.Next
      } else {
         p.Next = l2
         l2 = l2.Next
      }
      p = p.Next
   }
   // 连上l1剩余的链,连上l2剩余的链
   if l1 != nil {
      p.Next = l1
   }
   if l2 != nil {
      p.Next = l2
   }
   return dummy.Next
}

// 辅助函数，在还没有达到最基本情况前，不断递归调用自己
// 输入是链表数组，和当前要处理的在链表中开始和结束的下标，输出是合并后的链表
func merge(lists []*ListNode, start, end int) *ListNode {
   if start == end { // 当开始下标等于结束下标时
      return lists[start] // 说明当前要处理的只有一个链表，直接返回它即可
   }
   if start > end { // 否则如果开始下标大于结束下标
      return nil // 无效的，直接返回空指针nil
   }
   // 如果不是上面两种情况，就分而治之
   // 先找到当前子数组的中间下标
   mid := start + (end-start)/2
   // 然后分别递归处理前一半和后一半链表
   left := merge(lists, start, mid)
   right := merge(lists, mid+1, end)
   // 得到的结果是两条合并后的有序链表
   // 最后再把这两条链表也合并即可
   return mergeTwoSortedLists(left, right)
}

// Time: O(n*log(k)), Space: O(log(k))
func mergeKLists(lists []*ListNode) *ListNode {
   if lists == nil || len(lists) == 0 {
      return nil // 链表为空或长度为0，直接返回空指针
   }
   return merge(lists, 0, len(lists)-1)
}
```