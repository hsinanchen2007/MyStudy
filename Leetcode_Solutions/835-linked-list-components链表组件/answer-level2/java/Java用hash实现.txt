class Solution {
    public int numComponents(ListNode head, int[] G) {
        int R = 0;
        int[] hash  = new int[10000];
        int gLen = G.length;

        for (int i = 0; i < gLen; i++) {
            hash[G[i]]++;
        }

        ListNode tmp = head;
        while (tmp != null) {
            int index = tmp.val;
            
            while (hash[index] > 0) {
                hash[index]--;
                R++;
                
                /* 头子每减少一次，就把以此开头的顺序子集删一次，直到中断了无法连接，本次集合才算是结束，然后再回到头节点，继续处理，直到头节点次数为0 ，才表示此头节点开始的子集不会再存在了 */
                ListNode go = tmp.next;
                while (go != null) {
                    if (hash[go.val] == 0) {
                        break;
                    }
                    hash[go.val]--;
                    go = go.next;
                }
            }
            
            tmp = tmp.next;
        }
        
        return R;
    }
}