# Trie
    Tire is a data structure also called prefix tree.
    
Re-organizing the data structure is of great necessity when we need to deal with the big data problem.

Please refer Leetcode problem 208: implement a trie, if you do not know what a trie is.

## Solution 1: HashMap + PriorityQueue

```
public List<String> topKFrequent(String[] words, int k) {
        // Use hashmap to store the words
        Map<String, Integer> count = new HashMap();
        for (String word: words) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
        
        // PriorityQueue Comparator
        class WordComparator implements Comparator<String> {
            public int compare(String s1, String s2) {
                int times1 = count.get(s1);
                int times2 = count.get(s2);
                if( times1 < times2 ) {
                    return -1;
                }
                else if( times1 > times2 ) {
                    return 1;
                }
                else {
                    // We need to return the answer in alphabetical order
                    return s2.compareTo(s1);   
                    // not s1.compareTo(s2), 
                    // because we need the lower alphabetical word go first
                }
            }
        }
        PriorityQueue<String> heap = new PriorityQueue<String>(new WordComparator());
        // In a simple way:
        /*PriorityQueue<String> heap = new PriorityQueue<String>(
                (w1, w2) -> count.get(w1).equals(count.get(w2)) ?
                w2.compareTo(w1) : count.get(w1) - count.get(w2) 
        );*/

        for (String word: count.keySet()) {
            heap.offer(word);
            if (heap.size() > k) {
                heap.poll();
            }
        }

        List<String> ans = new ArrayList();
        while (!heap.isEmpty()) {
            ans.add(heap.poll());
        }
        Collections.reverse(ans);
        return ans;
    }
```

Time complexity: O(Nlogk) where k is the top k frequent word and N is the number of words we've got.
Space complexity: O(N).

## Solution 2
```
class Solution {
    
    class TrieNode {	
        // children
        private TrieNode[] children;

        // Whether current node is an end node.
        private boolean isEnd;
        private final int R = 26;  // Depends on the size of the character set
        private int appearTimes;
        private boolean hasChildren;
        private String word;

        // Constructor
        public TrieNode() {
            isEnd = false;
            children = new TrieNode[R];
            appearTimes = 0;
            hasChildren = false;
        }

        public boolean containsChar(char ch) {
            return children[ch-'a'] != null;
        }

        // getter and setter
        public boolean isEnd() {
            return isEnd;
        }
        public void setEnd(boolean _isEnd) {
            isEnd = _isEnd;
            appearTimes++;
        }

        // get Char by Char
        public TrieNode get(char ch) {
            return children[ch-'a'];
        }

        // put char
        public void put(char ch, TrieNode node) {
            children[ch-'a'] = node;
            hasChildren = true;
        }

        // get children
        public TrieNode[] getChildren() {
            return children;
        }

        // get appear times
        public int getAppearTimes() {
            return appearTimes;
        }
        
        // get has children
        public boolean hasChildren() {
            return hasChildren;
        }
        
        // get current word
        public String getCurrentWord() {
            return word;
        }
        // set current word
        public void setCurrentWord(String _word) {
            word = _word;
        }
    }
    
    class Trie {
	
        private TrieNode root;

        // Constructor
        public Trie() {
            root = new TrieNode();
        }

        // Get root
        public TrieNode getRoot() {
            return root;
        }

        // Inserts a word into the trie.
        public void insert(String word) {
            TrieNode node = root;
            for( int i = 0; i < word.length(); i++ ) {
                char currentChar = word.charAt(i);
                if( !node.containsChar(currentChar) ) {
                    node.put(currentChar, new TrieNode());
                }
                node = node.get(currentChar);
            }
            node.setEnd(true);
            node.setCurrentWord(word);
        }

        // Returns if the word is in the trie.
        public boolean search(String word) {
            TrieNode node = root;
            for( int i = 0; i < word.length(); i++ ) {
                char currentChar = word.charAt(i);
                if( node.containsChar(currentChar) ) {
                    node = node.get(currentChar);
                }
                else {
                    return false;
                }
            }
            return node.isEnd();       
        }

        // Returns if there is any word in the trie that starts with the given prefix.
        public boolean searchPrefix(String prefix) {
            TrieNode node = root;
            for( int i = 0; i < prefix.length(); i++ ) {
                char currentChar = prefix.charAt(i);
                if( node.containsChar(currentChar) ) {
                    node = node.get(currentChar);
                }
                else {
                    return false;
                }
            }  	
            return true;        
        }

    }
    
    public List<String> topKFrequent(String[] words, int k) {
        // Actually trie can do better. Construct the trie: O(N). 
        // Search the trie: O(26*k) k is the longest word in words.
        // Use priority queue with size k to sort
        
        // Construct a trie
        Trie trie = new Trie();
        for( String str : words ) {
            trie.insert(str);
        }
        HashMap<String, Integer> count = new HashMap<String, Integer>();

        // Search the trie by DFS
        dfs(trie.getRoot(), count);
        
        // PriorityQueue Comparator
        class WordComparator implements Comparator<String> {
            public int compare(String s1, String s2) {
                int times1 = count.get(s1);
                int times2 = count.get(s2);
                if( times1 < times2 ) {
                    return -1;
                }
                else if( times1 > times2 ) {
                    return 1;
                }
                else {
                    // We need to return the answer in alphabetical order
                    return s2.compareTo(s1);   
                    // not s1.compareTo(s2), 
                    // because we need the lower alphabetical word go first
                }
            }
        }
        PriorityQueue<String> heap = new PriorityQueue<String>(new WordComparator());

        for (String word: count.keySet()) {
            heap.offer(word);
            if (heap.size() > k) {
                heap.poll();
            }
        }

        List<String> ans = new ArrayList();
        while (!heap.isEmpty()) {
            ans.add(heap.poll());
        }
        Collections.reverse(ans);
        return ans;
        
    }
    
    // DFS helper funtion
    private void dfs(TrieNode node, HashMap<String, Integer> count) {
        if( node.isEnd() ) {
            count.put(node.getCurrentWord(), node.getAppearTimes());
        }
        // Recursion exit
        if( !node.hasChildren() ) {
            return ; 
        }        
        // Recursion
        TrieNode[] children = node.getChildren();
        for( int i = 0; i < children.length; i++ ) {
            if( children[i] != null ) {
                dfs(node.children[i], count);
            }
        }        
    }
}
```
### Time complexity: 
    Construct the trie: O(N)
    Search the trie: O(L^26) where L is the height of the trie, 
    which is the length of the longest word in words.
### Space complexity: O(N)