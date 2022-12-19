### 解题思路
1. 按单词长度从大到小排序后进行插入, 考虑非结尾的情况
2. Trie
3. 后缀删除法

### 代码

**插入法**
```c++ []
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int N = words.size();
        if(N == 0)
            return 0;
        if(N == 1)
            return words[0].size()+1;
        
        sort(words.begin(), words.end(), [&](string s1, string s2){
            return s1.size()>s2.size();
        });

        string res = "";
        for(int i=0; i<N; ++i){
            int index = res.find(words[i]);
            bool flag = false;
            while(index != -1){
                if(res[index + words[i].size()]=='#'){
                    flag = true;
                    break;
                }
                else{
                    // 需要继续查询
                    index = res.find(words[i], index+1);
                }
            }
            if(!flag)
                res += (words[i]+"#");
        }

        return res.size();
    }
};
```
**后缀删除法**
```java []
class Solution {
    public int minimumLengthEncoding(String[] words) {
        // 删除法
        HashSet<String> rec = new HashSet<>(Arrays.asList(words));
        for(String word: words){
            for(int i=1; i<word.length(); ++i){
                rec.remove(word.substring(i));
            }
        }

        int res = 0;
        for(String word: rec){
            res += (word.length()+1);
        }
        return res;
    }
}
```
```c++ []
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // 后缀删除法
        set<string> rec(words.begin(), words.end());
        for(auto &word: rec){
            for(int i=1; i<word.size(); ++i)
                rec.erase(word.substr(i));
        }

        int res = 0;
        for(auto &word: rec){
            res += word.size()+1;
        }

        return res;
    }
};
```
**Trie**
```python []
from functools import reduce
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        # 嵌套实现Trie
        words = list(set(words))
        # defaultdict注册, 只有在调用时才会调用构造函数
        Trie = lambda: collections.defaultdict(Trie)
        root = Trie()
        # reduce(func, data)的使用, 将word插入到Trie中, 其中dict.__getitem__仍然返回一个dict
        nodes = [reduce(dict.__getitem__, w[::-1], root) for w in words]
        # nodes[i]表示第i个单词在Trie中的插入情况, len(nodes[i])==0表示为一个新词
        return sum(len(w)+1 for i, w in enumerate(words) if len(nodes[i])==0)
```
```c++ []
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // Trie
        // 排序
        sort(words.begin(), words.end(), [&](string s1, string s2){
            return s1.size()>s2.size();
        });
        Trie *root = new Trie();
        for(auto word: words){
            reverse(word.begin(), word.end());
            root->add(word);
        }
        return root->getCount();
    }

private:
    class Node{
    public:
        bool isWord;
        map<char, Node*> next;
        Node(){
            this->isWord = false;
        }
    };

    class Trie{
    public:
        Trie(){
            this->root = new Node();
        }
        // 添加单词存储
        void add(string &word){
            Node *cur = root;
            for(char &c: word){
                if(cur->next.find(c) == cur->next.end()){
                    cur->next[c] = new Node();
                    cur->isWord = true;
                }
                cur = cur->next[c];
            }
            if(!cur->isWord){
                cur->isWord = true;
                this->cnt += (word.size()+1);
            }
        }

        int getCount(){
            return this->cnt;
        }

    private:
        Node *root;
        int cnt = 0;
    };
};
```