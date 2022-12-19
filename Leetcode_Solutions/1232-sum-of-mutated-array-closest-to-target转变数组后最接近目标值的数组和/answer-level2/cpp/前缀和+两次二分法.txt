### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int left  =1;
        int right;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int>presum(n+1,0);
        for(int i=1;i<=n;i++)
        {
            right = max(right,arr[i-1]);
            presum[i] = presum[i-1]+arr[i-1];
        }
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            int sum = binaryseclect(arr,mid,presum);
            if(sum<target) left = mid+1;
            else right = mid-1;
        }
        if(abs(binaryseclect(arr,left,presum) - target)>= abs(binaryseclect(arr,left-1,presum) - target))
            return left-1;
        else{
            return left;
        }
    }
    int binaryseclect(vector<int>&arr,int value,vector<int>&presum)
    {
        int left = 0,right = arr.size()-1;
        int n = arr.size();
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(arr[mid] < value) left = mid+1;
            else right = mid-1;
        }
        if(left ==0) return value*n;
        else{
            return presum[left]+value*(n-left);
        }
    }
};
```