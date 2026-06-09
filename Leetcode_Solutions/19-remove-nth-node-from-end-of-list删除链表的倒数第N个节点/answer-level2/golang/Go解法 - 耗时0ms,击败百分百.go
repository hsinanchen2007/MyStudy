一遍遍历的思路是用一个链表队列来实现，但插入队列的方法感觉可优化
但已经想了两三个小时了，头大，放弃了

```
type Queue struct {
 	Element *ListNode
 	Next *Queue
 }

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	rs := head
	if head.Next == nil {//一个或零个元素
		return nil
	}

	//初始化
	var queue Queue

	count := 0//记录队列里的数量

	for head != nil {
		if count >= n + 1 {
			queue = popQueue(&queue)
		}

		pushQueue(&queue, head)
		head = head.Next
		count++
	}
    
    //说明删除的是头指针
	if count == n {
		return rs.Next
	}

	//outQueue(&queue)
	//os.Exit(1)

	//此时队列头部，是带移除元素的前一个
	queue.Element.Next = queue.Element.Next.Next

	return rs
}

//入队 - 返回头指针和尾指针
func pushQueue(queue *Queue, listNode *ListNode) {
	for queue != nil {//遍历到队尾
		if queue.Next == nil {
			queue.Element = listNode
			var next Queue
			queue.Next = &next
			break
		}
		queue = queue.Next
	}
}

func popQueue(queue *Queue) Queue {
    queue = queue.Next
    return *queue
}
```