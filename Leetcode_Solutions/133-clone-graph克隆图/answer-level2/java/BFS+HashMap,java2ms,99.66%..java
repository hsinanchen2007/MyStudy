![搜狗截图20191111233704.png](https://pic.leetcode-cn.com/26cf37fa58fdb0c985ea2b57026d2e51bc68e10113c54f49adcf5817299e78f7-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20191111233704.png)
```
/*首先，深复制指的是完完全全复制一遍，所有内容都和原先的无关，复制后两者完全独立。
使用HashMap<Integer,Node>存储new过的新结点，通过val映射。
使用广度优先搜索，队列里存放还没有处理好(处理好指结点的neighbors已全部复制好)的原图中的结点的引用。
*/
class Solution {
    HashMap<Integer,Node> hash = new HashMap<Integer, Node>(); //存储new过的新结点
    ArrayDeque<Node> que = new ArrayDeque<Node>();  //广搜辅助队列，存储原图中没处理好的结点的引用
    Node head; //克隆图的引用
    public Node cloneGraph(Node node) {
        if(node == null) return null;
        que.addLast(node);
        while(!que.isEmpty()){
            Node t = que.pollFirst(); //t表示未处理的结点(原图中结点的引用)
            Node nd = null; //nd表示当前要处理(处理指往它的neighbors加结点)的结点,会被加入新图中
            if(!hash.containsKey(t.val)){   //如果当前val的结点不在hash中，说明没有new过
                nd = new Node(t.val,new ArrayList<Node>());
                hash.put(t.val, nd);
            }else nd = hash.get(t.val); //否则new过，直接取出

            if(hash.size() == 1) head = nd; //确定克隆图的引用

            List<Node> t_list = t.neighbors;
            for(Node n : t_list){
                if(!hash.containsKey(n.val)){   //与t结点相邻的结点不在hash中(没new过)
                    que.addLast(n); //将此结点(原图中结点的引用)加入队列
                    Node newNode = new Node(n.val, new ArrayList<Node>());
                    nd.neighbors.add(newNode);  //将新new的结点加入nd的neighbors
                    hash.put(n.val,newNode);    //放入hash表明已经new过
                }else{
                    nd.neighbors.add(hash.get(n.val));  //否则，从hash中取出，加入nd的neighbors
                }
            }
        }
        return head;
    }
}
```
