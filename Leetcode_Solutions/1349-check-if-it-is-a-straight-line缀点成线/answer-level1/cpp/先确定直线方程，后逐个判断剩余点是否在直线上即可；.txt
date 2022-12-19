```
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int k,b;
        if(coordinates[0][0]-coordinates[1][0]==0) k=0;
        else k=(coordinates[0][1]-coordinates[1][1])/(coordinates[0][0]-coordinates[1][0]);
        b=coordinates[1][1]-k*coordinates[1][0];
        for(int i=2;i<coordinates.size();++i){
            if(coordinates[i][1]!=k*coordinates[i][0]+b) return false;
        }
        return true;
    }
};
```
