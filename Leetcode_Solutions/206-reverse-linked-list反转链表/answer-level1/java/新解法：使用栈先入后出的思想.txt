

class Solution {
    public ListNode reverseList(ListNode head) {
        Stack<Integer> stack = new Stack<>();
        ListNode temp = head;
        while (true){
            if(temp == null){
                break;
            }
            stack.push(temp.val);
            temp = temp.next;
        }
        if (!stack.empty()){
            ListNode cur = new ListNode(stack.pop());
            ListNode temp1 = cur;
            while (!stack.empty()){
                temp1.next = new ListNode(stack.pop());
                temp1 = temp1.next;
            }
            return cur;
        }else {
            return null;
        }
    }
}