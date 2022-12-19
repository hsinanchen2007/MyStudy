```
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int i = start;
        int n1 = 0;
        int n2 = 0;
        while(i != destination)
        {
            n1 += distance[i];
            i = (i+1) % distance.size();
        }
        i = destination;
        while(i != start)
        {
            n2 += distance[i];
            i = (i+1) % distance.size();
        }
        return min(n1, n2);
    }
};
```
