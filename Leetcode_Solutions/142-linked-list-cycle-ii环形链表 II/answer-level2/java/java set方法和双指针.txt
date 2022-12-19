## 一、使用set
- 这个就是把遇到的node都存到set里面，每次添加之前都判断是否已经存在该节点，如果存在，立即返回当前节点，当前节点就是环的入口
```
        if (head == null) return null;

        ListNode temp = head;
        Set<ListNode> set = new HashSet<ListNode>();
        while (temp != null) {
            if (set.contains(temp)) {
                return temp;
            } else {
                set.add(temp);
                temp = temp.next;
            }
        }

        return null;
```

## 二、双指针法
- 像官方讲解一样，分两个阶段
    - 第一阶段：判断是否有环，使用双指针判断，如果fast=null了，说明没有环，return null；如果过程中快慢指针相等了（相遇了），此时的快慢节点都是相遇节点，在第二阶段要用到
    - 第二阶段，看图
        ![fullsizerender.jpg](https://pic.leetcode-cn.com/164f90c2db2ffd203581f775d404cf38a2fa70d9450c0c81be69a2da0f4b58c3-fullsizerender.jpg)
- 代码
    ```
        if (head == null) return null;

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null) {
            slow = slow.next;
            if (fast.next == null) return null;
            fast = fast.next.next;

            if (fast == slow) {
                ListNode encounter = fast;
                while (true){
                    if (encounter==head)return encounter;
                    encounter=encounter.next;
                    head=head.next;
                }
            }
        }
        return null;
```
