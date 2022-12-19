这题真的有点难，贴下别人的代码，加上自己的注释和思路，算是个小总结
（1）主干代码沿用127题单词接龙，从上到下的BFS用以建图，使用两个关键的数据结构
```
    unordered_map<string,int> depth  记录每个节点所在高度的
    unordered_map<string,vector<string>> neighbor  记录每个节点所有它的前向变化节点集（由curr->temp，记录curr）
```
每个word所在的层，从上到下做记录。首先队列弹出curr节点，检查出和它相差一个字符的在字典wordList里的所有单词temp,之前没记录过的，更新高度：高度+1；因为curr->temp,注意我们这里记录逆向变化，不记录curr的下一层节点集，而是记录temp的所有上一层节点集
（2）从下往上的dfs搜索
第一步的bfs建图已经建好，这一步就非常简单了，常规的深度优先搜索思路。
从endword顺着neighbor中记录的状态一步步往上树形空间搜索，到达beginword时，反转一下，存入最后的res
```
void dfs(string &beginword,string &curr,vector<string> path,
             unordered_map<string,vector<string>> &neighbor, vector<vector<string>> &res)
    {
        if(curr==beginword){
            //到达了迭代终点
            path.push_back(curr);
            reverse(path.begin(),path.end());
            res.push_back(path);
            return;
        }
        //这里的path记录状态，这是c++的一个技巧，状态使用传值，则每个节点都是一个全新的状态，无需状态重置。
        path.push_back(curr);
        for(auto word:neighbor[curr]){
            //对于邻接节点
            dfs(beginword,word,path,neighbor,res);
        }
        
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)     
    {
        //两个关键的数据结构，每个节点的邻接节点（每个节点的下一层节点，只相差一个字符的）
        //存储每个节点所在的深度
        /*
        1)先使用BFS"建图"，在搜索过程中记录信息
        */
        vector<vector<string>> res;
        vector<string> path;
        if(std::find(wordList.begin(),wordList.end(),endWord)==wordList.end())    return res;
        
        unordered_map<string,int> depth;
        unordered_map<string,vector<string>> neighbor;
        //convert vector into hashset,or use boolean matrix
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        //vector<int> visited(wordList.size(),0);
        
        //BFS to get words neighbors(only next layers neighbors)
        depth[beginWord]=1;
        queue<string> Q;
        Q.push(beginWord);
        //从begin到end建图
        while(!Q.empty()){
            string curr=Q.front();
            Q.pop();
            for(int i=0;i<curr.size();++i){
                string temp=curr;
                for(char c='a';c<='z';++c){
                    temp[i]=c;
                    if(wordSet.count(temp)){
                        //如果修改的这个temp是被包含的,再字典里面
                        if(depth.count(temp)==0){
                           //这个temp还没被添加进neighbor
                            Q.push(temp);
                            depth[temp]=depth[curr]+1;//update depth map
                            neighbor[temp].push_back(curr);
                        }else if(depth[temp]==depth[curr]+1){
                            neighbor[temp].push_back(curr);
                        }
                    }
                }
            }
        }
        dfs(beginWord,endWord,path,neighbor,res);
        return res;
    }
```
