```
class Solution {
    vector<int> v;
public:
    Solution(vector<int>& w) {
        int sum=0;
        for(int i=0;i<w.size();++i){
            sum+=w[i];
            v.push_back(sum);
        }
    }
    
    int pickIndex() {
        
        int a=rand();
        int num=a%(*v.rbegin());
        int ans=upper_bound(v.begin(),v.end(),num)-v.begin();
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
```
