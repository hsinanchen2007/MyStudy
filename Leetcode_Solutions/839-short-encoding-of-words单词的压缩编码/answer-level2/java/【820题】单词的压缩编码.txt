**方法一：单词后缀**
```
class Solution {
    /**
     * 思路：
     *  由题最终的编码字符串由所有不属于其它单词后缀的单词和 # 组成，
     *  所以使用 HashSet 移除所有属于其它单词后缀的单词后计算组成的编码串长度。
     */
    public int minimumLengthEncoding(String[] words) {
        // 将数组单词保存到 HashSet 中。
        Set<String> set = new HashSet(Arrays.asList(words));
        // 遍历所有单词，移除 HashSet 中属于当前单词后缀的单词。
        for (String word: words) {
            for (int k = 1; k < word.length(); k++){
                set.remove(word.substring(k));
            }
        }
        int ans = 0;
        // 遍历 HashSet 中剩余不属于其它单词后缀的所有单词，并累加长度。
        for (String word: set){
            ans += word.length() + 1;
        }
        return ans;
    }
}
```

**方法二：构建字典树**
```
class Solution {
    /**
     * 思路：
     *  由题最终的编码字符串由所有不属于其它单词后缀的单词和 # 组成，
     *  所有由每个单词字母倒序构建字典树，得到所有不属于其它单词后缀的单词，
     *  最后计算组成的编码串长度。
     */
    public int minimumLengthEncoding(String[] words) {
        // 字典树的树根。
        TrieNode trie = new TrieNode();
        // 存储每个单词首字母的节点以及在原数组中的单词角标。
        Map<TrieNode, Integer> nodes = new HashMap();
        // 倒序遍历每个单词的字母，构建当前单词每个字母在字典树中的子节点。
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            TrieNode cur = trie;
            for (int j = word.length() - 1; j >= 0; j--){
                cur = cur.get(word.charAt(j));
            }
            nodes.put(cur, i);
        }
		
        int ans = 0;
        // 遍历所有单词首字母节点，子节点个数为 0 表示当前节点为叶子节点。
        for (TrieNode node: nodes.keySet()) {
            if (node.count == 0){
                ans += words[nodes.get(node)].length() + 1;
            }
        }
        return ans;
    }
}

class TrieNode {
    // 当前单词字母组成的节点数组。
    TrieNode[] children;
    // 记录当前节点的子节点个数。
    int count;
    TrieNode() {
        // 单词每个字母节点下面都有26个字母分支。
        children = new TrieNode[26];
        // 初始化没有子节点时候。
        count = 0;
    }

    public TrieNode get(char c) {
        // 如果获取的字母不是当前字母的子节点则创建一个。
        if (children[c - 'a'] == null) {
            children[c - 'a'] = new TrieNode();
            count++;
        }
        return children[c - 'a'];
    }
}
```

**方法三：字符串包含**
```
class Solution {
    /**
     * 思路：
     *  按单词长度由长到短拼接 # 构建编码字符串，
     *  如果之后单词拼接 # 之后不属于之前编码字符串则继续拼接，
     *  被包含则不拼接，直到遍历完所有单词返回编码字符串长度。
     */
    public int minimumLengthEncoding(String[] words) {
        // 字符串长度由大到小排序(JDK1.8以后新增的lambda表达式)。
        Arrays.sort(words, (w1, w2) -> w2.length() - w1.length());
        // 然后在进行匹配的计算。
        StringBuilder sb = new StringBuilder();
        for (String word : words) {
            if (sb.indexOf(word + "#") < 0) {
                sb = sb.append(word).append("#");
            }
        }
        return sb.length();
    }
}
```
