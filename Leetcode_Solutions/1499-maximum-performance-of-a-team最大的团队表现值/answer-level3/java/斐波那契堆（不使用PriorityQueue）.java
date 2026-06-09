别的不想多说，在很多人的代码里，使用了PriorityQueue来进行获取最小值，而我最近刚看了斐波那契堆，正好实战一下。

PriorityQueue只是建个数组，而使用斐波那契堆要建一堆的对象来保存数据，所以开始我是比较不自信的，建对象要时间啊。
但是提交之后，耗时54ms，斐波那契堆，插入o(1)，名不虚传。

```

    long NN = 1000000;

    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        if (k == 0) {
            return 0;
        }
        long ans = 0;
        if (k == 1) {
            for (int i = 0; i < n; i++) {
                ans = Math.max(ans, ((long) speed[i]) * efficiency[i]);
            }
            return (int) (ans % 1000000007);
        }
        Long[] effSpee = new Long[n];
        for (int i = 0; i < n; i++) {
            effSpee[i] = efficiency[i] * NN + speed[i];
        }
        Arrays.sort(effSpee, new Comparator<Long>() {
            @Override
            public int compare(Long o1, Long o2) {
                return o2.compareTo(o1);
            }
        });
        int nspeed = (int) (effSpee[0] % NN);
        Node min = new Node(nspeed);
        min.left = min;
        min.right = min;
        //建堆
        H h = new H();
        h.min = min;
        long allNum = nspeed;
        ans = (effSpee[0] / NN) * allNum;
        for (int i = 1; i < n; i++) {
            nspeed = (int) (effSpee[i] % NN);
            long v = (effSpee[i] / NN);
            if (i >= k) {
                if (nspeed <= h.min.val) {
                    continue;
                } else {
                    allNum -= h.min.val;
                    //移除最小
                    h.rewmovMin();
                }
            }
            allNum += nspeed;
            //插入
            h.add(new Node(nspeed));
            ans = Math.max(ans, v * allNum);
        }
        return (int) (ans % 1000000007);

    }

    Node[] nodes = new Node[20];

    class H {
        Node min;

        public void rewmovMin() {
            Node node = null;
            //移除min，把min的child加入到链表中
            if (min.left == min) {
                node = min.child;
            } else {
                node = min.left;
                node.right = min.right;
                node.right.left = node;
                if (min.degree > 0) {
                    node.right.left = min.child.left;
                    min.child.left.right = node.right;
                    node.right = min.child;
                    min.child.left = node;
                }
            }
            //上面的操作，就是把可能是最小的值都放在最上层的链表里
            Node nNext = node.right;
            min = node;
            //循环遍历链表
            while (nNext != node) {
                if (nNext.val < min.val) {
                    min = nNext;
                }
                Node thisNode = nNext;
                nNext = thisNode.right;
                build(thisNode);
            }
            build(node);
            //以上操作，保证链表没有相同degree的树结构
            for (int i = 0; i < nodes.length; i++) {
                //清空
                nodes[i] = null;
            }
        }

        private void build(Node thisNode) {
            //同等degree合并
            while (nodes[thisNode.degree] != null) {
                Node addNode = nodes[thisNode.degree];
                nodes[thisNode.degree] = null;
                if (addNode.val <= thisNode.val) {
                    //小的做父节点
                    remove(thisNode);
                    if (addNode.child == null) {
                        thisNode.left = thisNode;
                        thisNode.right = thisNode;
                        addNode.child = thisNode;
                    } else {
                        addRight(addNode.child, thisNode);
                    }
                    thisNode = addNode;
                } else {
                    remove(addNode);
                    if (thisNode.child == null) {
                        addNode.left = addNode;
                        addNode.right = addNode;
                        thisNode.child = addNode;
                    } else {
                        addRight(thisNode.child, addNode);
                    }
                }
                thisNode.degree++;
            }
            nodes[thisNode.degree] = thisNode;
        }

        //把node加到N的左边
        private void addRight(Node N, Node node) {
            node.right = N.right;
            N.right.left = node;
            node.left = N;
            N.right = node;
        }

        //把node从链中删除
        private void remove(Node node) {
            node.left.right = node.right;
            node.right.left = node.left;
        }

        //添加
        public void add(Node node) {
            addRight(min, node);
            if (node.val < min.val) {
                min = node;
            }
        }
    }

    class Node {
        int degree = 0;
        int val;
        Node child;
        Node left;
        Node right;

        public Node(int nspeed) {
            val = nspeed;
        }
        //四个操作用不到parent
    }
```
