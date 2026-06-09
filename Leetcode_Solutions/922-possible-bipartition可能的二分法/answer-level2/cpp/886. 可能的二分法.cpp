```
class Solution {
public:
    vector<vector<int>> tmp;
    vector<int> color;

    bool draw(int idx, int cl)
    {
        if(color[idx]==0)
        {
            color[idx]=cl;
            int cl1=3-cl;
            for(int i=0;i<tmp[idx].size();++i)
            {
                if(!draw(tmp[idx][i],cl1))return false;
            }
        }
        else if(color[idx]!=cl)
        {
            return false;
        }

        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int n=dislikes.size();
        tmp = vector<vector<int>>(N,vector<int>());

        for(int i=0;i<n;++i)
        {
            int id1=dislikes[i][0]-1;
            int id2=dislikes[i][1]-1;
            tmp[id1].push_back(id2);
            tmp[id2].push_back(id1);
        }

        //0未处理, 1分组1,2分组2,3没有不喜欢的
        color = vector<int>(N,0);
        for(int i=0;i<N;++i)
        {
            if(tmp[i].empty())
            {
                color[i]=3;
            }
            else if(color[i]==0)
            {
                if(!draw(i,1))return false;
            }
        }

        return true;
    }
};
```
