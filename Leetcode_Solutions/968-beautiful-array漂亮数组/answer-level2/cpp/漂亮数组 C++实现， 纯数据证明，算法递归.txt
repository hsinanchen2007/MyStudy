依次递归

    1,
    1,2,
    1,3,2,4
左半边部分 x*2-1，右半部分 x*2 递归分解。

```cpp
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> ret, left, right;
        if (N == 1) { return {1}; }
        left = beautifulArray((N+1)/2);
        for (int i = 0; i < left.size(); i++) { ret.push_back(left[i]*2-1); }
        right = beautifulArray(N/2);
        for (int i = 0; i < right.size(); i++) { ret.push_back(right[i]*2); }
        return ret;
    }
};
```

以下错误的实现，虽然也是漂亮数组，但不是1~N
```cpp
class Solution {
public:
    vector<int> beautifulArray_Invalid(int N) {
        vector<int> ret{1};
        auto size = ret.size();
        while((size = ret.size()) < N) {
            vector<int> right(ret);
            for (int i = 0; i< size; i++) { right[i] = right[i]*2; }
            vector<int> &left = ret;
            for (int i = 0; i< size; i++) { left[i] = left[i]*2 -1; }
            for(int i = 0; i + size < N && i < size; i++) { left.push_back(right[i]); }
        }
        return ret;
    }
};
```

