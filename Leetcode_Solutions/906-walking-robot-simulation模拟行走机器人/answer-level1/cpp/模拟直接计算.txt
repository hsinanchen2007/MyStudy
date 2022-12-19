```
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<int,vector<int>> mpx,mpy;
        for(auto o:obstacles)
        {
            mpx[o[0]].push_back(o[1]);
            mpy[o[1]].push_back(o[0]);
        }
        for(auto x:mpx)
        {
            sort(x.second.begin(), x.second.end());
        }
        for(auto y:mpy)
        {
            sort(y.second.begin(), y.second.end());
        }
        int x = 0;
        int y = 0;
        int d = 1;
        vector<vector<int>> mpd = {{1,0},{0,1},{-1,0},{0,-1}};
        int md = 0;
        for(auto c:commands)
        {
            if(c == -2)
            {
                d = (d+1) % 4;
            }
            else if(c == -1)
            {
                if(d==0)
                    d = 4;
                d = (d-1) % 4;
            }
            else if(c>=1 && d<=9)
            {
                if(mpd[d][1] == 0)
                {
                    x = stepx(mpd[d][0], mpy, y, x, c);
                }
                else
                {
                    y = stepx(mpd[d][1], mpx, x, y, c);
                }
                md = max(md, x*x+y*y);
            }
        }
        return md;
    }
    bool between(int x, int y, int z)
    {
        return ((x<z && z<=y) || (y<=z && z<x));
    }
    int stepx(int dx, map<int, vector<int>>& mpy, int y, int x, int step)
    {
        auto iter = mpy.find(y);
        if(iter == mpy.end())
        {
            x += dx * step;
        }
        else
        {
            int lx = x + dx * step;
            for(auto i:iter->second)
            {
                if(between(x,lx,i))
                {
                    lx = i - dx;
                    if(dx == -1)
                    {
                        break;
                    }
                }
            }
            x = lx;
        }
        return x;
    }

};
```
