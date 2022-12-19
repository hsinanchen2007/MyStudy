### 解题思路
解析见下面代码部分。
Collections不能作用于[],这个捣鼓了好久，python写习惯了，以为[]也可以修改。。。

### 代码
使用直接暴力排序
步骤为：
1-1-2-===
1-2-4-===
2-3-4-===
3-4-6-===
4-4-6-===
4-6-null -===
5-6-null -===
6-null -null -===
null -null -null -===
注意这里的[]不能删除元素，所以直接设置为null，将null尽量放后面

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
    public int cmp(ListNode n1,ListNode n2) {
        return n1.val-n2.val;
    }

    public ListNode mergeKLists(ListNode[] lists) {
        ListNode node = new ListNode(-1);
        ListNode result = node;

        while(true) {
            //排序
            Arrays.sort(lists,new Comparator<ListNode>(){
                @Override
                public int compare(ListNode n1,ListNode n2) {
                    if (n1 == null) {
                        return 1;
                    }
                    if (n2 == null) {
                        return -1;
                    }
                    return n1.val-n2.val;
                }
            });
            //调试
            // for(ListNode tmp : lists) {
            //     if(tmp != null) System.out.print(tmp.val +"-");
            //     else System.out.print("null -");
            // }
            // System.out.println("===");
            
            //取出最小的ists[0]
            if(lists.length>0) {
                if(lists[0] == null) {
                    break;
                }
                node.next = lists[0];
                lists[0] = lists[0].next;
                node = node.next;
                node.next = null;
                
            } else {
                break;
            }

        }
        return result.next;

    }
}
```
很显然，每次取最小值，使用小顶堆进行优化

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int cmp(ListNode n1,ListNode n2) {
        return n1.val-n2.val;
    }

    public ListNode mergeKLists(ListNode[] lists) {

        ListNode node = new ListNode(-1);
        ListNode result = node;

        //建立并初始化小顶堆
        PriorityQueue<ListNode> pq = new PriorityQueue<>(new Comparator<ListNode>(){
                @Override
                public int compare(ListNode n1,ListNode n2) {
                    return n1.val-n2.val;
                }
            });
        
        for(ListNode tmp :lists) {
            if(tmp!=null)pq.add(tmp);
        }

        while(pq.size()>0) {
            
            //取出堆顶元素
            ListNode top = pq.poll();
            if(top.next!=null) {
                pq.add(top.next);
            }
            top.next = null;
            node.next = top;
            node = node.next;

        }
        return result.next;

    }
}
```

