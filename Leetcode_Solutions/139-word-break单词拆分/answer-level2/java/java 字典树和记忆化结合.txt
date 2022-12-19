## intro

看到这个题目，我首先的想法就是字典树。

因为给定的数据库有个字典数组，如果数组中的字符串有相同前缀，每次重复搜浪费了时间。

然后看题解大家都是用的动态规划/记忆化，就写了个字典树的版本

## 代码

```java

class Solution {

    public class TrieNode {       
        boolean flag;  
        HashMap<Character, TrieNode> next = new HashMap<Character, TrieNode>(); 
          
        public TrieNode() {  
            flag = false; 
        }  
    }

    TrieNode root;
    //List<Integer>  memo = new LinkedList<Integer>();
    int[] memo;

    public boolean helper(String s, int start, int end) {
        if(start == end) return true;
        if (start == end)
            return true;
        if (memo[start] != 0)
            return memo[start] > 0;
        TrieNode node = root;
        for (int i = start; i < end; ++i) {
            if (!node.next.containsKey(s.charAt(i)))
                break;
            node = node.next.get(s.charAt(i));
            if (node.flag && helper(s, i + 1, end)){
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = -1;
        return false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        memo = new int[s.length()];
        root = new TrieNode();
        TrieNode node = root;
        for(String word : wordDict){
            node = root;
            for(char ch : word.toCharArray()){
                if(!node.next.containsKey(ch)){
                    node.next.put(ch, new TrieNode());
                }
                node = node.next.get(ch);
            }
            node.flag = true;
        }
        return helper(s, 0, s.length());
    }
}
```

## 结果

- 36/36 cases passed (4 ms)
- Your runtime beats 88.4 % of java submissions
- Your memory usage beats 5.02 % of java submissions (42.1 MB)

使用字典树和记忆化进行优化