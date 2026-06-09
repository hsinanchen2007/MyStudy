[Leetcode-Java(200+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_82_deleteDuplicates.java)

```java
    /**
     * 解题思路：
     * 对于链表类型的题目，就是按照next的指针进行遍历，找到题目要求
     * 1、定义四个指针:
     *  一个头结点的前置虚拟指针==>方便返回结果的头结点,
     *  一个前置指针==>方便切断遍历相同节点，
     *  一个遍历指针，
     *  一个搜寻相同指针的尾结点==>定位结尾
     * 2、找到满足条件的，将前置指针的next指向尾结点的next
     *
     * 执行用时 :1 ms, 在所有 java 提交中击败了99.26%的用户
     * 内存消耗 :37 MB, 在所有 java 提交中击败了57.65%的用户
     *
     * @param head
     * @return
     */
    public ListNode deleteDuplicates(ListNode head) {
        //头结点的前置虚拟指针
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        //前置指针
        ListNode preNode = head;
        //遍历指针
        ListNode node = head;
        //尾结点指针
        ListNode endNode ;
        while (node != null ) {
            endNode = node.next;
            while (endNode != null && endNode.val == node.val) {
                endNode = endNode.next;
            }
            if (node.next == endNode){
                //不是重复的
                preNode = node;
            }else{
                //存在重复的
                preNode.next = endNode;
                if (dummy.next == node){
                    dummy.next = endNode;
                }
            }
            node = endNode;
        }

        return dummy.next;
    }
```