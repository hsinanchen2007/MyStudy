### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int pivot = arr[n - 1],tmp;
        arr[n - 1] = -1;
        for(int i = n - 2;i >= 0;i--){
            tmp = arr[i];
            arr[i] = max(pivot,arr[i+1]);
            pivot = tmp;
        }
        return arr;
    }
};
```