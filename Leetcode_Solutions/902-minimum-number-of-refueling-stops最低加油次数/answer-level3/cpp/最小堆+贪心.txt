```
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target,0});
        priority_queue<int> pq;
        int ans=0;
        int last_pos=0,leftFuel=startFuel;
        for(int i=0;i<stations.size();++i){
            leftFuel-=(stations[i][0]-last_pos);
            if(leftFuel>=0){
                pq.push(stations[i][1]);
            }
            else{
                while(leftFuel<0&&!pq.empty()){
                    ++ans;
                    leftFuel+=pq.top();
                    pq.pop();
                }
                if(leftFuel<0){
                    return -1;
                }
                pq.push(stations[i][1]);
            }
            last_pos=stations[i][0];
        }
        return ans;
    }
};
```
