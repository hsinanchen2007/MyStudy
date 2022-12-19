### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution 
{
public:
    vector<int> findOrder(int num, vector<vector<int>>& proj) 
    {
        return TopoSort(num,proj);
    }

    vector<int> TopoSort(int num,vector<vector<int>>& proj)
    {
        vector<int> plan,ID(num,0);
        vector<vector<int>> vex(num,plan);
        stack<int> s;
        int fin=0;

        for(int i=0;i<proj.size();i++) 
        {
            vex[proj[i][1]].push_back(proj[i][0]);
            ID[proj[i][0]]++;
        }
        for(int i=0;i<num;i++) if(ID[i]==0) s.push(i);

        while(!s.empty())
        {
            int pre=s.top();
            plan.push_back(pre);
            s.pop();
            fin++;

            for(int i=0;i<vex[pre].size();i++) 
            {
                ID[vex[pre][i]]--;
                if(ID[vex[pre][i]]==0) s.push(vex[pre][i]);
            }
        }

        vector<int> empty;
        return fin==num ? plan:empty;
    }
};
```