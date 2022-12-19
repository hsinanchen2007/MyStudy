### 解题思路
从0开始出发,如果在第i哥加油站停了,说明在0~i之间出发都是不行的,下一次从i+1出发,考虑好边界值判断.

### 代码

```java
class Solution {
    class Node {

        int index;

        int gas;

        int cost;

        Node next;

        public Node(int index, int gas, int cost) {
            this.index = index;
            this.gas = gas;
            this.cost = cost;
        }
    }

    public int canCompleteCircuit(int[] gas, int[] cost) {
        Map<Integer, Node> nodeMap = new HashMap<>();
        Node root = new Node(0, gas[0], cost[0]);
        nodeMap.put(0, root);
        Node preNode = root;
        for (int i = 1; i < gas.length; i++) {
            Node node = new Node(i, gas[i], cost[i]);
            nodeMap.put(i, node);
            preNode.next = node;
            preNode = node;
        }
        preNode.next = root;

        boolean[] circle = new boolean[1];
        int start = 0;
        while (!circle[0]) {
            int end = canCircuit(nodeMap.get(start), circle, gas.length-1);
           if ((end == gas.length - 1 ) && !circle[0]) {
                return -1;
            }else   if (end == start && circle[0]) {
                return start;
            }  
            else {
                start = end + 1;
            }
        }
        return -1;
    }

    public int canCircuit(Node node, boolean[] circle, int l) {
        int begin = node.index;
        int curGas = node.gas - node.cost;
       
        while (curGas >= 0) {
             if (node.index == l) {
                circle[0] = true;
            }
            node = node.next;
            if (node.index == begin) {
                return begin;
            }
            if (node.index == l) {
                circle[0] = true;
            }
            curGas += node.gas - node.cost;
        }
        return node.index;
    }
}
```