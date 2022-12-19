### 解题思路
1. 最容易想到的就是暴力求解办法，但是需要使用容器将已经遍历过的结点存储起来，下次判断是否已经有相同的元素了，如果有的话那么就是存在环的。那么自然就想到使用Hash或者 Set来解决。 
    - 时间复杂度O(n)
    - 空间复杂度O(n)
    
2. 但是题目中要求使用存储O(1)的方法来解决。那么我们就对以往遍历过的结点没有了记忆能力。只能通过另外的方式来解决。如果一个指针解决不了，就尝试提升问题维度，使用两个指针来看看，只要两个指针遍历的地方有重合就说明有重复元素。类比龟兔在环形操场赛跑，兔子总能撵上乌龟。所以把链表比成跑道。一个指针比作乌龟，速度为1 。另外一个指针比作兔子，速度为2.让他们去跑，

    - 时间复杂度为 O(n),这块儿参考官方题解，分为非环形部分和环形部分两部分时间，加起来还是O(n)
    - 空间复杂度O(1)
    
注意事项: 
- 要处理好空指针问题
- 要注意跑得快的人从哪里开始跑，这个很重要！！！(看下方对比解释)

### 我的代码

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        //1. 可以暴力求解，遍历，使用 hash/set判断是否在是已经存在容器中的结点
        //2. 快慢指针，如果是有环的话，快指针总会追上慢指针
        if(head == null || head.next == null){
            return  false;
        }
        ListNode slow, fast;
        slow = head;
        //仔细观察，我的初始版本代码这里跑得快的指针直接领先了跑得慢的人两步
        fast = head.next.next;
        while(slow != null && fast != null && fast.next != null){
            if(fast == slow){
                return true;
            }
            fast = fast.next.next;
            slow = slow.next;
        }
        return  false;
    }
}
```


### 参考官方题解写的代码
```java
public boolean hasCycle(ListNode head) {
         //1. 可以暴力求解，遍历，使用 hash/set判断是否在是已经存在容器中的结点
        //2. 快慢指针，如果是有环的话，快指针总会追上慢指针
        if(head == null || head.next == null){
            return  false;
        }
        ListNode slow,fast;
        slow = head;
        //仔细观察，官方题解版本代码这里跑得快的指针直接领先了跑得慢的人 仅 1 步
        fast = head.next;
        while(slow != fast){
            if(fast == null || fast.next == null){
                return false;
            }
            fast = fast.next.next;
            slow = slow.next;
        }
        return  true;
    }
```

由于我的代码中跑得快的指针领先的两步，导致在以后跑的过程中如果正好遇到在环中慢的人在快的人前面1步，那么就需要多一个迭代周期，也就是多一圈才能追上慢指针。所以就变慢了。所以我提交后，执行时间是1ms,仅仅打败了36%的人。但是修改之后我的也和官方一样，0毫秒，能击败100%的人了。
### 修改后的我的代码
```java
public class Solution {
    public boolean hasCycle(ListNode head) {
       if(head == null || head.next == null){
            return  false;
        }
        ListNode slow, fast;
        slow = head;
        //注意这里，快指针起跑位置只领先一步
        fast = head.next;
        while(slow != null && fast != null && fast.next != null){
            if(fast == slow){
                return true;
            }
            fast = fast.next.next;
            slow = slow.next;
        }
        return  false;
    }
}
```
