```cpp
class Trie {
private:
  Trie* next[26];
  int times;
public:
  Trie() {
    for (int i = 0; i < 26; i++) next[i] = nullptr;
    times = 0;
  }
  void insert(string word) {
    Trie* node = this;
    for (auto& ch : word) {
      if (node->next[ch - 'a'] == nullptr) {
        node->next[ch - 'a'] = new Trie();
      }
      node = node->next[ch - 'a'];
    }
    node->times++;
  }
  int search(string word) {
    Trie* node = this;
    for (auto& ch : word) {
      if (node->next[ch - 'a'] == nullptr) return 0;
      node = node->next[ch - 'a'];
    }
    return node->times;
  }
};
class WordsFrequency {
private:
  Trie* trie;
public:
  WordsFrequency(vector<string>& book) {
    trie = new Trie();
    for (auto& word : book) {
      trie->insert(word);
    }
  }
  
  int get(string word) {
    return trie->search(word);
  }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
```