    
    class Solution {
        public class Node{
            String val;
            List<Node> next;    // 这个应该是多叉树
            public Node(String val) {
                this.val = val;
                next = new ArrayList<>();
            }
        }

        public List<List<String>> res = new ArrayList<>();
        public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
            HashSet<Node> hs = new HashSet<>();
            Node[] nodes = new Node[wordList.size()];
            // 预处理数据，生成一个个树的节点存入数组
            for(int i = 0;i < wordList.size();i++) {
                nodes[i] = new Node(wordList.get(i));
            }
            // 开始BFS，一层层广搜，并且下一层的next连接到当前层节点
            // 这样当我们找到目标值后，一步步next到开始值，这个路径就是结果
            Queue<Node> queue = new LinkedList<>();
            queue.offer(new Node(beginWord));
            // BFS搜出的路径一定是最短的，所有当结果集不为空立马结束，往后的路径就不是最短的了
            while(!queue.isEmpty() && res.isEmpty()) {
                int size = queue.size();
                HashSet<Node> temp = new HashSet<>();
                for(int k = 0;k < size;k++) {  // 当前层都出队找下一层
                    Node node = queue.poll();
                    for(int i = 0;i < nodes.length;i++) {
                        if(!hs.contains(nodes[i]) && distance(nodes[i].val, node.val) == 1) {
                            temp.add(nodes[i]);
                            nodes[i].next.add(node);
                        }
                    }
                }
                // 将遍历出的下一层存入queue，如果到达目标string，就递归这棵树生成结果
                for (Node n : temp) {
                    if(n.val.equals(endWord)) {
                        LinkedList<String> list = new LinkedList<>();
                        dfs(n, list, beginWord);
                        break;
                    }
                    queue.offer(n);
                }
                hs.addAll(temp);  // 两个set合并起来
            }
            return res;
        }

        // 生成结果集
        public void dfs(Node n, LinkedList<String> list, String beginWord) {
            if(n.next.size() == 0) {
                list.addFirst(beginWord);
                res.add(new ArrayList<>(list));
                list.removeFirst();
                return;
            }
            for(int i = 0;i < n.next.size();i++) {
                list.addFirst(n.val);
                dfs(n.next.get(i), list, beginWord);
                list.removeFirst();
            }
        }
        
        // 计算两个字符串间的距离
        public int distance(String s1, String s2) {
            int count = 0;
            for(int i = 0;i < s1.length();i++) {
                if(s1.charAt(i) != s2.charAt(i)) {
                    count++;
                }
            }
            return count;
        }
    }