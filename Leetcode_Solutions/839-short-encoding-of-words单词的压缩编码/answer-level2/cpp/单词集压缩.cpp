### 解题思路
本题是可以用集合unorder_map来做，先根据words建立单词库，然后每个单词用substr遍历，看单词库里是否有相同的
有就删除，没有就+单词数再+1。不过时间消耗太高；

另一种对付大数量字符串的方法是建立字符树，即把每个单词通过26叉树的形式组织起来，每个子树表示单词的一个字，为了
能够实现重复的后缀单词不被计数，我们可以利用树中单词未出现（即录入某一树节点时节点为nullptr)来进行计数。由于判断
的是后缀重复，所以需要把word反向输入进树。

代码部分：一个是sort函数需要注意，判断语句不能写成>= 不知道为啥= =
    另一个是

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), 
                [](const string &lhs, const string &rhs) ->bool {
                    return lhs.size() > rhs.size();
                }
        );
        int ans = 0;
        Trie* wordTrie = new Trie();

        for(string word:words){
            ans += wordTrie->insert_letter(word);
        }
        return ans;
    }
private:
    class TrieNode{
    private:
        string s;
    public:
        TrieNode* children[26];
        TrieNode(){            
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
        }
    };

    class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }
        int insert_letter(string word){
            bool is_new =false;
            TrieNode* cur_node = root;
            for(int i = word.size()-1;i>=0;i--){
                if (cur_node->children[word[i]-'a'] == nullptr){
                    cur_node->children[word[i]-'a'] = new TrieNode();
                    is_new = true;
                }
                cur_node = cur_node->children[word[i]-'a'];
            }
            return is_new? word.size()+1:0;
        }
    };
};
```