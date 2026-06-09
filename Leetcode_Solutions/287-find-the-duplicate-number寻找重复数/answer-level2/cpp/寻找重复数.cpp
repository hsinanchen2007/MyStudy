### 解题思路
抽屉原理 + 二分法

### 代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //nums.size() -> n + 1,所以r -> n
        int l = 1,r = nums.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            int cnt = 0;
            for(auto x : nums)
                if(x >= l && x <= mid)
                    cnt++;
            //若[l,mid]区间小于落于该区间的数字数目，则[l,mid]该区间必定有重复数，更新r
            if(cnt > mid - l + 1) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};
```