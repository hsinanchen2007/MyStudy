```
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0, rid = 0;
        for(int dist:distance) sum += dist;
        if(start > destination) swap(start, destination);
        for(int i=start; i<destination; i++) rid += distance[i];
        return min(rid, sum - rid);
    }
};
```
