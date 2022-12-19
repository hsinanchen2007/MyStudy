受@pwrliang 的题解启发， 用C++实现了一遍
详情请参照
https://leetcode-cn.com/problems/reconstruct-itinerary/solution/javadfsjie-fa-by-pwrliang/

```cpp
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 构造邻接链表， from => to, 
        // 因为 to 可能会出现多次， 所以要用multiset, 
        // priority_queue 也可以， 可能更快， 但写起来麻烦些
        map<string, multiset<string>> adj; 
        for(auto & t: tickets){
            adj[t[0]].insert(t[1]);
        }
        // 节点反向插入结果集， 
        deque<string> itinerary;
        dfs(adj, "JFK", itinerary);
        return vector<string>(itinerary.begin(), itinerary.end());
    }
    void dfs(map<string, multiset<string>> & adj, const string & from, deque<string> & itinerary){
        auto & nbr = adj[from];
        while(!nbr.empty()){
            string to = *nbr.begin();
            nbr.erase(nbr.begin());
            dfs(adj, to, itinerary);
        }
        itinerary.push_front(from);
    }
};
```