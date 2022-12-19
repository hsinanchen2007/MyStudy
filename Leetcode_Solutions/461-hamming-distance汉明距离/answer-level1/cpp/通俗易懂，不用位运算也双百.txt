

```
class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        while(x > 0 || y > 0){
            x%2 == y%2?distance:distance++;
            x = x/2;
            y =y/2;
        }
        return distance;
    }
};
```
