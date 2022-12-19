先把值加入链表、重新构建

![image.png](https://pic.leetcode-cn.com/d4d97b03aa4fd23e8caa182f7d2350629b9394e6bf0ac136c04954e53583d509-image.png)

```
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null)return null;
        List<Integer> list = new ArrayList<>();
        while(head != null){
            list.add(head.val);
            head = head.next;
        }
        if(list.size() == 1)return new ListNode(list.get(0));
        
        for(int i = 0; i < list.size(); i += 2){
            if(i == list.size() - 1)break;
            int temp = list.get(i);
            list.set(i,list.get(i+1));
            list.set(i+1,temp);
        }
                
        ListNode p = new ListNode(list.get(0));
        ListNode q = p;
        for(int i = 1; i < list.size(); i++){
            p.next = new ListNode(list.get(i));
            p = p.next;
        }
        return q;
    }
}
```
