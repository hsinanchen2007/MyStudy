注意的点：
1、若两链表不等长，要判断哪个链表先结束。
2、考虑从低位进位和向高位进位，且前者要在后者之前判断
3、注意当前尾结点的位置别指错了
4、注意循环遍历链表节点别漏了
```
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode i1 = l1;
        ListNode i2 = l2;
        ListNode l3 = new ListNode(0);
        ListNode i3 = l3;
        int res = 0;
        boolean first = true;
        boolean isUp = false;
        while(i1 != null && i2 != null){
            res = i1.val + i2.val;
            System.out.println("res = " + res);
            if(isUp){
                res += 1;
                isUp = false;
            }
            if(res >= 10){
                isUp = true;
                res = res - 10; 
            }          
            if(first){
                first = false;
                l3.val = res;
                i3 = l3;
            } else {
            	i3.next = new ListNode(res);            	
            	i3 = i3.next;
            }
            i1 = i1.next;
            i2 = i2.next;
        }
        while(i1 != null){
            int val = i1.val;
            if(isUp){
                val += 1;
                isUp = false;
            }
            if(val >= 10){
                val = val - 10;
                isUp = true;
            }
            i3.next = new ListNode(val);
            i3 = i3.next;
            i1 = i1.next;
        }
        while(i2 != null){
            int val = i2.val;
            if(isUp){
                val += 1;
                isUp = false;
            }
            if(val >= 10){
                val = val - 10;
                isUp = true;
            }
            i3.next = new ListNode(val);
            i3 = i3.next;
            i2 = i2.next;
        }
        if(isUp){
            i3.next = new ListNode(1);
            i3 = i3.next;
        }
        return l3;
    }
```
