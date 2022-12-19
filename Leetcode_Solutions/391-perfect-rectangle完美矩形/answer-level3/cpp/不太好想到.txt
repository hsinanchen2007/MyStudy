1. 取得该矩形围成图形的四个顶点，同时求最终围成图形的面积是否与所有矩形之和相等；
2. 取相应矩形的点；
```
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int x1 = INT_MAX;
        int y1 = INT_MAX;
        int x2 = INT_MIN;
        int y2 = INT_MIN;
        int area = 0;
        set<pair<int,int>> points;
        
        for(auto r : rectangles){
            x1 = min(x1,r[0]);
            y1 = min(y1,r[1]);
            x2 = max(x2,r[2]);
            y2 = max(y2,r[3]);
            
            area += abs(r[2]-r[0])*abs(r[3]-r[1]);
            pair<int,int> p1 = make_pair(r[0],r[1]);
            pair<int,int> p2 = make_pair(r[0],r[3]);
            pair<int,int> p3 = make_pair(r[2],r[1]);
            pair<int,int> p4 = make_pair(r[2],r[3]);
            
            if(!points.count(p1)){
                points.insert(p1);
            }else{
                points.erase(p1);
            }
            if(!points.count(p2)){
                points.insert(p2);
            }else{
                points.erase(p2);
            }
            if(!points.count(p3)){
                points.insert(p3);
            }else{
                points.erase(p3);
            }
            if(!points.count(p4)){
                points.insert(p4);
            }else{
                points.erase(p4);
            }
        }
        
        if(area != abs(x2-x1)*abs(y2-y1)){
            return false;
        }
        
        if(points.count(make_pair(x1,y1))&&
           points.count(make_pair(x1,y2))&&
           points.count(make_pair(x2,y1))&&
           points.count(make_pair(x2,y2))&&
           points.size() == 4){
            return true;
        }else{
            return false;    
        }
    }
};
```