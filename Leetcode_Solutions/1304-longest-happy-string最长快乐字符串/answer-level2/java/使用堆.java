```
    class Node{
        char c;
        int count;

        public Node(char c, int count) {
            this.c = c;
            this.count = count;
        }
    }
    public String longestDiverseString(int a, int b, int c) {

        Node[] nodes = {new Node('a', a), new Node('b', b), new Node('c', c)};
        PriorityQueue<Node> heap = new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o2.count - o1.count;
            }
        });
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < nodes.length; i++) {
            if (nodes[i].count > 0) {
                heap.add(nodes[i]);
            }
        }
        HashMap<Character, Integer> hashMap = new HashMap<>();
        while (!heap.isEmpty()) {
            Node peek = heap.poll();
            //检查数量最多的这个字符的前缀
            int ori = hashMap.getOrDefault(peek.c, 0);
            if (ori < 2) {
                res.append(peek.c);
                peek.count--;
                hashMap.clear();
                hashMap.put(peek.c, ori + 1);
                if (peek.count > 0) {
                    heap.add(peek);
                }
            } else {
                //看数量第二多的,没有就说明结束了
                Node peek2 = heap.poll();
                if (peek2 == null) {
                    break;
                }
                res.append(peek2.c);
                int o2 = hashMap.getOrDefault(peek2.c, 0);
                peek2.count--;
                hashMap.clear();
                hashMap.put(peek2.c, o2 + 1);
                if (peek2.count > 0) {
                    heap.add(peek2);
                }
                heap.add(peek);
            }
        }

        return res.toString();
    }

```
