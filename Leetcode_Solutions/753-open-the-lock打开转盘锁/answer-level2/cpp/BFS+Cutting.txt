Use BFS and cutting algorithm to solve this problem. We can regard it as a searching in a graph. Comparing to DFS algorithm, the BFS can get the closest point nead the top.

```cpp
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Initialization
        string init="0000";
        char flag_1='9'+1;
        char flag_2='0'-1;
        // Use unordered_map rather than set to speed up the searching process
        unordered_set<string>dead(deadends.begin(),deadends.end());
        unordered_set<string>visited;
        int min_length=INT_MAX;
        // set initial string visited
        visited.insert(init);
        
        // build a queue that store the pair of integer which means its depth and string which means its string content
        queue<pair<int,string>>que;
        que.push({0,init});
        if(dead.find(init)!=dead.end())return -1;
        
        // Now begin BFS and cut tree
        while(!que.empty()){
            auto top_value=que.front();
            que.pop();
            // if top_value is the answer and its depth is smaller than current minimum length
            // replace the minimum length with its depths. 
            if(top_value.second==target && top_value.first<min_length){
                min_length=top_value.first;
            }
            // Cutting it 
            if(top_value.first>min_length){
                continue;
            }
            for(unsigned i=0;i<4;i++){
                // each character plus one or minus one.
                string str_plus=top_value.second;
                string str_minus=top_value.second;
                str_plus[i]+=1;
                str_minus[i]-=1;
                // In case the cross the bound from '0' to '9'
                if(str_plus[i]==flag_1){
                    str_plus[i]='0';
                }
                if(str_minus[i]==flag_2){
                    str_minus[i]='9';
                }
                // We also can combine the "dead" and the "visited", but it would be confusing.
                if(dead.find(str_plus)==dead.end()&&visited.find(str_plus)==visited.end()){
                    que.push({top_value.first+1,str_plus});
                    visited.insert(str_plus);
                }
                if(dead.find(str_minus)==dead.end()&&visited.find(str_minus)==visited.end()){
                    que.push({top_value.first+1,str_minus});
                    visited.insert(str_minus);
                }
            }
        }
        return min_length==INT_MAX?-1:min_length;
        
    }
};
```