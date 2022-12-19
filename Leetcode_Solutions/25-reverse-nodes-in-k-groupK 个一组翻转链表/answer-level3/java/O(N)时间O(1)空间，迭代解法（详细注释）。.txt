迭代解法：外层循环ceiling(N/k)次 内层开销O(k) 总时间复杂度O(N) 常数级额外空间使用，空间复杂度O(1)
```
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        //边界情况：0,1 个元素 或 k = 1 的情况下返回原链表
        if(head == null || head.next == null || k == 1) return head;
        ListNode l = head, r = head; //l,r指针用于确定反转区间
        //前一个block的反转后的尾部节点，要返回结果的头节点
        ListNode prevblk_tail = head, headofresult = null;
        int num_loops = 1;
        while(l != null) {
            int count = 0;
            for(; count < k; count++){//把r右移k步到下个block的开始(第k+1个节点)
                if(r == null) break;
                r = r.next;
            }
            if(count < k && r == null) {//移动不足k步，出现提前终止的情况
                if(num_loops == 1) return head;//边界情况：k>链表长度，返回原链表
                prevblk_tail.next = l;//剩余节点数目不足k,将前个block尾部连向当前block开始
                break;//对剩余节点不进行处理直接返回
            }
            ListNode new_head = reverse(l, r);
            if (num_loops == 1) headofresult = new_head;//第一次反转的头是最终结果的头
            //不是第一次，把前一次反转的尾接到当前这一次反转结果的头
            if (num_loops > 1) prevblk_tail.next = new_head;
            prevblk_tail = l;//更新操作
            l = l.next;//l,r都到了下个block的开始   例: k=2  1-2-3[l,r]-4 
            num_loops++;
        }
        return headofresult;
    }

    /**
     * 反转[a,b)区间的链表 反转后开头为pre(b的前一个)，结尾为b 
     * 例子：反转前1[a][curr]->2->3->4[b][pre]->5->null
     * 反转后3[pre]->2->1[a]->4[b][curr]->5->null
     */
    public ListNode reverse(ListNode a, ListNode b){
        ListNode cur = a, pre = b;
        while(cur != b){
            ListNode temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
}
 
```


递归解法：看起来更简单 时间复杂度O(N) 空间复杂度好像是O(1 * N/k)=O(N) 每个栈帧上都有常数级的空间调用
```
class Solution {
    ListNode reverse(ListNode a, ListNode b) { //反转[a,b)的链表并返回新的头节点
        ListNode curr = a, prev = null;
        while (curr != b) {
            ListNode nxt = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null) return null;
        ListNode a = head, b = head;
        for (int i = 0; i < k; i++) { //将b移动到第k+1节点位置
            if (b == null) return head;//<=k个节点(including null)
            b = b.next;
        }
        ListNode new_head = reverse(a, b);
        a.next = reverseKGroup(b, k); //旧头连向余下内容，新头用来返回
        return new_head;
    }
}
```




