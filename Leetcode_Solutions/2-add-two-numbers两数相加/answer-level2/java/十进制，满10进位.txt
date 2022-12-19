### 解题思路
倒序相加就很简单了， 十进制，两数相加满10进位就行，  正序才麻烦。

执行用时 :
2 ms, 在所有 Java 提交中击败了99.97%的用户
内存消耗 :40 MB, 在所有 Java 提交中击败了95.71%的用户

### 解题代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode sum = new ListNode(0);
        ListNode head = sum;
        while(l1!=null || l2!=null) {
            sum.val += l1 == null? 0 : l1.val;
            sum.val += l2 == null? 0 : l2.val;
            if(sum.val >= 10) {
                sum.next = new ListNode(sum.val/10);
                sum.val = sum.val%10;
            }
            l1 = l1==null || l1.next == null ? null : l1.next;
            l2 = l2==null || l2.next == null ? null : l2.next;
            if((l1 != null || l2 !=null) && sum.next == null) {
                sum.next = new ListNode(0);
            }
            sum = sum.next;
        }
        return head;
    }
}
```

一开始以为正序数字，而且以为是自由编码。写了一大堆。。。
### 正序代码

```java
public static void main(String[] args) {
        List<Integer> a = new ArrayList<Integer>();
        a.add(1);
        a.add(4);
        a.add(6);

        List<Integer> b = new ArrayList<Integer>();
        b.add(1);
        b.add(3);
        b.add(5);
        b.add(5);
        //1 3 5;
        //2 4 6 8;
        int minSize = a.size()<b.size()? a.size():b.size();
        boolean aGtb = a.size()>b.size();
        boolean bGta = b.size()>a.size();
        int diff = Math.abs(a.size()-b.size());
        LinkedList<Integer> sum = new LinkedList<Integer>();
        for(int i=minSize-1; i>=0; i--) {
            if(diff == 0) {
                sum.add(a.get(i) + b.get(i));
            } else if(aGtb) {
                sum.add(a.get(i+diff) + b.get(i));
            } else if(bGta) {
                sum.add(b.get(i+diff) + a.get(i));
            }
        }
        if(diff > 0) {
            if(aGtb) {
                for(int i=diff-1; i>=0; i--) {
                    sum.add(a.get(i));
                }
            } else {
                for(int i=diff-1; i>=0; i--) {
                    sum.add(b.get(i));
                }
            }
        }
        for (int i=0; i<sum.size(); i++) {
            int currentNum = sum.get(i);
            if(currentNum>=10) {
                sum.set(i, currentNum%10);
                sum.set(i+1, sum.get(i+1)+currentNum/10);
            }
        }
        for (Integer o : sum) {
            System.out.print(o+" ");
        }
    }
```
