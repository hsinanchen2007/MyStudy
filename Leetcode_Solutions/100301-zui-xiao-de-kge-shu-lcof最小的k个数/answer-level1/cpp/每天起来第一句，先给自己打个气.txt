### 解题思路
看到vector容器，再看题目找到k个小的数，就想到了sort排序，默认是从小到大排序，然后把前k个数输出就好了

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> arr1;
        for(int i=0;i<k;i++){
            arr1.push_back(arr[i]);
        }
        return arr1;
    }
};
```