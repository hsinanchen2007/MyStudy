```cpp
class Trie {
public:
	bool is_word;
	unordered_map<char,Trie*> children;
	Trie() {
		this->is_word = false;
		this->children = {};
	}
};
class WordDictionary {
public:
	Trie* root;

	/** Initialize your data structure here. */
	WordDictionary() {
		root = new Trie();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Trie* p=root;
		for (char& c : word) {
			if (!p->children.count(c)) {
				p->children[c] = new Trie();
			}
			p = p->children[c];
		}
		p->is_word = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return search_helper( word, 0, root);
	}
	bool search_helper( string& word, int index, Trie* p) {
		if (index == word.size()) {
			return p && p->is_word;
		}
		if (word[index] == '.') {
			for (auto it = p->children.begin(); it != p->children.end(); ++it)
				if (search_helper( word, index+1, p->children[it->first]) )
					return true;
			return false;
		}
		else
			return p->children.count(word[index]) && search_helper(word, index + 1, p->children[word[index]]);
	}
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```