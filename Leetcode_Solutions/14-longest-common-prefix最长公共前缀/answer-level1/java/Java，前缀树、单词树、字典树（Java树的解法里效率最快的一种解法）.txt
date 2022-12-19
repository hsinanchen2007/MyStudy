### 解题思路
    1、生成单词树（trie），且增加一个统计当前树下的单词熟练
    2、直接随机选取一个字符串，然后用字符串的字符进行树递归查询，每次查询结束都追加当前的字符
    3、结束条件：
            a、如果树的当前节点下的单词数量小于字符串数组的数量就返回；
            b、随机选择的字符串遍历完毕。

### 代码

```java
 class Solution {
        public String longestCommonPrefix(String[] strs) {
            int len = strs.length;
            StringBuilder res = new StringBuilder("");
            if (len == 0) return res.toString();
            Trie trie = new Trie();
            trie.build(strs);
            Node node = trie.root;
            for (char ch : strs[0].toCharArray()) {
                node = node.children[ch - 'a'];
                if (node.total != strs.length) return res.toString();
                res.append(ch);
            }
            return res.toString();

        }

        class Trie {
            Node root = new Node();

            public void build(String[] strs) {
                for (String str : strs) {
                    Node temp = root;
                    temp.total++;
                    for (char ch : str.toCharArray()) {
                        if (temp.children[ch - 'a'] == null) {
                            temp.children[ch - 'a'] = new Node();
                        }
                        temp = temp.children[ch - 'a'];
                        temp.total++;
                    }

                }
            }
        }

        class Node {
            int total = 0;
            Node[] children;

            public Node() {
                children = new Node[26];
            }
        }
    }
```