### 解题思路
最开始的想法：第一次做这种题想了好久都没思路，看了一眼答案，使用dfs做，并且对woldList进行处理（hit->*it,h*t,hi*）。之后按照官方答案我自己用c++实现了一遍（普通bfs和双端bfs），可能自己优化的不好，在wordlist较大的情况始终超时（本地可以）。之后参考[https://blog.csdn.net/x603560617/article/details/87992660?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task]()，他是的代码进行实现，并对其进行双端bfs的优化，执行时间从208ms提升到76ms。
下面代码我直接注释了，写这个主要就是为了记录解题过程加深印象。

### 代码

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());//用unorderset存woldList，方便后续查找，
        if(wordSet.count(endWord)==0) return 0;//wordList中没有endword，返回0
        unordered_map<string, int> pathCount{{{beginWord, 1}}};//记录每个节点的高度或者说是路径长度。
        unordered_map<string, int> pathCount_end{{{endWord, 1}}};
        queue<string> q{{beginWord}};//层次遍历用的队列，因为双端dfs，我用了两个dfs做，没看过标准答案自己想的。
        queue<string> q_end{{endWord}};
        while(!q.empty()&&!q_end.empty()){
            int q_len=int(q.size());//按层遍历，每次只遍历队列的一层，所以要记录队列每次的初始长度。
            int q_end_len=int(q_end.size());
            unordered_set<string> lev_set;//记录正向遍历过程中，该层遍历过的节点，主要作用是用来在反向遍历的时候判断是否两个遍历重合。
            for(int j=0; j<q_len; ++j)
            {
                string word=q.front();
                q.pop();
                for(int i=0; i<word.size(); ++i)
                {
                    string newWord=word;
                    for(char c='a'; c<='z'; ++c)//使用a-z对节点上字符串的每一位进行替换
                    {
                        newWord[i]=c;
                        if(wordSet.count(newWord)==1&&!pathCount.count(newWord))//如果新的字符串在wordList存在且之前没记录过，则进行
                                                                                //记录，第二个条件用来去重
                        {
                            pathCount[newWord]=pathCount[word]+1;
                            q.push(newWord);
                            lev_set.insert(newWord);//把该层的节点记录下来
                        }
                    }
                }
            }
            for(int j=0; j<q_end_len; ++j)//和之前的代码差不多，注意变量的区别即可
            {
                string word_end=q_end.front();
                if(lev_set.count(word_end))
                    return pathCount[word_end]+pathCount_end[word_end]-1;//这是两次遍历相遇的情况之一。（路径长度为偶数的时候）
                                                                         //两次层次遍历是同步进行的，所以他们相遇的时候要么是在
                                                                         //同一个层，要么就是在相邻的一层，可以自己画图体会一下。
                q_end.pop();
                for(int i=0; i<word_end.size(); ++i)
                {
                    string newWord_end=word_end;
                    for(char c='a'; c<='z'; ++c)
                    {
                        newWord_end[i]=c;
                        if(wordSet.count(newWord_end)==1&&!pathCount_end.count(newWord_end))
                        {
                            pathCount_end[newWord_end]=pathCount_end[word_end]+1;
                            if(lev_set.count(newWord_end))
                                return pathCount[newWord_end]+pathCount_end[newWord_end]-1;//这是两次遍历相遇的另一种情况。（路径长
                                                                                           //度为奇数）
                            q_end.push(newWord_end);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
```