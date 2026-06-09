```
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode virHead = new ListNode(0), p = virHead; // 虚拟表头
        int k = lists.length;
        if(k<=0) return null;
        ListNode[] minHeap = new ListNode[k];

        for(int i=0;i<k;i++){
            if(lists[i]!=null){
                minHeap[i] = lists[i];
            }else{
                //若节点为空，则塞进一个最大数的节点，它会被淘汰在最小堆的叶子节点中不会被访问到
                minHeap[i] = new ListNode(Integer.MAX_VALUE); 
            }
        }
        // 构建最小堆
        for(int i=k/2-1;i>=0;i--){
            adjustMinHeap(minHeap,i,k);
        }
        while(true){
            if(minHeap[0].val==Integer.MAX_VALUE) break; //当最小堆顶是最大时则跳出
            ListNode node = minHeap[0];

            p.next = node;
            p = p.next; // 连接，推进

            if(node.next!=null){ // 进堆
                minHeap[0] = node.next;
                adjustMinHeap(minHeap,0,k);
            }else{
                minHeap[0] = new ListNode(Integer.MAX_VALUE); // 为空塞最大值
                adjustMinHeap(minHeap,0,k);
            }
        }
        return virHead.next;

    }
    // 最小堆调整
    private void adjustMinHeap(ListNode[] nums,int i,int length){
        ListNode temp = nums[i];
        for(int k=2*i+1;k<length;k=k*2+1){
            if(k+1<length&&nums[k+1].val<nums[k].val) k++;
            if(nums[i].val>nums[k].val){
                nums[i] = nums[k];
                i=k;
            }
            nums[i] = temp;
        }
    }
}
```
复杂度O(Nlogk)，但是有一个问题：为了方便用了MAX_VALUE代替了那些空节点，如果链表中本来就刚好有这个值的=。= 
当然可以通过加一个计数来维护。