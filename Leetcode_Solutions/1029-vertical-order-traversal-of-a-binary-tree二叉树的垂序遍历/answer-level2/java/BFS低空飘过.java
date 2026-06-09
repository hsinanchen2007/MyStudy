    class Cor{
        public final int x;
        public final int y;

        public Cor(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    class Tuple implements Comparable{
        public final Cor      cor;
        public final TreeNode node;

        public Tuple(Cor cor, TreeNode node){
            this.cor = cor;
            this.node = node;
        }

        @Override
        public int compareTo(Object o) {
            Tuple tuple =  (Tuple)o;
            if (this.cor.x == tuple.cor.x){
                if (this.cor.y == tuple.cor.y) {
                    return this.node.val - tuple.node.val;
                } else {
                    return -(this.cor.y - tuple.cor.y);
                }
            } else { //x1!=x2
                return this.cor.y - tuple.cor.y;
            }
        }
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>>  res = new ArrayList<>();
        List<Tuple> posList = new ArrayList<>();

        if (root == null) return res;

        Queue<Tuple> queue =  new LinkedList<>();
        Tuple rootTuple = new Tuple(new Cor(0,0), root);
        queue.offer(rootTuple);
        posList.add(rootTuple);

        while (!queue.isEmpty()){
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Tuple tuple = queue.poll();
                if (tuple.node.left!=null){
                    Tuple left  = new Tuple(new Cor(tuple.cor.x - 1, tuple.cor.y - 1), tuple.node.left);
                    queue.offer(left);
                    posList.add(left);
                }
                if (tuple.node.right !=null) {
                    Tuple right = new Tuple(new Cor(tuple.cor.x + 1, tuple.cor.y - 1), tuple.node.right);
                    queue.offer(right);
                    posList.add(right);
                }
            }
        }

        Collections.sort(posList);

        Map<Integer, List<Tuple>> temp = posList.stream().collect(Collectors.groupingBy(tuple -> tuple.cor.x));

        TreeMap<Integer, List<Tuple>> treeMap = new TreeMap<>(temp);

        treeMap.forEach((k,v)->{
            Collections.sort(v);
            List<Integer> l = v.stream().map(t -> t.node.val).collect(Collectors.toList());
            res.add(l);
        });

        return res;
    }