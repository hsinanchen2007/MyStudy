### 解题思路
![屏幕快照 2020-03-17 下午5.43.31.png](https://pic.leetcode-cn.com/7080dfd01adf85d5a705496da5b0ead0dfc1d5e220c236434aa0e2be281741a5-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-17%20%E4%B8%8B%E5%8D%885.43.31.png)
0ms还是把我吓一跳。。。双指针，看了思路没看代码自己写的。代码有点啰嗦。

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode uselessHead = new ListNode(0);
        uselessHead.next = head;
        if(uselessHead.next ==null){
            return new ListNode();
        }else{
            int i = 1;
            ListNode beforeNode = new ListNode();
            ListNode firstNode = new ListNode();
            ListNode secondNode = new ListNode();
            while(head!=null){
                secondNode = head;
                head = head.next;
                if(i==n){
                    beforeNode = uselessHead;
                    firstNode = beforeNode.next;                
                }
                if(i>n){
                    beforeNode = beforeNode.next;
                    firstNode = beforeNode.next;
                }
                i += 1;
            }
            if(i<n){
                return new ListNode();
            }
            beforeNode.next = firstNode.next;
            return uselessHead.next;
        }
    }
}
```
然后看了大伙的精简了一下,但是存储量还是很高不知道为什么。思路就是second先走n步，然后first和second一起走，当second走到尾巴时，first指向第倒数n+1个节点。我最开始是设置三个指针，多了一个第倒数n的指针。
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode uselessHead = new ListNode(0);
        uselessHead.next = head;
        ListNode firstNode = uselessHead,secondNode = uselessHead;
        while(n>0){
            secondNode =  secondNode.next;
            n--;
        }
        while(secondNode.next!=null){
                firstNode = firstNode.next;;
                secondNode = secondNode.next;
            }
            firstNode.next = firstNode.next.next;
            return uselessHead.next;
        }
    
}
```