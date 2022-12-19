特定深度分组很明显了，用层次遍历，层次遍历也很明显了，用队列，主要是返回结果需要用数组存储，而一开始又不知道树的深度也就无从知道需要的数组大小，可以先进行一次深度优先求树的深度，但实在是不如直接用list暂存，最后在复制到数组中，代码如下，有注释，应该不难懂
```
class Solution {
    public ListNode[] listOfDepth(TreeNode tree) {
        List<ListNode> temp = new LinkedList<>(); // 用来存储结果的临时List，避免数组的大小初始化
        ListNode[] result; // 结果数组
        Queue<TreeNode> nodeQueue = new LinkedList<>(); // 层次遍历使用的队列
        nodeQueue.offer(tree);
        while(!nodeQueue.isEmpty()) { // 当队列为空时结束循环
            int amount = nodeQueue.size();
            ListNode lHead = new ListNode(0); // 每一层的链表当前节点
            ListNode finalHead = lHead; // 每一层的链表头节点
            while(amount > 0) { // 遍历完一层时结束循环
                TreeNode currNode = nodeQueue.poll();
                ListNode lNode = new ListNode(currNode.val);
                lHead.next = lNode; // 串起链表
                lHead = lHead.next; // 头节点后移
                if(currNode.left != null) { // 将左子节点加入到队列中
                    nodeQueue.offer(currNode.left);
                }
                if(currNode.right != null) { // 将右子节点加入到队列中
                    nodeQueue.offer(currNode.right);
                }
                amount--;
            }
            temp.add(finalHead);
        }
        result = new ListNode[temp.size()]; // 初始化结果数组的大小
        for(int i = 0; i < temp.size(); i++) { // 将链表List放到结果数组中
            result[i] = temp.get(i).next;
        }
        return result;
    }
}
```

