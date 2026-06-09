### 解题思路

官方题解用了字典记录可能的临近词，还有的用了位运算。然而我比较菜，就只会傻傻的的计算每个词和其他词的距离

用wordDist挨个比较两个词的每个字母是否相同，不同就加1。

接着用findAdj 根据给定的target，挨个计算和wordList的距离，就得到了每个单词的可能选择。

```cpp
    //计算两个单词之间的距离
    int wordDist(const string& w1, const string &w2){
        int cnt = 0;
        for (int i = 0; i < w1.size(); i++){
            if (w1[i] != w2[i]) cnt++;
        }
        return cnt;
    }
    //寻找当前单词的所有邻接单词
    vector<string> findAdj(string& target, vector<string>& wordList){
        vector<string> res;
        for (const auto& word : wordList){
            if(wordDist(target, word) == 1){
                res.push_back(word);
            }
        }
        return res;
```

于是题目就可以用BFS进行实现，（想不到双向BFS），每次把可能选择加入nde(临近单词队列)中。(需要有一个set记录访问记录)

```cpp
            for (auto e : findAdj(str, wordList)){
                if ( e == endWord) return cnt + 2; //临近词就是结束
                if (visited.find(e) == visited.end() ){ //没有访问
                    visited.insert(e);
                    nde.push_back(e);
                }
            }
```

下一次遍历时，因为de空了，那就把nde和de交换，

```cpp
            if (de.empty()){
                swap(de, nde);
                cnt++;
            }
```

于是又可以遍历de，找到de中每个单词的可能接触对象，直到接触对象刚好就是最终的单词，我们就可以结束了。

```cpp
if ( e == endWord) return cnt + 2; //临近词就是结束
```

或者，我们把所有的wordList都访问了，也就是队列空了，那么也可以结束了。

```cpp
while( ! de.empty () || ! nde.empty() )
```


### 代码

```cpp
class Solution{
private:
    //计算两个单词之间的距离
    int wordDist(const string& w1, const string &w2){
        int cnt = 0;
        for (int i = 0; i < w1.size(); i++){
            if (w1[i] != w2[i]) cnt++;
        }
        return cnt;
    }
    //寻找当前单词的所有邻接单词
    vector<string> findAdj(string& target, vector<string>& wordList){
        vector<string> res;
        for (const auto& word : wordList){
            if(wordDist(target, word) == 1){
                res.push_back(word);
            }
        }
        return res;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        //双向BFS,需要两个队列
        deque<string> de;
        deque<string> nde;
        //记录访问过的节点
        unordered_set<string> visited;

        //加入第一个节点
        de.push_back(beginWord);
        visited.insert(beginWord);

        int cnt = 0;
        while( ! de.empty () || ! nde.empty() ){
            if (de.empty()){
                swap(de, nde);
                cnt++;
            }
            //出队，获取当前word
            auto str = de.front();
            de.pop_front();
            //找到当前单词的所有临近词
            for (auto e : findAdj(str, wordList)){
                if ( e == endWord) return cnt + 2; //临近词就是结束
                if (visited.find(e) == visited.end() ){ //没有访问
                    visited.insert(e);
                    nde.push_back(e);
                }
            }
        }
        return 0;
        
    }
};
```