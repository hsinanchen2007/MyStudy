```cpp
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int c_size=coordinates.size();
        if(c_size<3)return true;
        for(int i=0;i<c_size-2;++i){
            if((coordinates[i][0]-coordinates[i+1][0])*(coordinates[i+1][1]-coordinates[i+2][1])!=(coordinates[i+1][0]-coordinates[i+2][0])*(coordinates[i][1]-coordinates[i+1][1]))return false;
        }
        return true;
    }
};
```