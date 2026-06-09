### 解题思路
1. Trie因为都是小写字母, 考虑使用指针数组存储26根指针, 以空间换时间, 时间复杂度$O(L)$
2. 集合运算【python3】
### 代码

```c++ []
class WordDictionary {
// 使用Trie实现
private:
    class Node{
    public:
        bool isWord = false;
        Node* next[26];
    };

    Node *root; // Trie树根节点
    int size;   // Trie存储单词的数量

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        this->root = new Node();
        this->size = 0;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *cur = root;
        for(int i=0; i<word.size(); ++i){
            if(cur->next[word[i]-'a']==nullptr){
                cur->next[word[i]-'a'] = new Node();
            }
            cur = cur->next[word[i]-'a'];
        }
        if(!cur->isWord){
            cur->isWord = true;
            this->size++;
        }
        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Node *cur = root;
        return match(cur, word, 0);
    }

private:
    bool match(Node *cur, string word, int index){
        if(index == word.size())
            return cur->isWord;
        if(word[index] != '.'){
            if(cur->next[word[index]-'a'] == nullptr)
                return false;
            return match(cur->next[word[index]-'a'], word, index+1);
        }
        // 如果是通配符, 则遍历所有非空子节点
        else{
            for(auto &p: cur->next){
                if(p != nullptr){
                    if(match(p, word, index+1))
                        return true;
                }
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```
```java []
class WordDictionary {

    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        Node cur = root;
        for(int i=0; i<word.length(); ++i){
            if(cur.next[word.charAt(i)-'a']==null)
                cur.next[word.charAt(i)-'a'] = new Node();
            cur = cur.next[word.charAt(i)-'a'];
        }
        if(!cur.isWord)
            cur.isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        Node cur = root;
        return match(cur, word, 0);
    }

    private boolean match(Node cur, String word, int index){
        if(index == word.length())
            return cur.isWord;
        
        if(word.charAt(index) != '.'){
            if(cur.next[word.charAt(index)-'a']==null)
                return false;
            return match(cur.next[word.charAt(index)-'a'], word, index+1);
        }else{
            // 通配符, 遍历所有子节点
            for(Node p: cur.next){
                if(p != null){
                    if(match(p, word, index+1))
                        return true;
                }
            }
            return false;
        }
    }

    private class Node{
        public boolean isWord;
        public Node []next = new Node[26];
    }

    private Node root;
}
```
```python []
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.rec = dict()


    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        if len(word) not in self.rec.keys():
            self.rec[len(word)] = [word]
        else:
            self.rec[len(word)] += [word]


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        L = len(word)
        if L not in self.rec.keys():
            return False
        # 去重
        wordset = set(self.rec[L])
        for i in range(L):
            if word[i] == '.':
                continue
            else:
                delSet = set()
                for w in wordset:
                    if w[i] != word[i]:
                        delSet.add(w)
                wordset = wordset-delSet
                if(len(wordset))==0:
                    return False
        return len(wordset) > 0
```