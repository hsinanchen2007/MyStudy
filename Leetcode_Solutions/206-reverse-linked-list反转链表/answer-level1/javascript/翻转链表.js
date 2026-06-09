### 方法1 借助数组

理解起来最简单，利用数组，将链表中的元素依次放入，最后，从数组最后一个元素开始，构建最终的链表

    /**
     * Definition for singly-linked list.
     * function ListNode(val) {
     *     this.val = val;
     *     this.next = null;
     * }
     */
    /**
     * @param {ListNode} head
     * @return {ListNode}
     */
    var reverseList = function(head) {
      if (head === null) return null
      
      const queue = []
      while (head) {
        queue.push(head)
        head = head.next
      }
      for (let i = queue.length - 1; i > 0; i--) {
        queue[i].next = queue[i - 1]
      }
      queue[0].next = null
      return queue[queue.length -1]
    };

### 方法2 原地修改指针

    var reverseList = function(head) {
      let prev = null
      let curr = head
      while (curr) {
        let tmp = curr.next
        curr.next = prev
        prev = curr
        curr = tmp
      }
      return prev
    };