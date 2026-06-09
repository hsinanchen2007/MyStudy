首先处理一下数据，原题给的是字符串类型"1-401--349---90--88"，我把它转换为数组，这种形式["1","-","401","-","-","349"....]
就是把数字组合在一起，‘-’分开.
代码
```
List<String> list= new ArrayList<>();
        StringBuilder sb =new StringBuilder();
        for (int i = 0; i < S.length(); i++) {
            char s = S.charAt(i);
            if (s == '-') {
                if (sb.length() != 0) {
                    list.add(sb.toString());
                    list.add("-");
                    sb.delete(0,sb.length());
                }else {
                    list.add("-");
                }
            }else {
                sb.append(s);
            }
        }
        if (sb.length() != 0) {
            list.add(sb.toString());
        }
        String[] split = new String[list.size()];
        list.toArray(split);
```
由于题目是深度优先搜索，由深度优先搜索可以发现一个特点，‘-’的个数表示二叉树的层数，只要下一个‘-’的数量少于上一个，那么直到等于这个‘-’数量之前的节点都是计算完成可以不用去管的。

可以维护两个栈，一个是存放树的节点，一个是存放树的深度，只要当前‘-’的个数 等于 上一个节点‘-’的个数+1，可以判断是子节点，题目说了优先考虑左节点，那么就先加左边，左边有节点就加右边，再把计算过后的节点重新放入栈中。

另外一种情况，如果当前节点 小于等于上一个节点，那么上一个节点就没有效果了，可以直接出栈。

完整代码
```
public TreeNode recoverFromPreOrder(String S) {
        Stack<TreeNode> nodeStack = new Stack<>();
        Stack<Integer> intStack = new Stack<>();
        //保存根结点
        TreeNode root = null;
        List<String> list= new ArrayList<>();
        StringBuilder sb =new StringBuilder();
        for (int i = 0; i < S.length(); i++) {
            char s = S.charAt(i);
            if (s == '-') {
                if (sb.length() != 0) {
                    list.add(sb.toString());
                    list.add("-");
                    sb.delete(0,sb.length());
                }else {
                    list.add("-");
                }
            }else {
                sb.append(s);
            }
        }
        if (sb.length() != 0) {
            list.add(sb.toString());
        }
        String[] split = new String[list.size()];
        list.toArray(split);
        //计算当前节点的深度，等价于'-'的个数
        int count = 0;
        for (int i = 0; i < split.length; i++) {
            if ("-".equals(split[i])) {
                count++;
            } else {
                TreeNode thisNode = new TreeNode(Integer.parseInt(split[i]));
                if (root == null) {
                    root = thisNode;
                }
                if (nodeStack.empty()) {
                    nodeStack.push(thisNode);
                    intStack.push(count);
                    count = 0;
                } else {
                    //重新创建一个临时的双头链表，按照加入的顺序储存用过的节点
                    LinkedList<Integer> tempInt = new LinkedList<>();
                    LinkedList<TreeNode> tempNode = new LinkedList<>();
                    while (!nodeStack.empty()) {
                        int depth = intStack.pop();
                        TreeNode node = nodeStack.pop();
                        if (count == depth + 1) {
                            if (node.left == null) {
                                node.left = thisNode;
                            } else {
                                node.right = thisNode;
                            }
                            tempNode.addLast(thisNode);
                            tempInt.addLast(count);
                            //加入头部是为了保持顺序，顺序就是字符串节点的顺序
                            tempNode.addFirst(node);
                            tempInt.addFirst(depth);
                            break;

                        } else if (count == depth) {
                            tempInt.addFirst(depth);
                            tempNode.addFirst(node);
                        }
                    }
                    count = 0;
                    //计算完后放入栈
                    while (!tempNode.isEmpty()) {
                        nodeStack.add(tempNode.removeFirst());
                        intStack.add(tempInt.removeFirst());
                    }
                }
            }
        }

        return root;
    }
```
有很多可以优化的地方，懒得去搞了，通过就行了
