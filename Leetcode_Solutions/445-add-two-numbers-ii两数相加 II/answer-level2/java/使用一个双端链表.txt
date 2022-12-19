##### 执行用时 :6 ms, 在所有 Java 提交中击败了99.28%；内存消耗 :42.7 MB, 在所有 Java 提交中击败了92.63%的用户

##### 复杂度分析
- 空间复杂度：O(max(m,n)+1)，使用一个queue最长为max(m,n)+1，+1为最高位进位。
- 时间负责度：O(max(m,n))

##### 举例
- 9 5 4 3
- 0 5 6 4

#### 入队尾 9 10 10 7

#### 出队尾并入队首，逢10进1：
- 9,10,10,7 (c = 0)  // 初始进位c=0
- 7,9,10,10 (c = 0) 
- 0 ,7, 9, 10 (c = 1) 
- 1 ,0 ,7 ,9  (c = 1) 
- 0 ,1, 0, 7 (c = 1)
- 1 ,0, 1, 0, 7  结果





```
 public static ListNode helper(ListNode l1, ListNode l2) {
        if (l1==null||l2==null) return l1 != null ? l1 : l2;
        Deque<ListNode> queue = new LinkedList<>();  
        int length = 0, len1 = 0 ,len2 = 0;        
        ListNode cur = l1;        
        while (cur != null && ++len1 !=0) cur = cur.next;cur = l2;                      
        while (cur != null && ++len2 !=0) cur = cur.next;        
        cur = len1 >= len2 ? l1:l2;        
        ListNode mcur = len1 >= len2 ? l2:l1;         
        length = Math.abs(len1-len2);        
        for (;length-- != 0;cur = cur.next) 
            queue.addLast(cur);           
        for (;cur != null ;cur = cur.next,mcur = mcur.next)
            queue.addLast(new ListNode(cur.val+mcur.val));                      
        length = len1 >= len2 ? len1 : len2;        
        int c = 0;        
        while( length-- != 0) {
            cur = queue.pollLast();
            int value = cur.val+c;
            cur.val = value%10;
            queue.addFirst(cur);
            c = value/10;
        }        
        if (c == 1) queue.addFirst(new ListNode(1));      
        ListNode head = queue.peekFirst();        
        while (!queue.isEmpty())  queue.pollFirst().next = queue.peekFirst();   
        return head;
    }   
```
