# 单词接龙
## 基本思路
根据给定的开始和结尾的单词以及单词表构造一张图 
每个单词作为一个顶点，两个单词只有一个字母不同则连一条边 
然后从起点开始做一次BFS，同时每个点的深度需要记录下来，这时的深度就是从开始单词起，到最终单词的变化长度（每次只能改变一个字母） 
此时整张图的信息以及构建完成——每个能从开始点修改得到的单词，都有一个（因为是BFS，因此是最短的）修改长度，暂且叫做深度。 
此时我们从终点反向搜索整个修改的具体路径，这时采用的方法是递归：若一个点的相邻节点的深度==这个点-1，那么就是合法的前一步修改 
每次发现这样的点，我们就把储存搜索路径的容器复制一份，直到搜索到终点，就添加到最后的答案中去 
还有一个需要注意的地方，最后的答案需要反向输出，因为我们是从终点反向搜索回去的
## 用时
![屏幕快照 2020-03-14 下午5.44.51.png](https://pic.leetcode-cn.com/eeb802e0d3f6ceebdce8c13d2538738b598edfaaf980bf4b6cc64ce46302f950-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-14%20%E4%B8%8B%E5%8D%885.44.51.png)

## 代码
```
#include <iostream>
#include <queue>
#include <string>
#include <vector>
/*@author:黄小良
 *@description: 单词接龙2
 *@Time: 2020/03/14
 */


using namespace std;

bool determine_edge(const string &first, const string &second)
{
    int count = 0;
    for (int i = 0; i < first.size(); ++i)
    {
        if (first[i] != second[i])
            count++;
    }
    if (count > 1)
        return false;
    else
        return true;
}

struct Vertex
{
    Vertex() : in_queue(false){};
    /*data*/
    int word_id;
    vector<int> neighbor;
    bool in_queue;
};

struct Graph
{
    Graph(int n);
    ~Graph();
    void init(const vector<string> &word_list, int start_id, int end_id);
    void bfs();
    void get_final_answer(vector<vector<int>> &ans);

    /*data*/
    int vertex_num;
    Vertex *vertex;
    int *shortest_length;
    int start; //标记开始点
    int end;   //终点

  protected:
    void get_final_answer(int v_id, vector<int> &res, vector<vector<int>> &ans);
};

Graph::Graph(int n) : vertex_num(n)
{
    vertex = new Vertex[n];
    shortest_length = new int[n];
    for (int i = 0; i < n; ++i)
        shortest_length[i] = -1;

    for (int i = 0; i < vertex_num; ++i)
    {
        vertex[i].word_id = i;
    }
}

Graph::~Graph()
{
    delete[] vertex;
    delete[] shortest_length;
}

void Graph::init(const vector<string> &word_list, int start_id, int end_id)
{
    start = start_id;
    end = end_id;
    for (int i = 0; i < vertex_num; ++i)
    {
        const string &first_word = word_list[i];
        for (int j = i + 1; j < vertex_num; ++j)
        {
            const string &second_word = word_list[j];
            if (determine_edge(first_word, second_word))
            {
                vertex[i].neighbor.push_back(j);
                vertex[j].neighbor.push_back(i);
            }
        }
    }
}

void Graph::bfs()
{
    queue<int> que; //辅助队列
    que.push(start);
    shortest_length[start] = 0;
    vertex[start].in_queue = true;
    while (!que.empty())
    {
        int current_id = que.front();
        que.pop();

        const Vertex &v = vertex[current_id];
        for (int i = 0; i < v.neighbor.size(); ++i)
        {
            int neighbor_id = v.neighbor[i];
            Vertex &neighbor = vertex[neighbor_id];
            if (neighbor.in_queue)
                ;
            else
            {
                que.push(neighbor_id);
                neighbor.in_queue = true;
                shortest_length[neighbor_id] = shortest_length[current_id] + 1;
            }
        }
    }
}

void Graph::get_final_answer(vector<vector<int>> &ans)
{
    if (shortest_length[end] == -1)
        return;
    vector<int> vec;
    get_final_answer(end, vec, ans);
}

void Graph::get_final_answer(int v_id, vector<int> &res, vector<vector<int>> &ans)
{
    res.push_back(v_id);
    if (v_id == start)
    {
        ans.emplace_back(res);
        return;
    }
    //如果递归还未到终点
    const Vertex &v = vertex[v_id];
    for (int i = 0; i < v.neighbor.size(); ++i)
    {
        int neighbor_id = v.neighbor[i];
        if ((shortest_length[v_id] - shortest_length[neighbor_id]) == 1)
        {
            vector<int> vec(res);
            get_final_answer(neighbor_id, vec, ans);
        }
    }
}

class Solution
{
  public:
    vector<vector<string>> findLadders(string begin_word, string end_word, vector<string> &word_list)
    {
        vector<vector<string>> ladders;

        //先判断开始和结束单词是否在单词表里
        bool begin_in = false, end_in = false;
        int start_id;
        int end_id;
        for (int i = 0; i < word_list.size(); ++i)
        {
            const string &word = word_list[i];
            if (word == begin_word)
            {
                begin_in = true;
                start_id = i;
            }
            else if (word == end_word)
            {
                end_in = true;
                end_id = i;
            }
        }
        if (!begin_in)
        {
            word_list.push_back(begin_word);
            start_id = word_list.size() - 1;
        }
        if (!end_in)
            return ladders;

        //下面开始建图
        vector<vector<int>> ans;
        Graph graph(word_list.size());
        graph.init(word_list, start_id, end_id);
        graph.bfs();

        graph.get_final_answer(ans);

        //最后准备输出答案
        for (int vec_id=0; vec_id < ans.size(); ++vec_id)
        {
            const vector<int> &vec = ans[vec_id];
            ladders.emplace_back();
            vector<string> &ladder = ladders.back();
            for (auto crbegin = vec.crbegin(); crbegin != vec.crend(); ++crbegin)
            {
                ladder.push_back(word_list[*crbegin]);
            }
        }

        return ladders;
    }
};

int main()
{
    string begin_word = "hit";
    string end_word = "cog";
    vector<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution s;
    vector<vector<string>> ans(s.findLadders(begin_word, end_word, word_list));
    for (int i = 0; i < ans.size(); ++i)
    {
        const auto &vec = ans[i];
        for (int j = 0; j < vec.size(); ++j)
        {
            cout << vec[j] << ", ";
        }
        cout << endl;
    }
    return 0;
}
```
