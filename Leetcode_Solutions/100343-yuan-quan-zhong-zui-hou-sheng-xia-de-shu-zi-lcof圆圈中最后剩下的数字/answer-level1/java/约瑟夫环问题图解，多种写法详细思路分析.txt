### 解法一：比较直观的解法，使用 LinkedList
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;经典的约瑟夫环问题，我们首先能想到的就是模拟，我们先把所有的数加进一个链表中，只要链表的长度不为 $1$，那我们就要不断循环，如果不是要剔除的，把前一个添加进链表尾部即可，时间复杂度 $O(nm)$，看了下数据， $n= 10^5,m=10^6$，必定会 $TLE$。写了试了一下，确实

```java
class Solution {
    public int lastRemaining(int n, int m) {
        LinkedList<Integer> list = new LinkedList<>();
        // 全部加进去
        for (int i = 0; i < n; i++) {
            list.add(i);
        }
        // 只要链表长度不为 1，就不断循环
        while (list.size() != 1) {
            for (int i = 0; i < m; i++) {
                Integer pre = list.pollFirst();
                if (i != m - 1) {
                    list.add(pre);
                }
            }
        }
        return list.pollFirst();
    }
}
```

### 解法二：循环链表解法
首先创建循环链表，节点值从 $0～n-1$，再调用我们的方法即可，也是**超时**的
```java
class Solution {
    public int lastRemaining(int n, int m) {
        ListNode pre = create(n);
        ListNode head = pre.next;
        while (head.next != head) {
            for (int i = 0; i < m - 1; i++) {
                pre = head;
                head = head.next;
            }
            // 此时head指向要被删除的节点
            head = head.next;
            pre.next = head;
        }
        return pre.val;
    }

    // 创建循环链表，节点的 val 从 0 到 n-1，返回的是 head 的前驱节点，方便删除
    private ListNode create(int n) {
        ListNode head = new ListNode(0);
        ListNode cur = head;
        for (int i = 1; i < n; i++) {
            ListNode node = new ListNode(i);
            cur.next = node;
            cur = cur.next;
        }
        cur.next = head;
        return cur;
    }
}

class ListNode{
    int val;
    ListNode next;

    public ListNode(int val) {
        this.val = val;
        next = null;
    }
}
```

### 解法三：数学思路

**第一轮**：$n$ 个数字的编号如下：
![image.png](https://pic.leetcode-cn.com/ab6bb426edd9ab361d8cf48e98f38dd86898421b39d5609524083cbd5f05c3b0-image.png)



第一个被剔除的数字是是$（m-1）\%\  n$，剔除完结果如下：
![image.png](https://pic.leetcode-cn.com/2a4d9b17c565e67882dde99f9d88f022ccb87b42d677817a75bb9e325618a8c9-image.png)


**第二轮**：那就是从 $m$ 开始啦，我们给它重新排个队，再编个号：
![image.png](https://pic.leetcode-cn.com/381ebcd3191ff0c42fb8799983a33977e8a9798f098a3352d98612798598839a-image.png)

问题规模变为 $n-1$ 个数字，这里面第 $m-1$ 个被剔除。那么这个剔除的有俩编号，一个手机在**当前**这一轮的编号为 $(m-1) \% (n-1)$，而对于**第一轮**来讲，这个被剔除数字的编号其实为 $((m-1) \%(n-1)+m) \%n$ （您不用管这个公式）。如此下去，直到最后只剩一个，也就是只剩 $0$ 号位。
![image.png](https://pic.leetcode-cn.com/e1bca8e5133cc2af4cc2f44132a8cccc3c5e76a7d80dc4436f2eced1d286dbd5-image.png)
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; 我们想到知道，它在第一轮中的编号是什么，这个也就是结果。因为相邻两轮之间，被剔除的这个数字在当前轮的编号是知道的，最后一轮就是0，我们可以利用这个编号倒推，利用最后一轮的求出它在倒数第二轮的编号，利用倒数第二轮的编号求出它在倒数第三轮的编号，以此类推。

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; $n$ 个数字就是 $n$ 个人，我们用函数 $f(i)$ 表示当前人数为 $i$ 的时候留下来的的最后一个人的位置（暂且这么说吧），那么$f(1) = 0$，再推一步，还剩两个的时候，第 $m-1$ 个要被剔除，要剔除哪个呢？

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;现在我们知道的是 ，也就是当只有一个人的时候，被剔除人的下标为 $0$（我们知道他是不会被剔除的），它在上一轮中是第 $m+1$ 个（第 $m$ 个下标为 $m-1$，被删除），逃过了一劫，因为在它之前的一步，第 $m-1$ 个是被剔除的，所以在倒数第二步，就是在最后一步的基础上加 $m$，也就是对于最后一轮这个要被剔除的，它在上一轮没被剔除，它在上一轮的编号是多少，我们给它求出来，即： 
$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~f(2) = f(1) + m$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;但这里还要记得取余哦
$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~f(2) = (f(1) + m) \% 2$

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;接下来我们只需要利用公式往上推即可，因为可能会超出当前个数 $i$ 的范围，所以边计算边取模即可，可以得到递推式：
$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~f(i) = (f(i-1)+m)\% \ i$

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;写的时候，$n$ 个数字，要剔除 $n-1$ 个，循环 $n-1$ 次，$i$ 从 $2$ 开始直到 $n$ 结束







### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        // 存活的最后一个人的位置
        int last = 0;  
        for (int i = 2; i <= n; i++) {
            last = (last + m) % i;
        }
        return last;
    }
}
```
**递归写法**
```java
class Solution {
    public int lastRemaining(int n, int m) {
        if (n == 1) {
            return 0;
        }
        if (n == 2) {
            if ((m & 1) == 1) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return (lastRemaining(n - 1, m) + m) % n ;
        }
    }
}
```
在写的过程中可能有一些错误，希望大家指正，我会及时修改，谢谢您的观看。