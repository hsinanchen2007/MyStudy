### 解题思路
排序即可

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> res(k,0);
        for(int i=0;i<k;i++)
        {
            res[i]=arr[i];
        }
        return res;

    }
};
```