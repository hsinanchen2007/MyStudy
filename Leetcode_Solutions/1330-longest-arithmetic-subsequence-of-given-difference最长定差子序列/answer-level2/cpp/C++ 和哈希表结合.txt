```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> hash;
        int ans = 1;
        for(auto&e:arr){
            hash[e] = hash[e-difference] +1;
            ans = max(ans, hash[e]);
        }
        return ans;
    }
};
```