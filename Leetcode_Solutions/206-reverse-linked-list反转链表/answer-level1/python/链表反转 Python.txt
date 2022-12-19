### 解题思路
此处撰写解题思路

cur.next, prev, cur = prev, cur, cur.next
主要就是遍历一遍链表，改变指针的方向，一直到结束，流程如下所示：
![20190322120002546.png](https://pic.leetcode-cn.com/03fc5df7f4c1a296c21324f3f4bd5aa591f00b669e4ac998cb243292c202a80f-20190322120002546.png)
