直接上代码
```
public ListNode reverseKGroup(ListNode node, int k) {
    	// 有效性验证
    	if(node==null||node.next==null||k==1) return node;
    	// 记录段的头尾节点
        ListNode tmp_1 = node;
        ListNode tmp_2 = node;
        // 记录段长度
        int i=0;
        // 遍历到端尾
        // 进行k次步进，tmp_2到达下一个段段头结点
        for(; i<k&&tmp_2!=null; i++) {
            tmp_2=tmp_2.next;
        }
        if(i==k){
            // 当完全遍历时，即说明段长足够k个，可以反转
        	// 调用递归反转方法反转当前段
        	ListNode res = reversePartList(tmp_1, tmp_2);
        	// 连接下一段的反转结果
            // 注意，由于本区段已经反转，所以原本指向段头结点的tmp_1，现在是段尾节点了
        	tmp_1.next = reverseKGroup(tmp_1.next, k);
            return res;
        }else{
        	// 否则直接返回段头结点
            return tmp_1;
        }
    }
    // 递归反转链表
    // 因为这里是反转部分链表，所以需要传入一个终止的尾结点
    public ListNode reversePartList(ListNode node, ListNode tile) {
    	// 当链表到达尾部（下一个节点为实际尾部或尾结点时）
        // 不过本题中，进入这个递归的链表部分不会到达null
    	if(node==null|| node.next==null || node.next==tile) return node;
    	// 递归，反转下一个节点
    	ListNode new_node = reversePartList(node.next, tile);
    	// 递归每一步实际处理逻辑，这一块如果不太理解，建议自己画图走走流程
    	node.next.next = node;
    	// 连接尾结点
    	node.next = tile;
    	// 返回头结点
    	return new_node;
    }
```
