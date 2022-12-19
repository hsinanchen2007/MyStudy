我怎么觉得答案有问题，我用了两个不同commands是直行，预计答案都是5140，但是这两个commands的终点明显是不一样的。
```
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> o;
        int x(0),y(0),d(0);
        for(int i=0;i<obstacles.size();i++){
            o.insert(pair<int,int>(obstacles[i][0],obstacles[i][1]));
        }
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1)
                d = (d+1)%4;
            else if(commands[i]==-2)
                d = (d+3)%4;
            else{
                for(int j=1;j<=commands[i];j++){
                    if(d==0){
                        if(o.find(pair<int,int>(x,y+1))==o.end())
                            y++;
                        else
                            continue;
                    }
                    else if(d==1){
                        if(o.find(pair<int,int>(x+1,y))==o.end())
                            x++;
                        else
                            continue;
                    }
                    else if(d==2){
                        if(o.find(pair<int,int>(x,y-1))==o.end())
                            y--;
                        else
                            continue;
                    }
                    else if(d==3){
                        if(o.find(pair<int,int>(x-1,y))==o.end())
                            x--;
                        else
                            continue;
                    }

                }
            }
        }
        return x*x+y*y;
    }
};
```

