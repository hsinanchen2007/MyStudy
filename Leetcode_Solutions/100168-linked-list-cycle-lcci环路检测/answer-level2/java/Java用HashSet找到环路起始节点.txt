### 解题思路
1. 判断是否存在环路，用的是Hash表来判断，不太理解的可以跳转到141题
2. 找到形成环路的那个节点

其实理解了思路这两步就可以合二为一，因为**用Hash表找到第一次重复的节点就是形成环路的起始节点**

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null){ //链表为空则返回null
            return null;
        }
        Set<ListNode> hashSet = new HashSet<ListNode>(); //创建HashSet
        ListNode curNode = head;  //创建临时节点
        while(!hashSet.contains(curNode)){   //一旦找到hash表中存在的节点，就结束循环
            if(curNode == null){    //如果当前节点是null，则表示找到了尾节点，即没有环
                return null;
            }
            hashSet.add(curNode);   //将节点添加到HashSet中
            curNode = curNode.next;  //移动节点
        }
        return curNode;   //中途结束循环的节点被保存在curNode中，就是我们要找的节点
    }
}
```