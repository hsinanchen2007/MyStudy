### 解题思路
小根堆用于存放资本，大根堆用于存放收益。
![image.png](https://pic.leetcode-cn.com/e7316e5fbd8a08c71afce9dbf39e5493b22fd0e1fe0fb74a70d9b451714eca52-image.png)


### 代码

```java
class Solution {
    //贪心策略：从W>Capital[i]中收益最大的那个开始做项目
    public class Node{
        int p;
        int c;
        public Node(int p, int c){
            this.p = p;
            this.c = c;
        }
    }
    public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
        Node[] nodes = new Node[Profits.length];
        for(int i = 0; i < Profits.length; i++){
            nodes[i] = new Node(Profits[i], Capital[i]);
        }
        PriorityQueue<Node> minCosts = new PriorityQueue<>(new Comparator<Node>(){
            public int compare(Node n1, Node n2){
                return n1.c - n2.c;
            }
        });
        PriorityQueue<Node> maxProfits = new PriorityQueue<>(new Comparator<Node>(){
            public int compare(Node n1, Node n2){
                return n2.p - n1.p;
            }
        });
        for(int i = 0; i < Profits.length; i++){
            minCosts.add(nodes[i]);
        }
        for(int i = 0; i < k; i++){
            while(!minCosts.isEmpty() && minCosts.peek().c <= W){
                maxProfits.add(minCosts.poll());
            }
            if(maxProfits.isEmpty()){
                return W;
            }
            W = W + maxProfits.poll().p;
        }
        return W;
    }
}
```