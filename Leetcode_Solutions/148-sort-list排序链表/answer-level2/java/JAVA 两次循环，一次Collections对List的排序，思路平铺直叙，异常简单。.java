/*
两次循环，一次Collections对List的排序，思路平铺直叙
*/


class Solution {
    public ListNode sortList(ListNode head) {
        List<Integer> lis = new ArrayList<Integer>();
        ListNode node = head ;
        while(node!=null){
            lis.add(node.val);
            node=node.next ;
        }
        Collections.sort(lis);
        node = head ;
        int i= 0 ;
        while(node!=null){
            node.val=lis.get(i);
            i++;
            node=node.next ;
        }
        return head ;
    }
}