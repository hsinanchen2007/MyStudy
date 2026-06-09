### 解题思路
1
vector<vector<int>>v
for(auto i:v )sort(i.begin(),i.end());//无法影响到v
for(auto &i:v)sort(i.begin(),i.end());

2.vector和list的区别相当于数组和链表

3.由于需要找的path需要字典序最小，那么我们就在每次找邻接点的时候都先找字典序最小的那个结点，而不是全部遍历一遍，这样找到的第一条成功的路径就是最佳的。如果选最小的那个结点走不通，那么就继续选第二小的。这要求我们在dfs之前对每个结点的直连结点list进行排序。
### 代码

```cpp

class Solution {
public:
    unordered_map<string,list<string>>map;
    vector<string>finalPath;
    int EdgeNum;
    void dfs(string from,vector<string>&path,bool &flag){
        if(flag==1)
            return;
        auto adjacentNode=map[from];
        //边界处理
        //已无adjacent node,递归边界
        if(adjacentNode.size()==0){
            if(path.size()==EdgeNum){//Edge-1行程中的结点数，path还少了起始的结点，故再减1
                finalPath=path;
                flag=1;
            }
            return;
        }

        //递归核心
        for(string node:adjacentNode){
            path.push_back(node);
            map[from].pop_front();//之后的遍历不能再用边from->node
            dfs(node,path,flag);
            path.pop_back();//换个连接点，上一个的删了
            map[from].push_back(node);//回溯时重新放入
        }
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string>path;
        for(auto i:tickets)map[i[0]].push_back(i[1]);
        for(auto &i:map)i.second.sort();
        EdgeNum=tickets.size();//边数
        bool flag=0;
        dfs("JFK",path,flag);
        finalPath.insert(finalPath.begin(),"JFK");//插入起点机场
        return finalPath;
    }
};
```