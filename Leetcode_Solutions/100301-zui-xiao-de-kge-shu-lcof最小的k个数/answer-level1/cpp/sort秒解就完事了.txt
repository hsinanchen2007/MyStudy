### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> min(k,0);
        for(int i=0;i<k;i++)
            min[i]=arr[i];
        return min; 
    }
};
```