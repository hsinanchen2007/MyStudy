### 解题思路
查找k-diff数对时，保证前数大于后数。
为了保证k-diff不重复，我们对每个k-diff数组中的最大值进行标记，将k-diff中前数的value 设为1.

### 代码

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;

        if(k < 0)//好坑不止有-1 还有-157
            return 0;

        if(k == 0) {
        //当k=0时，其实就是找数组中有没有重复元素 且重复元素个数大于等于2时 我们都视为只有1组K-diff
            for(int i = 0; i < nums.size(); i++) {
            ++map[nums[i]];
            if(map[nums[i]] == 2)
                count++;
            }
            return count;
        }
        //k为其他数字时，先构建hash表，将value初始化为0.
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] = 0;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(map.find(nums[i] - k) != map.end()) {
            //若nums[i]-k存在于数组中。注：nums[i]-k必然小于nums[i] diff数对为{num[i], nums[i]-k}
                if(map[nums[i]] == 0 ) {//已经存在的diff数对中还没有出现过nums[i]为第一个数
                    count++;//数对数量+1
                    map[nums[i]] = 1;//给nums[i]标记，表示已经有nums[i]开头的数对了，后面不再考虑
                }
            }
        }
        return count;
    }
};
```