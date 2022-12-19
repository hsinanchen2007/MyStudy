**先不考虑进位，直接将val值相加。接着再while加if判断val是否大于10，是则进位**


先上代码：
```
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode sum = l1;
        while(l1.next!=null&&l2.next!=null){
            l1.val += l2.val;
            l1 = l1.next;
            l2 = l2.next;
        }
        l1.val += l2.val;
        if(l1.next==null&&l2.next!=null){
            l1.next = l2.next;
        }
        l1 = sum;
        while(l1.next!=null){
            if(l1.val>9){
                l1.val -= 10;
                l1.next.val++;
            }
            l1 = l1.next;
        }
        if(l1.val>9){
            l1.val -= 10;
            l1.next = new ListNode(1);
        }
        return sum;
    }
}
```



就用了2ms，时间复杂度大概是O(2*max(m,n))。。
**把所有if塞进一个循环不可取**（或许有大神可以优化），
进位可以参考leetcode官方的题解，其它都是小问题；；

因为全部结果都加在l1里,假如碰到l1==null,而l2不是null,这时不要为l1 new一个ListNode来储存结果，
看代码：
```
if(l1.next==null&&l2.next!=null){
    l1.next = l2.next;
}
```

