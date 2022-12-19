### 解题思路
手动建堆，用时击败99.8%？？？

### 代码

```cpp
class Solution {
public:
    void percolate(vector<int>& arr, int idx, int n) {
        if (idx*2+2 < n && (arr[idx]<arr[idx*2+1]|| arr[idx]<arr[idx*2+2])) {
            if (arr[idx*2+1]>arr[idx*2+2]) {
                swap(arr[idx], arr[idx*2+1]);
                percolate(arr, idx*2+1, n);
            }
            else {
                swap(arr[idx], arr[idx*2+2]);
                percolate(arr, idx*2+2, n);
            }
        }
        else if (idx*2+1<n && arr[idx]<arr[idx*2+1]) {
            swap(arr[idx], arr[idx*2+1]);
            percolate(arr, idx*2+1, n);
        }
    }
    int pop(vector<int>& arr, int n) {
        int ans = arr[0];
        arr[0] = arr[n-1];
        percolate(arr, 0, n-1);
        return ans;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int idx = nums.size()/2-1;
        while (idx >= 0) {
            percolate(nums, idx, nums.size());
            idx--;
        }
       // for (int i=0;i<nums.size();i++) cout<<nums[i]<<endl;
        int cnt = 0;
        while (cnt<k-1) {
            pop(nums, nums.size()-cnt);
            cnt++;
        }
        return nums[0];
    }
};
```