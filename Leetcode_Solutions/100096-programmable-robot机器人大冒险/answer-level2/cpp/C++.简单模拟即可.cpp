**执行用时 :8 ms, 在所有 cpp 提交中击败了69.24% 的用户
内存消耗 :14.8 MB, 在所有 cpp 提交中击败了100.00%的用户**
1.如果终点没在路径上直接返回false.
2.将障碍物在路上的扫一次，如果障碍物在终点之前出现，则返回false。
3.最后如果所有障碍物都没有则返回true
```
#define vec vector<vector<int>>
#define ll long long
class Solution {
public:
    //思路：1.如果障碍不在路上则判断终点
    //2.如果障碍在路上，判断障碍与终点的相对位置
    
    bool ok(string s,int inx,int iny,int x,int y){//直接推不出来那就。。。
        int mod1=x,mod2=y;
        int k=x/inx;
        mod1=x-k*inx;
        mod2=y-k*iny;
        int x=0,y=0;
        if(x==mod1&&y==mod2)return true;
        for(int i=0;i<command.size();i++){
            if(command[i]=='U')y++;
            else
                x++;
            if(x==mod1&&y==mod2)return true;
        }
        return false;
    }
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int inx=0,iny=0;
        for(int i=0;i<command.size();i++){
            if(command[i]=='U')
                iny++;
            else
                inx++;
        }
        int n=obstacles.size();
        if(!ok(command,inx,iny,x,y))return false;
        vec ans;
        for(int i=0;i<n;i++){
            int a=obstacles[i][0],b=obstacles[i][1];
            if(ok(command,inx,iny,a,b))
                ans.push_back({a,b});
        }
        if(ans.empty())return true;
        for(auto &e: ans){//判断相对位置
            if(e[0]<=x&&e[1]<=y)return false;
        }
        return true;
    }
};
```
