### 解题思路
链表反向给出数字的顺序其实是方便的计算，思路参考ALU的加法部分，使用一个c标志位判断进位
只要l1， l2，中有一个不为空就要继续计算。最后结尾注意一下，如果c在运算完仍是1，不要忽略它。

代码与官方思路一致，我写的太啰嗦了
### 代码

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
        int c = 0;//进位
        ListNode result = null;
        int temp;
        while (l1!=null || l2!=null){
            if(l1==null){
                temp = l2.val + c;
                if(temp > 9){
                    temp -= 10;
                    c = 1;
                }else {
                    //使用了标志位就要清零，不要忘记
                    c = 0;
                }
                result = add(result, temp);
                l2 = l2.next;
            }else if(l2 == null){
                temp = l1.val + c;
                if(temp > 9){
                    temp -= 10;
                    c = 1;
                }else {
                    c = 0;
                }
                result = add(result, temp);
                l1 = l1.next;
            }else {
                temp = l1.val+l2.val+c;
                if(temp > 9){
                    temp -= 10;
                    c = 1;
                }else {
                    c = 0;
                }
                result = add(result, temp);
                l1 = l1.next;
                l2 = l2.next;
            }
        }
          if(c == 1){
            result = add(result, 1);
        }
        return result;
    }

    public ListNode add(ListNode root, int value){
        ListNode temp = root;
        if(temp == null){
            temp = new ListNode(value);
            return temp;
        }else {
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = new ListNode(value);
        }
        return root;
    }
}
```