```c++ []
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int sum = 0;
        vector<int> left(n+1,0);
        
        if(start == destination){
            return 0;
        }
        
        for(int i = 0;i < n; ++i){
            sum += distance[i];
            left[i+1] = sum;
        }
        
        
        if(start > destination){
            swap(start,destination);
        }
        
        return min(left[destination] - left[start],sum-(left[destination] - left[start]));
    }
};
```
```java []
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int n = distance.length;
        int[] left = new int[n+1];
        int sum = 0;
        int rest = 0;
        
        for(int i = 0;i < n; ++i){
            sum += distance[i];
            left[i+1] = sum;
        }
        
        if(start == destination){
            return 0;
        }
        
        if(start < destination){
            rest = left[destination]-left[start];
        }else{
            rest = left[start]-left[destination];
        }
        return Math.min(rest,sum-rest);
    }
}
```
```python []
python:

class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        n = len(distance)
        if start == destination:
            return 0
        
        if start > destination:
            start,destination = destination,start
        
        if start == 0:
            rest = sum(distance[0:destination])
        else:
            rest = sum(distance[0:destination]) - sum(distance[0:start])
    
        return min(sum(distance[0:n])-rest,rest)
```