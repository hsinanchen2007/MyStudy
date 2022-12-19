### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
* 应用：自动补全、给字符串按字典序排序
* 优势：1、找到具有同一前缀的全部键值。2、按词典序枚举字符串的数据集。
*/

class Trie {
private:
    // 最多R个指向子节点的链接，其中每个链接对应字母表数据集中的一个字母，这里取26个英文字母，R=26。
	Trie *child[26];
    // 指定节点是对应键的结尾还是只是键前缀
    bool isWord;
public:
    /** Initialize your data structure here. */
    // 构造函数
    Trie() {
        isWord = false;
        for (int i=0;i<26;i++) {
            child[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    // 插入键 时间复杂度O(m)，m为键长。空间复杂度O(m)，最坏的情况下新插入的键没有公共前缀。
    // 通过搜索Trie树来插入键。从根开始搜索它对应于第一个键字符的链接。
    void insert(string word) {
        // 用于指向每一层节点，进行搜索的操作。
        Trie *t = this;
        // 遍历插入键的每一个字符
        for(char c: word){
            // 如果链接不存在，创建一个新节点，并将它与父节点的链接相连，该链接与当前的键字符相匹配
            if (!t -> child[c-'a']) {
                t->child[c-'a'] = new Trie();
            }
            // 链接存在，沿着链接移动到树的下一个子层。算法继续搜索下一个键字符
            t = t->child[c-'a'];
        }
        // 直到到达键的最后一个字符，然后将当前节点标记为结束节点。此时的当前节点已经移动到键的最后字符所在的节点
        t->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    // 查找键 时间复杂度O(m)，最坏的情况下m为键长。空间复杂度O(1)
    bool search(string word) {
        // 用于指向每一层节点，进行搜索的操作。
        Trie *t = this;
        // 遍历查找键的每一个字符
        for (char c:word) {
            // 如果链接不存在，查找失败
            if (!t -> child[c - 'a']) {
                return false;
            }
            // 链接存在，沿着链接移动到树的下一个子层。算法接续查找下一个键字符。
            t = t->child[c - 'a'];
        }
        // 直到到达最后一个字符，返回该键字符节点的isWord，如果为false，待查键是Trie树中另一个键的前缀。
        return t->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    // 查找Trie树中的键前缀
    bool startsWith(string prefix) {
        // 用于指向每一层节点，进行搜索的操作。
        Trie *t = this;
        // 遍历查找前缀的每一个字符
        for (char c:prefix) {
            // 如果链接不存在，查找失败
            if (!t->child[c-'a']) {
                return false;
            }
            // 链接存在，沿着链接移动到树的下一个子层。算法接续查找下一个键字符。
            t = t->child[c - 'a'];
        }
        // 直到到达最后一个字符，由于是查找前缀，而不是整个键，所以返回true
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */



#include <iostream>
#include <string>

using namespace std;

class Trie {
private:
	Trie *child[26];
    bool isWord;
public:
    Trie() {
        isWord = false;
        for (int i=0; i<26; i++) {
            child[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie *t = this;
        for (char c: word){
            if (!t -> child[c-'a']) {
                t->child[c-'a'] = new Trie();
            }
            t = t->child[c-'a'];
        }
        t->isWord = true;
    }
    
    bool search(string word) {
        Trie *t = this;
        for (char c:word) {
            if (!t -> child[c - 'a']) {
                return false;
            }
            t = t->child[c - 'a'];
        }
        return t->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie *t = this;
        for (char c:prefix) {
            if (!t->child[c-'a']) {
                return false;
            }
            t = t->child[c - 'a'];
        }
        return true;
    }
};

int main() {
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;
    cout << trie->search("app") << endl;
    cout << trie->startsWith("app") << endl;
    trie->insert("app");
    cout << trie->search("app") << endl;
    cout << "true:" << true << endl;
    cout << "false:" << false << endl;
}



```