

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k){
        vector<int>ans;
        if(arr.size()==0)
            return ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<k;i++)
            ans.push_back(arr[i]);
        return ans;

    }
};
```