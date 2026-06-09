### 传统前缀树模板
![](https://pic.leetcode-cn.com/0cddad836ee9a200b150a3d89f96035f44f3643c4fba0cb1f329e2307c714895-file_1562596867185)

就像上图，节点本身包含基本两个属性一个为是否是结束标志，一个是next哈希存放下一条边，而哈希的key为下条边的值。
类似链表一样用一个root来代表一下虚拟头结点。
* 插入操作：对于传进的字符串的每一个字符，假如不存在当前字符c，就增加一条当前字符c的边。若存在当前字符，直接就跳到下一层。在最后一个边的结尾，标记isEnd = true
* 查找操作：怎么插的就怎么查找。从根节点往下找。若找不到当前字符c直接返回false，找到了继续往下找，直到找不到为止

#### 省略析构函数版本（做题）
```cpp
struct TrieNode {
    bool isEnd = false;
    unordered_map<char, TrieNode*> next;
};

class Trie {
private:
    TrieNode *root;
    
public:
    Trie(): root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode *p = root;
        for (const char c : word) {
            if (!p->next.count(c)) {
                p->next[c] = new TrieNode();
            }
            p = p->next[c];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *p = root;
        for (const char c : word) {
            if (!p->next.count(c)) {
                return false;
            }
            p = p->next[c];
        }
        return p->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (const char c : prefix) {
            if (!p->next.count(c)) {
                return false;
            }
            p = p->next[c];
        }
        return p != nullptr;
    }
};
```

#### 面试版本（有析构函数和智能指针释放内存）
```cpp
struct TrieNode {
    bool isEnd = false;
    unordered_map<char, TrieNode*> next;
    ~TrieNode() {  // 析构
        for (auto& [key, value] : next) {
            if (value) delete value;
        }
    }
};

class Trie {
private:
    std::unique_ptr<TrieNode> root;  // 智能指针
    
public:
    Trie(): root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode *p = root.get();
        for (const char c : word) {
            if (!p->next.count(c)) {
                p->next[c] = new TrieNode();
            }
            p = p->next[c];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *p = root.get();
        for (const char c : word) {
            if (!p->next.count(c)) {
                return false;
            }
            p = p->next[c];
        }
        return p->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *p = root.get();
        for (const char c : prefix) {
            if (!p->next.count(c)) {
                return false;
            }
            p = p->next[c];
        }
        return p != nullptr;
    }
};
```

### 前缀树set实现写法

* 优点代码简洁，做周赛算法竞赛数据规模小的时候可以偷懒写少点代码，比较快
* 比传统时间慢

**原理：利用了set自动通过字典序大小排序的性质。**
添加就直接加入set就可以了

主要说一下查询思路： 查询通过字典序大小，二分查找set集合中第一个字典序大小大于等于所给前缀字符串prefix的字符串，起名叫s(第一个大于等于所给前缀字符串prefix有一个性质，有**可能**是给定前缀的字符的第一个数， 要不就不是该前缀)。然后在看s是否真的是符合该前缀，如果符合就是就找到了set中第一个符合该前缀的字符。

```cpp
class Trie {
private:
    set<string> se;
public:
    Trie() {
        se.clear();
    }
    
    void insert(string word) {
        se.insert(word);
    }
    
    bool search(string word) {
        return se.count(word) > 0;
    }
    
    bool startsWith(string prefix) {
        auto it = lower_bound(se.begin(), se.end(), prefix);
        if (it == se.end() || (*it).find(prefix) != 0) return false;
        return true;
    }
};
```