```
class Solution {
public:
    vector<int> ans;
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());//调用sort，从小到大排序
        for(int i=0;i<k;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

```
