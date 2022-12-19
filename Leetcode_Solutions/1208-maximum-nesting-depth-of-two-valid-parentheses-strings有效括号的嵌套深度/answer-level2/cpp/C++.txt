
```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int index = 0;
        for (char c: seq) {
            if (c == '(') {
                index ++;
                res.push_back(index%2);
            } else {
               res.push_back(index%2);
                index --;
            }
        }
        return res;
    }
};
```
