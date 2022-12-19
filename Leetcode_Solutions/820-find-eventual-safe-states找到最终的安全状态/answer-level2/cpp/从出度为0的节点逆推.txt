```
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nums = graph.size();
        vector<int> re;
        vector<int> outdegrees(nums, 0);
        map<int, vector<int>> src_nodes;
        for(int i = 0; i < graph.size(); i++)
        {
            outdegrees[i] = graph[i].size();
            for(auto dest:graph[i])
            {
                src_nodes[dest].push_back(i);
            }
        }
        queue<int> node_que;
        for(int i = 0; i < outdegrees.size(); ++i)
        {
            if(outdegrees[i] == 0)
            {
                node_que.push(i);
            }
        }
        while(!node_que.empty())
        {
            int curr = node_que.front();
            node_que.pop();
            re.push_back(curr);
            for(auto src: src_nodes[curr])
            {
                outdegrees[src]--;
                if(outdegrees[src] == 0)
                {
                    node_que.push(src);
                }
            }
        } 
        sort(re.begin(), re.end());
        return re;   
    }
};
```
