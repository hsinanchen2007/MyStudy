```
class Solution {
        private Map<Integer,Node> nodeMap = new HashMap();
        private Map<Node,Node> minNodeMap = new HashMap();
        //返回值
        int[] res = null;
        public int[] loudAndRich(int[][] richer, int[] quiet) {

            //构建链表结构,并保存数据到map
            for(int i=0;i<richer.length;i++){
                int curr = richer[i][1];
                Node node = getNodeIfAbsent(curr,quiet);
                int prev = richer[i][0];
                Node prevNode = getNodeIfAbsent(prev,quiet);
                node.setPrev(prevNode);
            }
            //返回值
            res = new int[quiet.length];
            Arrays.fill(res,-1);
            for(int j=0;j<quiet.length;j++){
                Node currNode = nodeMap.get(j);
                if(currNode == null){
                    res[j] = j;
                    continue;
                }
                //找出前驱中最安静的人
                currNode =dfsMinQuiet(currNode);
                res[j] = currNode.person;

            }
            return res;
        }

        //递归找出前驱中最安静的人
        private Node dfsMinQuiet(Node currNode){
            //map做记忆
            if(minNodeMap.containsKey(currNode)){
                return minNodeMap.get(currNode);
            }
            List<Node> prev = currNode.prev;
            if(prev.isEmpty()){
                return currNode;
            }
            Node minNode=currNode;
            for (Node node :prev){
                Node node1 = dfsMinQuiet(node);    
                minNodeMap.put(node,node1);           
                if(node1.quietVel < minNode.quietVel){
                    minNode = node1;
                }
            }
            return minNode;

        }

        //保存数据到map中
        private Node getNodeIfAbsent(int val,int[] quiet){
            if(nodeMap.containsKey(val)){
                return nodeMap.get(val);
            }
            Node node = new Node(val,quiet[val]);
            nodeMap.put(val,node);
            return node;
        }

        //拥有前驱的链表
        class Node{
            //比自己有钱的人列表
            List<Node> prev = new ArrayList();
            //当前人
            Integer person;
            //安静值
            Integer quietVel;
            Node(int person,int quietVel){
                this.person = person;
                this.quietVel = quietVel;
            }
            void setPrev(Node node ){
                prev.add(node);
            }

        }
}
```
