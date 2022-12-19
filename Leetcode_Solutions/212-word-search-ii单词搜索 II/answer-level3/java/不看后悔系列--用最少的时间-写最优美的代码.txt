### 代码

```java
class Trie {
	static class TrieNode {
		public char val;
		public boolean isWord;
		public TrieNode[] children = new TrieNode[26];

		public TrieNode() {
		}

		TrieNode(char c) {
			TrieNode node = new TrieNode();
			node.val = c;
		}
	}

	private TrieNode root;

	/** Initialize your data structure here. */
	public Trie() {
		root = new TrieNode();
		root.val = ' ';
	}

	/** Inserts a word into the trie. */
	public void insert(String word) {
		TrieNode ws = root;
		for (int i = 0; i < word.length(); i++) {
			char c = word.charAt(i);
			if (ws.children[c - 'a'] == null) {
				ws.children[c - 'a'] = new TrieNode(c);
			}
			ws = ws.children[c - 'a'];
		}
		ws.isWord = true;
	}

	/** Returns if the word is in the trie. */
	public boolean search(String word) {
		TrieNode ws = root;
		for (int i = 0; i < word.length(); i++) {
			char c = word.charAt(i);
			if (ws.children[c - 'a'] == null)
				return false;
			ws = ws.children[c - 'a'];
		}
		return ws.isWord;
	}

	/**
	 * Returns if there is any word in the trie that starts with the given prefix.
	 */
	public boolean startsWith(String prefix) {
		TrieNode ws = root;
		for (int i = 0; i < prefix.length(); i++) {
			char c = prefix.charAt(i);
			if (ws.children[c - 'a'] == null)
				return false;
			ws = ws.children[c - 'a'];
		}
		return true;
	}
}
class Solution {
   Set<String> res=new HashSet<>();
	//212-单词搜索||
	public List<String> findWords(char[][] board, String[] words) {
		Trie trie=new Trie();
		for(String word:words) {
			trie.insert(word);
		}
		int m=board.length;
		int n=board[0].length;
		boolean[][] visited=new boolean[m][n];
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				dfs(board, visited, "", i, j, trie);
			}
		}
		return new ArrayList<>(res);
	}
	
	public void dfs(char[][] board,boolean[][] visited,String str,int x,int y,Trie trie) {
		if(x<0||x>=board.length||y<0||y>=board[0].length)return;
		if(visited[x][y])return;
		
		str+=board[x][y];
		if(!trie.startsWith(str))return;
		
		if(trie.search(str))res.add(str);
		visited[x][y]=true;
		dfs(board, visited, str, x-1, y, trie);
		dfs(board, visited, str, x+1, y, trie);
		dfs(board, visited, str, x, y-1, trie);
		dfs(board, visited, str, x, y+1, trie);
		visited[x][y]=false;
	}
}
```