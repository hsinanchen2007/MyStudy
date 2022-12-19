核心的思想还是BFS，在本题中有两个关键的点就是如何找到节点的邻居节点和如何记录已经访问过的节点。在这里，我们使用两棵字典树，一颗用于记录所有的单词来查找指定单词的邻居，一棵用来记录已经访问过的节点，具体的实现参看find_neighbors()函数和find_word()函数
```
struct tire{
    bool is_word;
    map<char,tire*> children;
    tire(){is_word=false;for(char i='a';i<='z';i++)children[i]=NULL;}
};
class Solution {
public:
    int n,m,res;
    void insert_word(string word,tire* tire_tree){
        tire *now=tire_tree;
        for(int i=0;i<m;i++){
            if(now->children[word[i]]){
                now=now->children[word[i]];
            }
            else{
                tire *new_one=new tire();
                now->children[word[i]]=new_one;
                now=new_one;
            }
        }
        now->is_word=true;
    }

    bool find_word(string word,tire* tire_tree){
        tire* now=tire_tree;
        int size=word.size();
        for(int i=0;i<size;i++){
            if(now->children[word[i]])now=now->children[word[i]];
            else return false;
        }
        return true;
    }

    void find_neighbors(string word,tire* tire_tree,vector<string> &res){
        tire* now=tire_tree;
        for(int i=0;i<m;i++){
            for(char change='a';change<='z';change++){
                if(change==word[i])continue;
                if(now->children[change]&&find_word(word.substr(i+1),now->children[change])){
                    string mid=word;
                    mid[i]=change;
                    res.push_back(mid);
                }
            }
            now=now->children[word[i]];
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n=wordList.size();
        m=beginWord.size();
        res=1;
        if(!n)return 0;
        tire *all_the_word=new tire(),*visited_word=new tire();
        insert_word(beginWord,all_the_word);
        for(string word:wordList){//将所有的单词放进字典树中
            insert_word(word,all_the_word);
        }
        if(!find_word(endWord,all_the_word))return 0;
        //BFS一贯的套路代码
        queue<string> word_queue;
        word_queue.push(beginWord);
        insert_word(beginWord,visited_word);
        while(!word_queue.empty()){
            res++;
            int queue_size=word_queue.size();
            for(int i=0;i<queue_size;i++){
                vector<string> neighbors;
                string now_word=word_queue.front();
                word_queue.pop();
                find_neighbors(now_word,all_the_word,neighbors);
                for(auto neighbor:neighbors){
                    if(find_word(neighbor,visited_word))continue;
                    if(neighbor==endWord)return res;
                    word_queue.push(neighbor);
                    insert_word(neighbor,visited_word);
                }
            }
        }
        return 0;
    }
};
```
