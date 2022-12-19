### 解题思路
reindex[i] = 插入位置原位置index[i]+后面index <= i的元素个数

在考虑有没有低于O(n^2)的解法

### 代码

```cpp
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        // 插入位置原位置+后面index <= i的元素个数
        int N = nums.size();
        vector<int> reindex = index;
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                if(index[j] <= reindex[i]) reindex[i]++;
            }
        }
    
        vector<int> res(N, 0);
        for(int i = 0; i < N; i++){
            // cout << reindex[i] << " ";
            res[reindex[i]] = nums[i];
        }
        return res;
    }
};
```