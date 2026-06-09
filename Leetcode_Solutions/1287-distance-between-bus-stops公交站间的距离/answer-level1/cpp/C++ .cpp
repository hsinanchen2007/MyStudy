```
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0;
        int clockwise = 0;
        if(start > destination)
            return distanceBetweenBusStops(distance, destination, start);
        for(int i=0; i<distance.size(); ++i)
        {
            sum += distance[i];
            if(i >= start && i < destination)
                clockwise += distance[i];
        }
        return min(clockwise, sum-clockwise);
    };
};
```