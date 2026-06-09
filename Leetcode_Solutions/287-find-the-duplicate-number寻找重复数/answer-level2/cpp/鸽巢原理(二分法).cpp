### 解题思路
先限定范围为[1,n],取得中点mid,那么[1,mid]的个数上限为mid个，若超过mid个，说明重复的数位于[1,mid]，否则位于[mid+1,n]

### 代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1,right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int num : nums)
                if (num <= mid) ++count;
            if(count > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
```