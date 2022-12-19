```
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        if(root == null){
            return new ListNode[k];
        }
        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        dummy.next = root;
        int size = 0;
        while(root != null){
            ++size;
            root = root.next;
        }
        ListNode[] nodes = new ListNode[k];
        //if k > size，遍历，每一个位置一个节点，直至没有节点
        if(k >= size){
            for(int i = 0; i < size; ++i){
                root = dummy.next;
                dummy.next = root.next;
                root.next = null;
                nodes[i] = root;
            }
            return nodes;
        }

        //if k < size，就要做切分：
        //每一份都只属于两种类型，而且两种类型的大小只相差1，大的在前面。
        //可以分k份，问题在于如何决定大份和小份分别有多少。
        //大份的数量longAmount为size % k,小份的数量shortAmount为k - longAmount
        //小份的长度shortLength为(size - longAmount) / k,大份的长度longLength=shortLength + 1
        int longAmount = size % k;
        int shortAmount = k - longAmount;
        int shortLength = (size - longAmount) / k;
        int longLength = shortLength + 1;
        int index = 0;
        for(int i = 0; i < longAmount; ++i, ++index){
            root = dummy;
            for(int j = 0; j < longLength; ++j){
                root = root.next;
            }
            nodes[index] = dummy.next;
            dummy.next = root.next;
            root.next = null;
        }
        for(int i = 0; i < shortAmount; ++i, ++index){
            root = dummy;
            for(int j = 0; j < shortLength; ++j){
                root = root.next;
            }
            nodes[index] = dummy.next;
            dummy.next = root.next;
            root.next = null;
        }
        return nodes;
    }
}
```
