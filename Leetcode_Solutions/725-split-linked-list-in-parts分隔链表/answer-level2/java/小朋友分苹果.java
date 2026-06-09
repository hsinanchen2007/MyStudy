不妨把问题是转为给小朋友分苹果，那么问题就变成了，第几号小朋友分多少个苹果?
![小朋友分苹果.jpg](https://pic.leetcode-cn.com/37e452fc21073b826ef18d4b77e5ebe475af5955375a71e1c70201ebc52779e9-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200217141435.jpg)

但是一次分配看不出规律，所以，我们可以两次分配。先均分，再分剩下的，看看有没有什么规律。
苹果len=10，小朋友k=3，先每人分3个，剩1个，再分，分给第1号小朋友1个，分给第2，3，...，10号小朋友每人0个 。
苹果len=39，小朋友k=7，先每人分5个，剩4个，再分，分给第1，2，3，4号小朋友每人1个，分给第5，...，10号小朋友每人0个 。
苹果len=97，小朋友k=17，先每人分5个，剩12个，再分，分给第1，2，3，...，12号小朋友每人1个，分给13，14，15，16，17号小朋友每人0个。
所以，核心公式为，第几号小朋友拿多少个苹果 = 均分数 + （小朋友号数小于剩余苹果数，拿 1 个，大于拿0个）。
那小朋友数量比这一堆苹果的个数还要多，怎么办?上面的公式也是合适的。
苹果len=3，小朋友k=5，先每人分0个，剩3个，再分，分给第1，2，3号小朋友1个，分给第4，5号小朋友每人0个 。
苹果len=7，小朋友k=9，先每人分0个，剩7个，再分，分给第1，2，3，...，7号小朋友1个，分给第8，9号小朋友每人0个 。
所以跟官方的一样。

1. 遍历一下链表，得到链表的长度（一堆苹果有几个）
2. 采用除法计算出均分数（均分几个苹果），采用取模计算出余数（剩下几个苹果）
3. k次循环，生成一个临时链表，计算核心公式，当前小朋友分多少个苹果size = 均分数 + (小朋友号数 < 剩余苹果数? 1 : 0)
4. size次循环，取出size个ListNode，注意边界，添加到`ListNode[]`数组
5. 返回`ListNode[]`数组

```
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode cur = root;
        int N = 0;
        while (cur != null) {
            cur = cur.next;
            N++;
        }

        int width = N / k, rem = N % k;

        ListNode[] ans = new ListNode[k];
        cur = root;
        for (int i = 0; i < k; ++i) {
            ListNode dummy = new ListNode(0), write = dummy;
            int size = width + (i < rem ? 1 : 0);
            for (int j = 0; j < size; ++j) {
            	write.next = new ListNode(cur.val);
            	write = write.next;
                if (cur != null) cur = cur.next;
            }
            ans[i] = dummy.next;
        }
        return ans;
    }
```





