使用前缀树来解决这个问题，只不过要倒着插入一个字符串。显然，我们需要的字母长度是从根结点到每个叶子结点的长度之和，需要的'#'个数就是从根结点到叶子结点的路径数，所以在插入的时候，标记路径上的每个结点是否为叶子结点，然后利用深度优先搜索，找到所有的叶子结点，并且计算出长度即可。


```
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Trie tree = new Trie();
        for (String word : words) {
            tree.reverseInsert(word);
        }
        return tree.getLength();
    }

    //前缀树定义
    class Trie {
        class Node {
            //标记是否是叶子结点
            boolean isTail;
            Node[] childeren;
            public Node() {
                isTail = true;
                childeren = new Node[26];
            }
        }

        Node root;

        //需要字母的长度
        int sum;
        //需要‘#’的数量
        int count;

        public Trie() {
            count = 0;
            sum = 0;
            root = new Node();
        }

        //倒着插进来
        public void reverseInsert(String word) {
            Node p = root;
            char[] chars = word.toCharArray();
            for (int i = chars.length - 1; i >= 0; i--) {
                //标记路径上的结点都不是叶结点
                p.isTail = false;
                int c = chars[i] - 'a';
                if (p.childeren[c] == null) {
                    p.childeren[c] = new Node();
                }
                p = p.childeren[c];  
            }
            //此时一定有 p.isTail = true
        }
        
        public int getLength() {
            dfs(root, 0);
            return sum + count;
        }

        //len 是从 root 到 node 的路径长度，也就是这条路径上结点的数量（不包括根结点）
        public void dfs(Node node, int len) {
            if (node.isTail) {
                //到达叶结点
                count++;
                sum += len;
                return;
            }
            len++;
            for (Node next : node.childeren) {
                if (next != null) {
                    dfs(next, len);
                }
            }
        }
    }
}
```
