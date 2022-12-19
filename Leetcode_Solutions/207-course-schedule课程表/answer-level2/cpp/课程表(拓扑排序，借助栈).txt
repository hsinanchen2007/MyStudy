### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        return TopoSort(prerequisites,numCourses);
    }

    //拓扑排序
    bool TopoSort(vector<vector<int>>& proj,int num)
    {
        vector<int> temp,ID(num,0); //ID保存顶点入度
        vector<vector<int>> vex(num,temp);  //保存顶点的所有下一个顶点
        stack<int> s;
        int fin=0;

        for(int i=0;i<proj.size();i++) 
        {
            ID[proj[i][0]]++;
            vex[proj[i][1]].push_back(proj[i][0]);
        }
        for(int i=0;i<num;i++) if(ID[i]==0) s.push(i);

        while(!s.empty())
        {
            int pre=s.top();
            s.pop();
            fin++;

            for(int i=0;i<vex[pre].size();i++)
            {
                ID[vex[pre][i]]--;
                if(ID[vex[pre][i]]==0) s.push(vex[pre][i]);
            }
        }

        return fin==num ? true:false;
    }
};
```