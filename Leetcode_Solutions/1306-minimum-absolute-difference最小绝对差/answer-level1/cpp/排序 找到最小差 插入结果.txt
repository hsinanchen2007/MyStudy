```
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;  
        sort(arr.begin(),arr.end());  // 排序

        int min_sub = INT_MAX;  // 查找最小差
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i+1] - arr[i] < min_sub)
                min_sub = arr[i+1] - arr[i];
        }

        for(int i=0; i<arr.size()-1; i++){  // 插入结果
            if(arr[i+1] - arr[i] == min_sub)
                res.push_back({arr[i], arr[i+1]});
        }
        return res;
    }
};
```
