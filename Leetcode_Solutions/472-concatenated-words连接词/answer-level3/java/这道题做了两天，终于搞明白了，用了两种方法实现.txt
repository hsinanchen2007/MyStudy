### 解题思路
dfs和字典树。递归的方法就是人类理解起来不好理解，电脑很好理解

### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String[] words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
        List<String> list = solution.findAllConcatenatedWordsInADict(words);
        list.forEach(s -> System.out.println("s = " + s));
    }

    HashSet<String> dict = new HashSet<>();

    public List<String> findAllConcatenatedWordsInADict1(String[] words) {
        ArrayList<String> list = new ArrayList<>();
        /**
         * dfs
         */
        dict.addAll(Arrays.asList(words));
        System.out.println("dict.size() = " + dict.size());
        for (String word : words) {
            if (mydfs(word, 0, 0)) {
                list.add(word);
            }
        }
        return list;
    }

    TreeNode root = new TreeNode();

    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        for (String word : words) {
            createTireTree(word);
        }
        ArrayList<String> list = new ArrayList<>();
        /**
         * dict
         */
        for (String word : words) {
            if (find(word, 0, 0)) {
                list.add(word);
            }
        }
        return list;
    }

    private boolean mydfs(String word, int idx, int cnt) {
        if (idx == word.length()) {
            return cnt > 1;
        }
        for (int i = idx; i < word.length(); i++) {
            if (dict.contains(word.substring(idx, i + 1))) {
                if (mydfs(word, i + 1, cnt + 1)) {
                    return true;
                }
            }
        }
        return false;
    }


    public void createTireTree(String s) {
        TreeNode node = root;
        char[] d = s.toCharArray();
        for (char c : d) {
            int loc = c - 'a';
            if (node.childs[loc] == null) {
                node.childs[loc] = new TreeNode();
            }
            node = node.childs[loc];
        }
        node.isEnd = true;
    }

    public boolean find(String s, int index, int count) {
        if (s == null || "".equals(s)) {
            return false;
        }
        TreeNode node = root;
        /**
         * 一层一层寻找，找到的话检查count是否大于1
         */
        char[] d = s.toCharArray();
        for (int i = index; i < d.length; i++) {
            int loc = d[i] - 'a';
            if (node.childs[loc] == null) {
                return false;
            }
//            如果为单词结点，则判断count是否大于等于1，如果大于等于1且到了最后一个字符，则返回true。
//            否则，count+1并且以下一个结点开始查找。
            if (node.childs[loc].isEnd) {
                if (count >= 1 && i == s.length() - 1) {
                    return true;
                } else {
                    if (find(s, i + 1, count + 1)) {
                        return true;
                    }
                }

            }
            node = node.childs[loc];
        }
        return false;

    }

    static class TreeNode {
        final static int size = 26;
        String data;
        boolean isEnd;
        TreeNode[] childs;

        public TreeNode() {
            childs = new TreeNode[size];
        }
    }

}
```