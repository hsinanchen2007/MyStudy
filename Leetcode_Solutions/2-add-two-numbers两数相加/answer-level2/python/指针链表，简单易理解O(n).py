# 一. 思路
a. 两条链表相加，返回的结果要求是链表，每次插值的时候都要在链表的尾端添加。
需要一个返回结果的链表res，需要一个指针，每次添加后都指向最后一个节点。
b. 如果有进数(两数想和大于十进1)，下次相加时一起加上。
c. 两条链表长度可能不相等，因此结束循环后，需要判断是否有未遍历完的链表，有则单独遍历，没有则进入下一步。
d. 当两条链表都遍历结束，还需要判断进数是否为0，为0什么也不做，不为0在运行结果的链表尾部添加值为1的节点。
c. 最后可以直接返回res链表  

### 示例: 
a. 
![1.png](https://pic.leetcode-cn.com/ecd8df1327911130e109135722a7e10e323788b0b99467a827f80e5817917a7d-1.png)

b. 
![1 (2).png](https://pic.leetcode-cn.com/57c2a3bfadc4d82a6c988861979d092d28f3aa16c264067e6af10f6ea268894d-1%20\(2\).png)


# 二. 视频
输入链表: 
l1: 2 -> 4 -> 3 -> 1
l2: 5 -> 6 -> 6
![2-两数想和.mp4](074646b8-1321-45bf-84a7-56c706e1849d)

# 三. 源码
```java []
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res = new ListNode();
        ListNode resTemp = res;
        int nextSum = 0;
        int flag = 0; // 标识相加进1
        while(l1 != null && l2 != null){
            int p;
            if(flag == 0){
                p = l1.val + l2.val;
                res.val = p % 10;
                nextSum = p/10;
                flag ++;
            }else{
                p = l1.val + l2.val + nextSum;
                resTemp.next = new ListNode(p % 10);
                resTemp = resTemp.next;
                nextSum = p/10;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        while(l1 != null){
            int p = l1.val + nextSum;
            resTemp.next = new ListNode(p % 10);
            resTemp = resTemp.next;
            nextSum = p / 10;
            l1 = l1.next;
        }
        while(l2 != null){
            int p = (l2.val + nextSum);
            resTemp.next = new ListNode(p % 10);
            resTemp = resTemp.next;
            nextSum = p / 10;
            l2 = l2.next;
        }
        if(nextSum != 0) resTemp.next = new ListNode(nextSum);
        return res;
    }
}
```
```python []
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        res = ListNode(0);
        resTemp = res
        flag = 0
        nextSum = 0
        while l1 != None and l2 != None:
            if flag == 0:
                p = l1.val + l2.val
                res.val = p % 10
                nextSum = int(p / 10)
                flag += 1
            else:
                p = l1.val + l2.val + nextSum
                resTemp.next = ListNode(p%10)
                resTemp = resTemp.next
                nextSum = int(p / 10)
            l1 = l1.next
            l2 = l2.next
        while l1:
            p = l1.val + nextSum
            resTemp.next = ListNode(p%10)
            resTemp = resTemp.next
            nextSum = int(p / 10)
            l1 = l1.next
        while l2:
            p = l2.val + nextSum
            resTemp.next = ListNode(p%10)
            resTemp = resTemp.next
            nextSum = int(p / 10)
            l2 = l2.next
        if nextSum != 0:
            resTemp.next = ListNode(1)
        return res
```


# 四. 复杂度
时间复杂度: O(n)，n为max(n, m), 指两条链表中最长那一条。
空间复杂度: O(n), n或n + 1，n为最长链表的长度。
运行时间: 
100%靠运气，不过90+%还是没问题的，另外用python实现速度较慢，可能是我技术原因。
![QQ截图20200329181056.png](https://pic.leetcode-cn.com/579cb8c8a2679916f799953601dabf29d5a8508519e202964beadcca2738ff45-QQ%E6%88%AA%E5%9B%BE20200329181056.png)


