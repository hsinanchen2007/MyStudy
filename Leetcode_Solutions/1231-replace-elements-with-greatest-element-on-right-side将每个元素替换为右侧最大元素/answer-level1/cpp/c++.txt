# c++

```
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> store(arr.size(), 1);
        int len = arr.size();
        int rightMax = arr[len-1];
        store[len-1] = -1;
        for(--len ; len >= 0; len--){
            store[len] = rightMax;
            rightMax = max(rightMax, arr[len]);
        }
        store[store.size()-1] = -1;
        return store;
    }
};
```

执行用时 :
20 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
11.8 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

