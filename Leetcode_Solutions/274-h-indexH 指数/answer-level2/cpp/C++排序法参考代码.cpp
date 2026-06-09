```
class Solution {
private:
    static bool cmp(int a, int b){
        return a > b;
    }
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)   return 0;
        sort(citations.begin(), citations.end(), cmp);
        int i;
        for(i = 1; i <= citations.size(); i++)
            if(i > citations[i-1])
                break;
        return i-1;
    }
};
```
