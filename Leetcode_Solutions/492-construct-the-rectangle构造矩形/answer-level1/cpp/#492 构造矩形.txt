    class Solution {
    public:
        vector<int> constructRectangle(int area) {
            //看了别人题解发现我这个有点捞
            //算是中规中矩暴力法了
            vector<int> result;
            int dist = 0, mindist =INT_MAX;
            int minL = 0, minW = 0;
            for(int i=1; i*i<=area; i++){
                if(area % i == 0){
                    dist = area/i - i;
                    if(dist < mindist){
                        minL = area/i;
                        minW = i;
                        mindist = dist;
                    }
                }
            }
            result.push_back(minL);
            result.push_back(minW);
            return result;
        }
    };