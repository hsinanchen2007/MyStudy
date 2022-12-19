```
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        vector<int> res(n,0);
        stack<pair<int,int>> stk;
        
        for(string log : logs)
        {
            istringstream ss(log);
            string s1,s2,s3;
            getline(ss,s1,':');
            getline(ss,s2,':');
            getline(ss,s3,':');
            
            int id=stoi(s1);
            string action=s2;
            int time=stoi(s3);
            
            if(action=="start")
            {
                if(!stk.empty())
                   res[stk.top().first]+=time-stk.top().second;
                stk.push({id,time});
            }
            else
            {
                pair<int,int> p=stk.top();
                stk.pop();
                
                res[p.first]+=time-p.second+1;
                if(!stk.empty())
                    stk.top().second=time+1;
            }
            
        }
        
        return res;
    }
};
```
