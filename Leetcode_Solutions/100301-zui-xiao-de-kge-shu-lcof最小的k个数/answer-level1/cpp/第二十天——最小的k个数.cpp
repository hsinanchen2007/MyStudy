### 解题思路
使用冒泡排序，时间复杂度较差

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        if(0==k) return ans;

        int i=0, j=arr.size()-1;
        while(i < k){
            j = arr.size()-1;
            while(j > i){
                if(arr[j-1] >= arr[j]) swap(arr[j-1], arr[j]);
                j--;
            }
            ans.push_back(arr[i++]);
        }
        return ans;
    }
};
```