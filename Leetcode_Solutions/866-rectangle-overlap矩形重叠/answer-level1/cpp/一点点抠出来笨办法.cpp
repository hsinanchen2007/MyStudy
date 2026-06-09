```
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //判断rec1右上角和rec2左下角
        if(rec1[0]<=rec2[0]&&rec2[0]<rec1[2]){
            if(rec2[3]>rec1[3]&&rec2[1]<rec1[3]) return true;
            else if(rec2[3]<rec1[3]&&rec2[3]>rec1[1]) return true;
            else if(rec2[3]==rec1[3]&&rec2[1]<rec1[3]) return true;
            else return false;
        }else if(rec1[0]>=rec2[0]&&rec1[0]<rec2[2]){
            if(rec2[1]<rec1[3]&&rec2[3]>rec1[1]) return true;
            else if(rec2[1]<rec1[1]&&rec2[3]>rec1[3]) return true;
            else if(rec2[3]==rec1[3]&&rec2[1]<rec1[3]) return true;
            else return false;
        }
        else return false;
    }
};
```
