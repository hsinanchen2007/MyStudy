### 解题思路
本质是深搜，我们通过在搜的过程中去掉遍历过的结点来保证不会重复搜索，第一次碰到终点时，这个肯定是最远的位置，我们存为答案后回溯，之后每次的终点都比上一个终点要近（因为我们在搜的过程中边搜边去掉结点），所以依次存入就可以得到路径，最后逆序即可。
["JFK","NRT","JFK","KUL"]这组举例：
JFK先到KUL，KUL无后继结点，所以是终点，存入结果，回溯到JFK，JFK到NRT，NRT到JFK，JFK无后继结点，所以是倒数第二个终点，回溯，NRT无后继结点，所以是倒数第三个终点，回溯，JFK无后继结点，所以是倒数第四个终点。
也即我们认为出度为0的结点就是终点，每深入一次，我们就把当前结点的出度减1。

### 代码

```cpp
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        if(tickets.size() == 0)
            return ans;
        sort(tickets.begin(), tickets.end());
        unordered_map<string, list<string> > mp;
        for(int i = 0 ; i < tickets.size() ; ++i)
            mp[tickets[i][0]].push_back(tickets[i][1]);
        if(!mp.count("JFK"))
            return ans;
        stack<string> ss;
        ss.push("JFK");
        while(!ss.empty())
        {
            string f = ss.top();
            if(mp.count(f) && !mp[f].empty())
            {
                ss.push(mp[f].front());
                mp[f].pop_front();
            }
            else
            {
                ans.push_back(f);
                ss.pop();
            }
        }
        return vector<string>(ans.rbegin(), ans.rend());
    }
};
```