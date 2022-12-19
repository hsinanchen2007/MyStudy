### 解题思路
双指针最快方案(才知道大家都是0ms, 还以为自己今天灵光一闪, 自己做出最快的了. 我不玩儿了)

![image.png](https://pic.leetcode-cn.com/57ec6fe7ba45d329e0988a5a609e947f0722f9e8002f01ecc3f5dd47411f656a-image.png)

时间复杂度O(L);

- 按照常规思路来说, 这也算是双指针了吧, 一开始我确实想要循环两遍获得总长度的思路来解决. 暴力解决方案永远是最首先出现在我的脑海里的, 不能说不对, 只能说不好, 或说明我的思路还不够广泛, 遇到问题第一反应是穷举。

- 双指针是突然闪现到脑海里的, 倒数第n个, 是否可以用间隔n位的两个指针一遍循环获得答案呢? 可以说这个思路是我在做了好几遍三数和四数和这类题之后积累出来的双指针方案吧, 侧面也证明了我确实有记住一些算法思路! 嘻嘻.

- 其实这个双指针已经在第二点解释的很明白了. 但做出来时还是遇到了很多问题
1. 问题: 链表为空 --> 解决方案: 很简单, 开始时检测出来并直接返回null.
2. 问题: 链表只有一位, 需要删除倒数第一位的值 --> 解决方案: 也不难, 开始时检测链表的next是否为null, 并且判断n == 1? 若true, 直接返回null.
3. 问题: 链表只有两位, 需要删除倒数第二位的值 --> 解决方案: 实际上我这里有点取巧了, 因为我是在flag数到第n个值时才为第二个指针赋值的, 因此这个问题在循环结束时(当temp指向end时, flag == 1 != n, 此时赋值条件仍不成立), 实际上我还没有为第二个指针赋值, 实际为null, 那么我的解决办法也很简单, 结尾时候判断一下, 直接返回head.next.

- 注: 第一个指针为temp, 顺序向后循环指向. 第二个指针为delLast, 指向需要删除的节点的前一位, 并与 temp 间隔 **n + 1** 个节点.

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
    // 让一个指针跟着循环指针, 隔着n个位置. 而当循环指针结束时, 这个指针正好走到了倒数第n位的位置
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null || head.next == null && n == 1)
            return null;
        ListNode delLast = null;
        ListNode temp = head;
        int flag = -1;
        while(temp != null)
        {
            // 当为delLast赋值后, 让delLast也跟着循环走;
            if(delLast != null)
            {
                delLast = delLast.next;
            }
            else{
                flag = (flag + 1) % n;
                if(delLast == null && temp != head && flag == 0)
                {
                    delLast = head;
                }
            }
            // 通过循环计数, 
            temp = temp.next;
        }
        // 循环结束, 找到倒数n位, 删除n位;
        if(delLast != null)
        {
            ListNode deleted = delLast.next;
            delLast.next = deleted.next;
            return head;
        }
        else
        {
            return head.next;
        }
        
    }
}
```