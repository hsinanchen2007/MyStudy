```
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {

        
        int count=0;
        int n = 0;
        for (int i=0; i<light.size(); i++){
            n = max(n, light[i]);
            
            if (n == i+1) count++;
        }
        return count;
    }
};
```
