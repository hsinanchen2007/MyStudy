class Solution {
    public int[] reversePrint(ListNode head) {
        Stack<Integer> s = new Stack<Integer>();
        while(head!=null){
            s.push(head.val);
            head=head.next;
        }
        int[] arr = new int[s.size()];
        int index = 0;
        while(s.size()>0){
            arr[index++]=s.pop();
        }
        return arr;
    }
}