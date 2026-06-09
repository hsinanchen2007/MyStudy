# 思路：
从倒序转化为正序，先求出链表长度length
倒数第K个节点  即正数第lengthlength-K+1个节点
例如：1 2 3 4 5 6
长度为6  倒数第二个节点 5 正数第6-2+1个节点
![单链表.png](https://pic.leetcode-cn.com/b1fd9c4a0a2a65b7d402e8478076e43e6c7ae5fbf77c2f8a9fa8255f3aa23c8a-%E5%8D%95%E9%93%BE%E8%A1%A8.png)

# 代码实现
```
class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        if(head==null){
            return null;
        }
        int len = 0;
        ListNode tem = head;
        while(tem!=null){  *//第一次遍历得到链表长度*
            tem = tem.next;
            len++;
        }
        ListNode res = head;
        if(k<len&&k>0){   *//从头节点开始遍历，倒数第K个节点  即正数第len-K+1个节点*
            for(int i = 0;i<len-k;i++){
                res = res.next;
            }
        }
        return res;
    }
}
```
