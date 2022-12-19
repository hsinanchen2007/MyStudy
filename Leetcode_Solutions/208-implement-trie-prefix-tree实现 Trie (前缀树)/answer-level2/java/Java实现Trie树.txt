Trie树的应用有：给字符串按字典序排序，统计以某字符串作为前缀的单词数量等等
```
class Trie {
    class Node{
		Node next[] = new Node[26]; 
		boolean end;    //当前节点是否为某个单词的末尾
		int cnt;	//以当前节点路径为前缀的单词数量
	}
	Node root = new Node();

    
    /** Inserts a word into the trie. */
    public void insert(String s) {
		root.cnt++;
		Node p = root;
		for(int i=0;i<s.length();i++){
			int k = s.charAt(i) - 'a';
			if(p.next[k]==null) p.next[k] = new Node();
			p = p.next[k];
			p.cnt++;
		}
		p.end = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String s) {
		Node p = root;
		for(int i=0;i<s.length();i++){
			int k = s.charAt(i) - 'a';
			if(p.next[k]==null) return false;
			p = p.next[k];
		}
		return p.end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String s) {
		Node p = root;
		for(int i=0;i<s.length();i++){
			int k = s.charAt(i) - 'a';
			if(p.next[k]==null) return false;
			p = p.next[k];
		}
		return p.cnt>0 ? true : false;  //以字符串s为前缀的字符串数大于0，返回true
    }
}
```

