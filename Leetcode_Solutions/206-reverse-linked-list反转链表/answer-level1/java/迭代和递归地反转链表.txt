### 迭代
兩個指針a，b一前一後從左向右迭代，每回合做以下幾個動作：
1. b的下一個位置暫存在t
2. 讓b指向a
3. a移動到b
4. b移動到t

依此可以反轉每一個指針的方向

```
    public ListNode reverseList(ListNode head) {
        ListNode a = null;
        ListNode b = head;
        while(b != null) {
            ListNode t = b.next;
            b.next = a;
            a = b;
            b = t;
        }
        return a;
    }
```

### 遞歸
特殊情況判定，如果為空，則返回空
通過遞歸完成兩件事：
1. 沿著List找到最後一個節點返回它
2. 在返回的過程中調轉指針方向

```
    public ListNode reverseList(ListNode head) {
        if(head == null) {
            return null;
        }
        if(head.next == null) {
            return head;
        }
        ListNode res = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return res;
    }
```