### 关键字：树
1、初始化一个数据为“”的节点作为根节点（root节点），然后将每个数字对应的，每一个字符创建为一个新的节点，放在同一个父节点下，并且要循环执行父节点层节点数次（如：父节点层有3个节点，那么要循环执行3次，每个节点下都有相同的节点）。![1563288480(1).jpg](https://pic.leetcode-cn.com/12b2aeda63295296600b63da5670542d7bb52f897501ba0bf2d63ad669562ecb-1563288480\(1\).jpg)/
2、遍历树，根节点到叶节点的节点数据为一个组合方式
```
public class Test {

    private Node root = new Node("");

    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();

        if (digits == null || digits.length() == 0) {
            return result;
        }

        char[] chars = digits.toCharArray();
        List<List<String>> lists = new ArrayList<>();
        for (char c : chars) {
            lists.add(char2String(c));
        }


        //生成树
        tree(root, lists, 0);

        return ergodicTree(root);
    }

    //用于临时存储路径
    private StringBuilder sb = new StringBuilder();
    private List<String> res = new ArrayList<>();

    /**
     * 遍历树
     *
     * @param tree
     * @return
     */
    private List<String> ergodicTree(Node tree) {

        getCode(tree, tree.c, sb);
        return res;
    }

    private void getCode(Node node, String str, StringBuilder sb) {

        StringBuilder stringBuilder = new StringBuilder(sb);
        stringBuilder.append(str);

        if (node.nodes.size() > 0) {
            for (Node n : node.nodes) {
                getCode(n, n.c, stringBuilder);
            }
        } else {
            res.add(stringBuilder.toString());
        }

    }

    private void tree(Node node, List<List<String>> lls, int index) {

        List<String> cl = lls.get(index);
        for (String c : cl) {
            node.nodes.add(new Node(c));
        }
        index++;
        if (index < lls.size()) {
            for (Node n : node.nodes) {
                tree(n, lls, index);
            }
        }


    }


    private static List<String> char2String(char c) {
        List<String> characters = null;
        switch (c) {
            case '1':
                characters = Arrays.asList("");
                break;
            case '2':
                characters = Arrays.asList("a", "b", "c");
                break;
            case '3':
                characters = Arrays.asList("d", "e", "f");
                break;
            case '4':
                characters = Arrays.asList("g", "h", "i");
                break;
            case '5':
                characters = Arrays.asList("j", "k", "l");
                break;
            case '6':
                characters = Arrays.asList("m", "n", "o");
                break;
            case '7':
                characters = Arrays.asList("p", "q", "r", "s");
                break;
            case '8':
                characters = Arrays.asList("t", "u", "v");
                break;
            case '9':
                characters = Arrays.asList("w", "x", "y", "z");
                break;


        }
        return characters;
    }

    private class Node {

        String c;
        List<Node> nodes;

        public Node(String c) {
            this.c = c;
            nodes = new ArrayList<>();
        }

    }
}

```
