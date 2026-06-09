```
class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        int n = words.length;
        
        Trie trie = new Trie();
        for (int i = 0; i < n; ++i)
            trie.insert(words[i], i);
        
        List<List<Integer>> result = new LinkedList();
        for (int i = 0; i < n; ++i)
            trie.search(words[i], i, words, result);
        
        return result;
    }
}

class Trie {
    
    TrieNode reverseRoot = new TrieNode();
    
    public void insert(String word, int index) {
        int n = word.length();
        
        TrieNode reverse = reverseRoot;
        int charNo;
        
        for (int i = n-1; i >= 0; --i) {            
            charNo = word.charAt(i) - 'a';
            if (reverse.children[charNo] == null)
                reverse.children[charNo] = new TrieNode();
            reverse = reverse.children[charNo];
        }
        
        reverse.wordIndex = index;
    }
    
    public void search(String word, int index, String[] words, List<List<Integer>> result) {
        int n = word.length();
        int charNo;
        TrieNode node = reverseRoot;
        TrieNode child;
        for (int i = 0; i < n; ++i) {
            if (node.isWord() && isPalindrome(word, i, word.length()-1)) 
                addResult(index, node.wordIndex, result);
            
            charNo = word.charAt(i) - 'a';
            child = node.children[charNo];
            if (child == null)
                return;
            node = child;
        }
        
        Set<Integer> others = new HashSet();
        getLeftWords(node, others);
        for (int reverse: others) {
            if (isPalindrome(words[reverse], 0, words[reverse].length()-n-1))
                addResult(index, reverse, result);
        }
    }
    
    private void getLeftWords(TrieNode node, Set<Integer> words) {
        if (node == null)
            return;
        
        if (node.isWord())
            words.add(node.wordIndex);
        
        for (int i = 0; i < 26; ++i)
            getLeftWords(node.children[i], words);
    }
    
    private void addResult(int regular, int reverse, List<List<Integer>> result) {
        if (regular == reverse)
            return;
        List<Integer> pair = new ArrayList<>();
        pair.add(regular);
        pair.add(reverse);
        result.add(pair);
    }
    
    private boolean isPalindrome(String word, int start, int end) {
        while (start < end) {
            if (word.charAt(start++) != word.charAt(end--))
                return false;
        }
        return true;
    }
    
}

class TrieNode {
    public TrieNode[] children = new TrieNode[26];
    public int wordIndex = -1;
    public boolean isWord() {
        return wordIndex != -1;
    }
}
```
