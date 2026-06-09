```
/*
 * 虽然仍然是超时，但是仍然记录一下思路。尤其是对Trie前缀树的操作中，增加pulle_index[]用来记录所有以当前前缀为前缀的单词，可用于其他场景
 *
 * 核心思想是如果a为b的前缀，那么如果i属于a，则必然有i属于b
 *
 * 1. 按照puzzle的首字母建立26棵Trie树，并将对应的puzzle正序后插入Trie
 *      -- 原因是word必须要含有该puzzle的首字母，因此需要将puzzle按照其首字母进行归纳，建立不同的Trie树
 *      -- Trie树中的结点会记录以从root到当前结点的前缀为前缀的所有puzzle的index
 * 2. 将words中所有的word进行正序，并去重
 * 3. 使用正序并去重的word，在所有其word中字母所对应的Trie树中查找word
 *      当能够找到word时(str_index == str.size()),表示Trie树中存在以该word为前缀的puzzle，其列表存在于当前结点的puzzle_index中
 *
 * W = words.size();    K_w为word的最大长度
 * P = puzzles.size();  K_p为puzzle的最大长度，本处为7，常数
 * 时间复杂度=O(P*K_p*logP)+P(W*K_w*logW)+O(W*K_w*logP)
 */
const int SIZE = 26;

struct TrieNode{
    bool isword;
    int prefix_word_counter;
    TrieNode* next[SIZE];
    vector<int> puzzle_index;  // 记录所有以当前前缀为前缀的单词puzzle的下标
    TrieNode():isword(false), prefix_word_counter(0){}
};

class Trie{
private:
    TrieNode *root;
    char start;

public:
    Trie(char _start):start(_start){
        root = new TrieNode();
        for(int i = 0; i < SIZE; i++){
            root->next[i] = NULL;
        }
    }

    void insert_word(string &str){
        TrieNode *p = root;
        for(char i : str){
            int cur_index = i - 'a';
            if(p->next[cur_index] == NULL){
                auto *node = new TrieNode();
                node->isword = false;
                node->prefix_word_counter = 1;
                for(int i = 0; i < SIZE; i++){   // 注意: 有的编译器在创建指针后不会自动置NULL， 因此最好手动设置一下
                    node->next[i] = NULL;
                }
                p->next[cur_index] = node;
            }
            p->prefix_word_counter++;
            p = p->next[cur_index];
        }
        p->isword = true;
    }

    void insert_word(string &str, int word_index){
        TrieNode *p = root;
        for(char i : str){
            int cur_index = i - 'a';
            if(p->next[cur_index] == NULL){
                auto *node = new TrieNode();
                node->isword = false;
                node->prefix_word_counter = 1;
                for(int i = 0; i < SIZE; i++){
                    node->next[i] = NULL;
                }
                p->next[cur_index] = node;
            }
            p = p->next[cur_index];
            p->prefix_word_counter++;
            p->puzzle_index.push_back(word_index);
        }
        p->isword = true;
    }

    TrieNode *root_node(){
        return this->root;
    }

    bool search(const string &str){
        // TODO::
        return true;
    }
};

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        if(words.empty() || puzzles.empty()) return vector<int>();
        vector<Trie*> hash_trie(SIZE, NULL);
        for(int i = 0; i < SIZE; i++) {
            hash_trie[i] = new Trie('a'+i);
        }
        for(int i = 0; i < puzzles.size(); i++){
            string temp = puzzles[i];
            sort(temp.begin(), temp.end());
            hash_trie[puzzles[i][0]-'a']->insert_word(temp, i);
        }

        vector<int> ans(puzzles.size(), 0);
        for(const string& word: words){
            string temp = word;
            sort(temp.begin(), temp.end());
            shrink(temp);
            for(char c: temp){
                handle(hash_trie[c-'a']->root_node(), temp,0, ans);
            }
        }
        return ans;
    }

    void shrink(string &str){
        int left = 0, right = 1;
        while(right < str.size()){
            if(str[left] == str[right]){
                right++;
            }else{
                str[++left] = str[right++];
            }
        }
        str.resize(left+1);
    }

    void handle(TrieNode *p, const string& str, int str_index, vector<int> &ans){
        if(p == NULL) return;
        if(str_index == str.size()){
            for(const int &ind: p->puzzle_index){
                ans[ind]++;
            }
            return;
        }
        char cur_char = str[str_index];
        for(int i = 0; i < (cur_char-'a'); i++){
            handle(p->next[i], str, str_index, ans);
        }
        handle(p->next[cur_char-'a'], str, str_index+1, ans);
    }
};
```