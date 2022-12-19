### 思路
    直接套母函数模板即可，目标值是 nums 求和的一半，如果和是奇数可以直接返回 false
### 代码
```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &num: nums) sum += num;
        const int64_t M = 1e9+7;
        if(sum%2) return false;
        int target = sum/2;
        int size = (target+1)*sizeof(int);
        int *a = (int*)malloc(size);
        int *b = (int*)malloc(size);
        memset(a, 0, size);
        memset(b, 0, size);
        a[0] = 1;
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<=1&&j*nums[i]<=target; ++j){
                for(int k=0; k+j*nums[i]<=target; ++k)
                    b[(k+j*nums[i])%M] += a[k]%M;
            }
            memcpy(a, b, size);
            memset(b, 0, size);
        }
        int res = a[target%M];
        free(a);  free(b);
        return res;
    }
};
```
