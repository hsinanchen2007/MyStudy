### 解题思路 BFS
# BFS的八股格式：
1.申请队列
2.队列初始化
3.while(队列不为空){
    3.1从队列头取出元素
    3.2对该元素进行处理，并将满足条件的其他元素加入队列
}
### BFS版本1：
申请一个同样的队列layerQueue用来把同步保存当前正在处理的节点处于第几层
例如本题目[3,9,20,null,null,15,7]：
- queue：3 layerQueue：1
- queue：9 20 layerQueue：2 2
- queue：20 layerQueue：2
- queue：15 17 layerQueue：3 3

```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new LinkedList<List<Integer>>();

        int layer = 1;//指示当前处理的node在第几层，默认root是第一层

        Queue<TreeNode> queue = new LinkedList<TreeNode>();//1.申请队列，存储node
        Queue<Integer> layerQueue = new LinkedList<Integer>();//存储节点是第几层
        
        queue.offer(root);//2.队列初始化
        layerQueue.offer(new Integer(layer));

        List<Integer> list = new LinkedList<Integer>();//存储每一层的list列表

        while(queue.peek() != null){
            TreeNode node = queue.poll();
            int processingNodeLayer = layerQueue.poll().intValue();//当前正在处理的node的层数

            if(processingNodeLayer == layer){//同一个层
                list.add(node.val);//继续向列表里假如元素
            }else{//不是同一个层了
                ans.add(list);//将列表加入ans
                list = new LinkedList<Integer>();//重新申请列表
                list.add(node.val);//列表加入这层的数据
                layer = processingNodeLayer;//更新历史处理的层数
            }

            if(node.left != null){
                queue.offer(node.left);
                layerQueue.offer(new Integer(processingNodeLayer + 1));
            }
            if(node.right != null){
                queue.offer(node.right);
                layerQueue.offer(new Integer(processingNodeLayer + 1));
            }
        }

        if(root != null){//***这一步很重要***，最后一层的list还没来得及加入ans，所以需要在此手动加入ans
            ans.add(list);
        }
        return ans;
    }
}
```

### BFS优化后的版本2：
可以发现queue加入元素后，此时队列中的元素就是该层的全部元素
例如本题目[3,9,20,null,null,15,7]：
- queue：3 ，队列长度为1，循环取出队列元素3加入列表1，同时把每个元素的左右孩子加入队列，队列变为queue：9 20 
- queue：9 20 ，队列长度为2，循环取出队列元素9 20加入列表2，同时把每个元素的左右孩子加入队列，队列变为queue：15 17 
- queue：15 7，...
```java
public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new LinkedList<List<Integer>>();
        Queue<TreeNode> queue = new LinkedList<TreeNode>();//1.申请队列，存储node
        queue.offer(root);//2.队列初始化

        while(queue.peek() != null){//3.队列不为空
            int elementNum = queue.size();
            List<Integer> list = new LinkedList<Integer>();
            while(elementNum-- > 0){
                TreeNode node = queue.poll();
                if(node.left != null){
                    queue.offer(node.left);
                }
                if(node.right != null){
                    queue.offer(node.right);
                }
                list.add(node.val);
            }
            ans.add(list);
        }

        return ans;
```