**方法一:** 将字符串数组排序,找到前三个符合条件的直接返回.

**方法二:** 字典树,每个树节点保存到此为止满足条件的所有字符串.
```
    class Node {
        List<String> words;
        Map<Character, Node> nodes;

        Node() {
            this.words = new ArrayList<>();
            this.nodes = new HashMap<>(26);
        }
    }

    /**
     * 这里为了加快寻找速度,记忆上一个节点,将node设置为全局变量
     */
    Node node; 

    private void makeTree(String[] products, Node node) {
        for (String s : products) {
            Node tmp = node;
            for (char c : s.toCharArray()) {
                if (!tmp.nodes.containsKey(c)) {
                    Node newNode = new Node();
                    newNode.words.add(s);
                    tmp.nodes.put(c, newNode);
                } else {
                    tmp.nodes.get(c).words.add(s);
                }
                tmp = tmp.nodes.get(c);
            }
        }
    }

    private List<String> getStr(char c) {
        List<String> res = new ArrayList<>();
        if (node == null || !node.nodes.containsKey(c)) {
            node = null;
            return new ArrayList<>();
        } else {
            node = node.nodes.get(c);
            res = node.words;
        }
        if (res.size() > 3) {
            res = res.subList(0, 3);
        }
        return res;
    }

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        node = new Node();
        /**
         * 由于List数组有序,所以先排序,每次makeTree操作不用排序
         */
        Arrays.sort(products);
        makeTree(products, node);
        List<List<String>> res = new ArrayList<>();
        for (int i = 0; i < searchWord.length(); i++) {
            res.add(getStr(searchWord.charAt(i)));
        }
        return res;
    }
```
