```
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0,y=0;
        int forward=0;//方向
        int max_distance=0;//最大距离
        map<int,vector<vector<int>> > p;//基于障碍点的x坐标的map
        map<int,vector<vector<int>> > q;//基于障碍点的y坐标的map
        for(int i=0;i<obstacles.size();i++){
            vector<vector<int>> a;
            p.insert(make_pair(obstacles[i][0],a));
            q.insert(make_pair(obstacles[i][1],a));
        }
        
        for(vector<int> i:obstacles){
            p[i[0]].push_back(i);
            q[i[1]].push_back(i);
        }
        
        
        for(int i:commands){
            if(i==-1){
                forward=(forward+1)%4;//向右转
            }
            else if(i==-2){
                forward=(forward+3)%4;//向左转
            }
            else{
                if(forward==0){//向北方向
                    bool flag=false;
                    int min_y=0;
                    for(int j=0;j<p[x].size();j++){     //对相同x坐标的障碍点遍历
                        if(((p[x][j][1]>y)&&(p[x][j][1]<=y+i))){
                            if(flag==false){    //第一个障碍点
                                flag=true;
                                min_y=p[x][j][1]-1;
                            }
                            else                //找到距离目前位置最近的障碍点
                                min_y=min(min_y,p[x][j][1]-1);
                        }
                    }
                    if(flag==false) //没有障碍点
                        y+=i;
                    else            //有障碍点
                        y=min_y;
                }
                else if(forward==1){    //向东方向
                    bool flag=false;
                    int min_x=0;
                    for(int j=0;j<q[y].size();j++){ //对相同y坐标的障碍点进行遍历
                        if(y==q[y][j][1]&&((q[y][j][0]>x)&&(q[y][j][0]<=x+i))){
                                if(flag==false){
                                    min_x=q[y][j][0]-1;
                                    flag=true;
                                }                                    
                                else
                                    min_x=min(min_x,q[y][j][0]-1);
                        }
                    }                    
                    if(flag==false)
                        x+=i;
                    else
                        x=min_x;
                }
                else if(forward==2){    //向南方向
                    bool flag=false;
                    int min_y=0;
                    for(int j=0;j<p[x].size();j++){
                        if(x==p[x][j][0]&&((p[x][j][1]<y)&&(p[x][j][1]>=y-i))){
                                if(flag==false){
                                    flag=true;
                                    min_y=p[x][j][1]+1;
                                }
                                else
                                    min_y=max(min_y,p[x][j][1]+1);
                        }
                    }
                    if(flag==false)
                        y-=i;
                    else
                        y=min_y;
                    
                }
                else if(forward==3){    //向西方向
                    bool flag=false;
                    int min_x=0;
                    for(int j=0;j<q[y].size();j++){
                        if(y==q[y][j][1]&&((q[y][j][0]<x)&&(q[y][j][0]>=x-i)))
                            if(flag==false){
                                flag=true;
                                min_x=q[y][j][0]+1;
                            }
                                
                            else
                                min_x=max(min_x,q[y][j][0]+1);
                    }
                    if(flag==false)
                        x-=i;
                    else
                        x=min_x;
                }
                
                if(x*x+y*y>max_distance)    //改变一次位置，就计算欧氏距离
                    max_distance=x*x+y*y;

            }
            
        }
        return max_distance;
    }
};
```

