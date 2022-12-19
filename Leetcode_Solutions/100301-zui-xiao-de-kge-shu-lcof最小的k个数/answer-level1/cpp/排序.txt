### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
         vector<int> res;
        if(k<=0)
        return res;
       
        sort(arr.begin(),arr.end());
        for(int i=0;i<k;i++)
        res.push_back(arr[i]);

        return res;
    }
};
```