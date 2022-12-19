```
class Solution {
public:
    int sqr(int a){
        return a*a;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p = {p1,p2,p3,p4};
        sort(p.begin(),p.end());
        //情况1
        if(p[0][0]==p[1][0]){
            if(p[0][0]!=p[2][0] && p[2][0]==p[3][0] && abs(p[0][1]-p[1][1])==abs(p[2][1]-p[3][1]) && abs(p[2][0]-p[0][0])==abs(p[0][1]-p[1][1]) && max(p[0][1],p[1][1])==max(p[2][1],p[3][1])){
                return true;
            }
            return false;
        }
        //情况2
        if(p[1][0]==p[2][0]){
            if(p[1][0]-p[0][0] == p[3][0]-p[2][0] && abs(p[1][1]-p[0][1])==abs(p[3][1]-p[2][1])){
                return true;
            }
            return false;
        }
        //情况3
        if(double(p[0][0]-p[1][0]) * double(p[0][0]-p[2][0])/double(p[0][1]-p[1][1])/double(p[0][1]-p[2][1])==-1 && double(p[0][0]-p[1][0]) * double(p[1][0]-p[3][0])/double(p[0][1]-p[1][1])/double(p[1][1]-p[3][1])==-1 && double(p[1][0]-p[3][0]) * double(p[3][0]-p[2][0])/double(p[1][1]-p[3][1])/double(p[3][1]-p[2][1])==-1){
            if(sqr(p[0][0]-p[1][0])+sqr(p[0][1]-p[1][1])==sqr(p[0][0]-p[2][0])+sqr(p[0][1]-p[2][1]) && sqr(p[0][0]-p[1][0])+sqr(p[0][1]-p[1][1])==sqr(p[1][0]-p[3][0])+sqr(p[1][1]-p[3][1])) return true;
        }
        return false;
    }
};
```
