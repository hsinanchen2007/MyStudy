```
class Solution {
public:
    vector<int> printNumbers(int n) {
        int target = pow(10, n);
        vector<int> res(target-1);
        for(int i=0; i<target-1; i++) {
            res[i] = i + 1;
        }
        return res;
    }
};
```
