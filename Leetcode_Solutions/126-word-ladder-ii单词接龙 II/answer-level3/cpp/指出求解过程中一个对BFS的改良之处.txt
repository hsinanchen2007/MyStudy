没做过单词接龙I的先移步看I的官方解法。

根据I的官方解法思想，我们将问题抽象在一个无向无权图中，每个单词作为节点，差距只有一个字母的两个单词之间连一条边。问题变成找到从起点到终点的最短路径，如果存在的话。因此可以使用广度优先搜索方法。

# 相邻结点的表示
算法中最重要的步骤是找出相邻的节点，也就是只差一个字母的两个单词。为了快速的找到这些相邻节点，我们对给定的 wordList 做一个预处理，将单词中的某个字母用`*` 代替。这个预处理帮我们构造了一个单词变换的通用状态。例如：`Dog ----> D*g <---- Dig`，`Dog` 和 `Dig` 都指向了一个通用状态`D*g`。即`Hash(D*g)={Dog,Dig}`

这步预处理找出了单词表中所有单词改变某个字母后的通用状态，并帮助我们更方便也更快的找到相邻节点。否则，对于每个单词我们需要遍历整个字母表查看是否存在一个单词与它相差一个字母，这将花费很多时间。预处理操作在广度优先搜索之前高效的建立了邻接表。

例如，在广搜时我们需要访问 `Dug` 的所有邻接点，我们可以先生成 `Dug` 的所有通用状态：
```
Dug => *ug
Dug => D*g
Dug => Du*
```
第二个变换 `D*g` 可以同时映射到 `Dog` 或者 `Dig`，因为他们都有相同的通用状态。拥有相同的通用状态意味着两个单词只相差一个字母，他们的节点是相连的。 

这部分对应了代码中的`std::unordered_map<string,std::vector<Word*>> map;`
要构建上面的map，操作如下：
```
struct Word
{
    string word;
    bool used;
    int level;
    std::vector<Word*> father;
    Word(const string& in)
    {
        word=in;
        used=false;
        level=0;
    }

};
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    std::vector<Word> words;
    if(find(wordList.begin(),wordList.end(),beginWord)==wordList.end())
        wordList.push_back(beginWord);
    for (std::vector<string>::iterator i = wordList.begin(); i != wordList.end(); ++i)
    {
        words.push_back(Word(*i));
    }
    Word* begin=NULL;
    for(int i=0;i<words.size();i++)
        if(words[i].word==beginWord)
            begin=&words[i];
    Word* end=NULL;
    for(int i=0;i<words.size();i++)
        if(words[i].word==endWord)
            end=&words[i];
    if(end==NULL)
        return res;

    std::unordered_map<string,std::vector<Word*>> map;
    for (int i = 0; i < words.size(); ++i)
    {
        for (int j = 0; j < words[i].word.size(); ++j)
        {
            char c='*';
            swap(c,words[i].word[j]);
            string tmp=words[i].word;
            swap(c,words[i].word[j]);
            map[tmp].push_back(&words[i]);

        }
    }
```

# 如何找到所有的最短路径？
首先，记录下每个单词的前驱，这样，就可以从最后一个单词的前驱，逐渐追溯到到达第一个单词的路径们。多个路径往往意味着某些单词的前驱不唯一，这种不唯一表现为：一个词很可能有多个前面的词转化过来的。

比如tex 可以同时由ted和rex转化而来，对于这种情况，如果由ted遍历到了tex，是不能就此停止的，即**此时不能根据宽度优先遍历的原则——停止从rex到tex的访问过程，而是应该允许一个结点被多次访问的情况发生**。
即将BFS中的从`if(!visited[v->next]) queue.push(v->next);`类似的规则，
改成`if(!visited[v->next] || v->next.level==v->level+1 ) queue.push(v->next);`这种规则，
即**增加一个结点可以被多次访问的规则**。在实际中不需要让这个结点多次进队列，但是需要记录下这个单词的多个前驱。

所以，**这里虽然是借助了BFS的思想，但实际上并不是一个BFS的过程，因为有的结点并不只是被访问了一次**。

