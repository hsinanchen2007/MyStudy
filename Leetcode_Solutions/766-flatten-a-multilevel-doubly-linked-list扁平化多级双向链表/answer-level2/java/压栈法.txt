### 解题思路
按照题目思路，应该是node的next应该接在node的child的末尾，以此形成一条完整的无分支双向链表，
以child为优先遍历原始链表，遍历到有孩子的节点，则将该节点的next压入栈中，将child遍历完后，将栈中元素弹出接至末尾，继续往下遍历。
这种思路的空间复杂度在无next只有child的情况下达到最大。
这就是我的思路，比较拙劣，发布供大家交流。
内存消耗 :37.6 MB, 在所有 Java 提交中击败了11.57%的用户
说实话能跑过那个只有child没有next的用例纯属侥幸。
### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/
class Solution {
    public Node flatten(Node head) {
        if(head == null || (head.next == null && head.child == null)) return head;
        Stack<Node> s = new Stack<>();
        s.push(head.next);
        Node tmp = head;
        while(!s.isEmpty()){
            while(tmp.next != null && tmp.child == null){
                tmp = tmp.next;
            }
            if(tmp.child != null){
                if (tmp.next != null) s.push(tmp.next);
                tmp.next = tmp.child;
                tmp.next.prev = tmp;
                tmp.child = null;
            }
            if(tmp.next == null){
                Node tmp1 = s.pop();
                if(s.isEmpty()){
                    tmp.next = null;
                }else{
                    tmp.next = tmp1;
                    tmp.next.prev = tmp;
                }
            }
            tmp = tmp.next;
        }
        return head;
    }
}
```