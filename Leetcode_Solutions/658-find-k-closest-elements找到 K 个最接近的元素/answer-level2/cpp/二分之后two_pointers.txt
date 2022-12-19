### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int nearest = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = nearest - 1, right = nearest;
        int cnt = 0;
        while(left >= 0 && right < arr.size() && cnt < k)
        {
            if(abs(arr[left] - x) <= abs(arr[right] - x))
            {
                ans.push_back(arr[left]);
                left--;
            }
            else
            {
                ans.push_back(arr[right]);
                right++;
            }
            cnt++;
        }
        while(left >= 0 && cnt < k)
        {
            ans.push_back(arr[left]);
            left--;
            cnt++;
        }
        while(right < arr.size() && cnt < k)
        {
            ans.push_back(arr[right]);
            right++;
            cnt++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```