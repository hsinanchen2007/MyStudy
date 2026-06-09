### 解题思路
![111.png](https://pic.leetcode-cn.com/3c9c128efc98625315a87f0579dc32945f2189b3ee9791203c88d2ee263ac6fb-111.png)
昨天刚做了跳跃游戏，感觉这个方法挺类似的。

### 代码

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        Set<Integer> indexSet = new HashSet<>();
        queue.add(0);
        indexSet.add(0);
        while(!queue.isEmpty()) {
            int index = queue.poll();
            //遍历单词可达位置，并保存在queue中。
            for(int end=index+1; end<=s.length(); end++) {
                if(wordDict.contains(s.substring(index, end))) {
                    if(end == s.length()) {
                        return true;
                    }
                    //可达位置去重
                    if(!indexSet.contains(end)) {
                        indexSet.add(end);
                        queue.add(end);
                    }
                }
            }
        }
        return false;
    }

    public boolean wordBreak_V1(String s, List<String> wordDict) {
        TrieNode root = new TrieNode();
        for(int i=0; i<wordDict.size(); i++) {
            root.addString(wordDict.get(i), 0);
        }
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        Set<Integer> indexSet = new HashSet<>();
        queue.add(0);
        indexSet.add(0);
        while(!queue.isEmpty()) {
            int index = queue.poll();
            List<Integer> next = new ArrayList<>();
            int maxIndex = root.searchStringIndex(next, s, index);
            if(maxIndex == s.length()) {
                return true;
            }
            for(int nextIndex : next) {
                if(!indexSet.contains(nextIndex)) {
                    indexSet.add(nextIndex);
                    queue.add(nextIndex);
                }
            }
        }
        return false;

    }

    class TrieNode {
        TrieNode[] children;
        public TrieNode(){
            children = new TrieNode[27];
        }

        public void addString(String s, int start) {
            if(start == s.length()) {
                this.children[26] = new TrieNode();
                return;
            }
            int index = s.charAt(start)-'a';
            if(this.children[index] == null) {
                this.children[index] = new TrieNode();
            }
            this.children[index].addString(s, start+1);
        }
        //查找trie数上所有可匹配s.substring(start)的末尾索引
        private int searchStringIndex(List<Integer> ret, String s, int start) {
            int lastIndex = -1;
            TrieNode node = this;
            int i=start;
            for(; i<=s.length(); i++) {
                if(node.children[26] != null) {
                    ret.add(i);
                    lastIndex = i;                   
                }
                if(i == s.length()) {
                    break;
                }
                int index = s.charAt(i)-'a';              
                if(node.children[index] == null) {
                    break;
                }                
                node = node.children[index];
            }
            return lastIndex;
        }
    }
}
```