记录每个单词前驱的过程如下
```

std::queue<Word*> queue;
queue.push(begin);
begin->used=true;
begin->level=1;
int min_level=INT_MAX;
while(!queue.empty())
{
    Word* node=queue.front();
    queue.pop();
    if(node->word==endWord)
    {
        if(node->level<min_level)
        {
            min_level=node->level;
        }
    }
    if(node->level>min_level)
       break;
    for (int i = 0; i < node->word.size(); ++i)
    {
        char c='*';
        swap(c,node->word[i]);
        string tmp=node->word;
        swap(c,node->word[i]);
        for (int j = 0; j < map[tmp].size(); ++j)
        {
            if (!map[tmp][j]->used || map[tmp][j]->level==node->level+1)
            {//同层可以重复访问    
                if(!map[tmp][j]->used)
                   queue.push(map[tmp][j]);
                map[tmp][j]->used=true;
                map[tmp][j]->level=node->level+1;
                map[tmp][j]->father.push_back(node);
            }
        }

    }
}  
```

# 记录的前驱如何找到具体的路径们
注意，这里的记录了每个结点的前驱们，那么，从最后一个点出发，能到第一个单词的一条路就是一个答案，那么，我们深度遍历每一条路，就能找到所有的答案了。也就是说找答案的过程是一个深度优先搜索[DFS]的过程。还有一个注意的事情，我们是从最后到第一个单词，找到的答案需要倒过来，才是从第一个单词到最后一个单词的转换过程。

```
 void dfs(Word* node,const string& endWord,std::vector<string>& tmp,std::vector<vector<string>> &res)
 {
     if(tmp.empty())
        tmp.push_back(node->word);
     if(node->word==endWord)
     {
        res.push_back(tmp);
        reverse(res.back().begin(),res.back().end());
        return;
     }    			
     for (int i = 0; i < node->father.size(); ++i)
     {
         tmp.push_back(node->father[i]->word);
         dfs(node->father[i],endWord,tmp,res);
         tmp.pop_back();
     }
 }
```


最后，附完整代码：
```
 class Solution {
 public:
     struct Word
     {
         string word;
         bool used;
         int level;
         std::vector<Word*> father;
         Word(const string& in)
         {
             word=in;
             used=false;
             level=0;
         }

     };
     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
         vector<vector<string>> res;
         std::vector<Word> words;
         if(find(wordList.begin(),wordList.end(),beginWord)==wordList.end())
             wordList.push_back(beginWord);
         for (std::vector<string>::iterator i = wordList.begin(); i != wordList.end(); ++i)
         {
             words.push_back(Word(*i));
         }
         Word* begin=NULL;
         for(int i=0;i<words.size();i++)
             if(words[i].word==beginWord)
                 begin=&words[i];
         Word* end=NULL;
         for(int i=0;i<words.size();i++)
             if(words[i].word==endWord)
                 end=&words[i];
         if(end==NULL)
             return res;

         std::unordered_map<string,std::vector<Word*>> map;
         for (int i = 0; i < words.size(); ++i)
         {
             for (int j = 0; j < words[i].word.size(); ++j)
             {
                 char c='*';
                 swap(c,words[i].word[j]);
                 string tmp=words[i].word;
                 swap(c,words[i].word[j]);
                 map[tmp].push_back(&words[i]);

             }
         }
         std::queue<Word*> queue;
         queue.push(begin);
         begin->used=true;
         begin->level=1;
         int min_level=INT_MAX;
         while(!queue.empty())
         {
             Word* node=queue.front();
             queue.pop();
             if(node->word==endWord)
             {
                 if(node->level<min_level)
                 {
                     min_level=node->level;
                 }
             }
             if(node->level>min_level)
                break;
             for (int i = 0; i < node->word.size(); ++i)
             {
                 char c='*';
                 swap(c,node->word[i]);
                 string tmp=node->word;
                 swap(c,node->word[i]);
                 for (int j = 0; j < map[tmp].size(); ++j)
                 {
                     if (!map[tmp][j]->used || map[tmp][j]->level==node->level+1)
                     {//同层可以重复访问    
                         if(!map[tmp][j]->used)
                            queue.push(map[tmp][j]);
                         map[tmp][j]->used=true;
                         map[tmp][j]->level=node->level+1;
                         map[tmp][j]->father.push_back(node);
                     }
                 }

             }
         }    
         std::vector<string> tmp;
         dfs(end,beginWord,tmp,res);
         return res;		

     }
     void dfs(Word* node,const string& endWord,std::vector<string>& tmp,std::vector<vector<string>> &res)
     {
         if(tmp.empty())
         tmp.push_back(node->word);
         if(node->word==endWord)
         {
            res.push_back(tmp);
            reverse(res.back().begin(),res.back().end());
            return;
         }    			
         for (int i = 0; i < node->father.size(); ++i)
         {
             tmp.push_back(node->father[i]->word);
             dfs(node->father[i],endWord,tmp,res);
             tmp.pop_back();
         }
     }
 };
```

这个题目折腾了我三天，我也是服了。。。。。。
