### 解题思路
两种解法，暴力和前缀树，还是比较清晰且简单的

### 代码

```java
/*
 * Copyright (c) 2020
 * Author: xiaoweixiang
 */
import java.util.*;

class Solution {
    public static void main(String[] args) {
        String[] words = {"bat", "tab", "cat"};
        Solution solution = new Solution();
        List<List<Integer>> list = solution.palindromePairs(words);
        List<List<Integer>> list1 = solution.palindromePairs1(words);
        list.forEach(o -> System.out.println("list:" + o.get(0) + "," + o.get(1)));
        list1.forEach(o -> System.out.println("list1:" + o.get(0) + "," + o.get(1)));
    }

    public List<List<Integer>> palindromePairs1(String[] words) {
        // 只想到了暴力解法 o n^2
        List<List<Integer>> resList = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            for (int j = i + 1; j < words.length; j++) {
                if (isPalindrome(words[i], words[j])) {
                    resList.add(Arrays.asList(i, j));
                }
                if (isPalindrome(words[j], words[i])) {
                    resList.add(Arrays.asList(j, i));
                }
            }
        }
        return resList;
    }

    public List<List<Integer>> palindromePairs(String[] words) {
        for (int i = 0; i < words.length; i++) {
            reverseInsert(words[i], i);
        }
        // trie
        List<List<Integer>> resList = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            find(words[i], i, resList);
        }
        return resList;
    }

    private void find(String s, int index, List<List<Integer>> resList) {
        Trie head = root;
        char[] array = s.toCharArray();
        for (char c : array) {
            if (head.isWord) {
                if (head.index != index) {
                    if (isPalindrome(s + head.value)) {
                        resList.add(Arrays.asList(index, head.index));
                    }
                }
            }
            if (head.children.get(c) == null) {
                return;
            }
            head = head.children.get(c);
        }
        dfs(s, index, head, resList);
    }

    private void dfs(String s, int index, Trie head, List<List<Integer>> resList) {
        if (head == null) return;
        if (head.isWord) {
            if (head.index != index) {
                if (isPalindrome(s + head.value)) {
                    resList.add(Arrays.asList(index, head.index));
                }
            }
        }
        for (Trie trie : head.children.values()) {
            dfs(s, index, trie, resList);
        }
    }

    private boolean isPalindrome(String s, String s1) {
        String s2 = s + s1;
        int i = 0;
        int j = s2.length() - 1;
        while (i < j) {
            if (s2.charAt(i) != s2.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }

    private boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }

    class Trie {
        boolean isWord = false;
        String value = "";
        int index = -1;
        HashMap<Character, Trie> children = new HashMap<Character, Trie>();
    }


    Trie root = new Trie();

    private void reverseInsert(String s, int wordIndex) {
        Trie head = root;
        if ("".equals(s)) {
            head.isWord = true;
            head.value = s;
            head.index = wordIndex;
        }
        char[] array = s.toCharArray();
        for (int i = array.length - 1; i >= 0; i--) {
            char c = array[i];
            if (head.children.get(c) == null) {
                Trie tempTrie = new Trie();
                tempTrie.value = c + head.value;
                head.children.put(c, tempTrie);
            }
            head = head.children.get(c);
        }
        head.index = wordIndex;
        head.isWord = true;
    }
}

```