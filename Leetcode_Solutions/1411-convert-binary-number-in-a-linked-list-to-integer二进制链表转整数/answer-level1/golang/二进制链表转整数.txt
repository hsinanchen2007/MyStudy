### 解题思路
位运算

### 代码
```java []
class Solution {
    public int getDecimalValue(ListNode head) {
        int n = -1;
        ListNode p = head;
        while (p != null){
            n++;
            p = p.next;
        }
        int num = 0;
        p = head;
        while(p != null){
            num += p.val << n;
            n--;
            p = p.next;
        }
        return num;
    }
}
```


```golang []
func getDecimalValue(head *ListNode) int {
	var n uint = 0
	p := head
	for p != nil {
		n++
		p = p.Next
	}
	p = head
	num := 0
	n--
	for p!= nil {
		num += p.Val << n
		p = p.Next
		n--
	}
	return num
}
```

