TrieTree的变形，主要是在搜索时加入了有没有用过regex的条件判断。

**搜索成功的条件：**
1. word所有内容都参与到匹配中来（word中没有多余的字符）
2. 从root出发的某条路径所表示的单词参与到匹配中来（搜索到某个root处，root.isword == true）
3. 匹配过程使用过1次regex
不满足任何一条都返回false。

```java
class MagicDictionary {
    private TrieNode root;

    public MagicDictionary() {
        root = new TrieNode('-');
    }

    public void buildDict(String[] dict) {
        for (String s : dict) {
            TrieNode tmp = root;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                int index = c - 'a';
                if (tmp.next[index] == null) tmp.next[index] = new TrieNode(c);
                tmp = tmp.next[index];
            }
            tmp.isword = true;
        }
    }

    public boolean search(String word) {
        if (word == null || word.length() == 0) return false;
        for (int i = 0; i < 26; i++) {
            if (root.next[i] == null) continue;
            if (word.charAt(0) - 'a' == i) {
                if (search(word, root.next[i], false, 1)) return true;
            }
            else {
                if (search(word, root.next[i], true, 1)) return true;
            }
        }
        return false;
    }

    // word在word_index之前（不包括word_index）和root及以前的内容已经匹配完，现在要根据word_index及以后的内容匹配root（不包括root）下面的内容
    private boolean search(String word, TrieNode root, boolean regex_used, int word_index) {
        // 完成匹配返回true的条件（同时满足3条）：
        // 1.word所有内容已经匹配完了
        // 2.搜索到此处，root是一个终结单词（root.isword == true）
        // 3.使用过regex

        // 如果word下面已经没有东西了，应该返回是否满足条件2和3
        if (word_index == word.length()) return root.isword && regex_used;

        // word下面必还有内容，root下面可能还有内容，应该尝试匹配
        for (int i = 0; i < 26; i++) {
            // 此root下面没有内容了，不可能继续搜索/不满足条件2，continue掉
            if (root.next[i] == null) continue;

            // 本节点内容匹配成功，继续向下搜索，保持之前regex的使用状态
            if (word.charAt(word_index) - 'a' == i) {
                if (search(word, root.next[i], regex_used, word_index + 1)) return true;
            }

            // 虽然本节点不匹配，但或许可以用regex跳过这个节点
            else {
                // 已经跳过一次了，再跳会失败。这里我debug很久才发现，不能return false而是应该continue。
                if (regex_used) continue;

                if (search(word, root.next[i], true, word_index + 1)) return true;
            }
        }
        // word下面还有内容，但root下面的所有内容都不能匹配word下面的内容，返回false
        return false;
    }

    private static class TrieNode {
        char val;
        boolean isword = false;
        TrieNode[] next = new TrieNode[26];

        public TrieNode(char val) {
            this.val = val;
        }
    }
}
```

感觉复杂度应该应该是**O(26\*n)**相当于**O(n)**，如果可以允许2次通配符就是O(26\*26\*n)？不知道这么算对不对
实际时间还可以，这个方法没用ADT，空间比较好。85%/94%