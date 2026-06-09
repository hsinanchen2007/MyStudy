```
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int size = citations.size();
        int res = 0;
        int preMax = 0;
        for (int i = 0; i < size; i++) {
            if ((preMax <= size - i) && (size - i <= citations[i])) {
                int h = size - i;
                res = max(h, res);
            }
            preMax = max(preMax, citations[i]);
        }
        return res;
    }
};
```
