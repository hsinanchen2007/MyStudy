利用哈希表记录过去的值。看过去是否存在该值的上一个等差值。
```
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        if(arr.size() < 2)
            return arr.size();
                
        int n = arr.size();
        unordered_map<int,int> map;
        map[arr[0]] = 1;
        int ret = 1;
        for(int i = 1; i < n; ++i)
        {
            int tmp = 1;
            if(map.find(arr[i] - difference) != map.end())
                tmp = map[arr[i] - difference] + 1;
            
            map[arr[i]] = max(tmp,map[arr[i]]);
            ret = max(map[arr[i]],ret);
        }
        
        return ret;
    }
};
```
