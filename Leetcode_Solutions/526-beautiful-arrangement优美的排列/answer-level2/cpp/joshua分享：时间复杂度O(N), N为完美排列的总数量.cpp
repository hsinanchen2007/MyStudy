### 解题思路
joshua分享：在暴力方法中，我们产生了所有可能的排列并对每一个排列都进行了可除性检查。此方法中，我们可以稍做优化。我们将每个元素添加到数组最后面的时候，我们马上进行可除性检查，一旦发现当前元素和位置不满足要求我们就不能将这个元素放在当前位置，即可换一个元素继续判断

### 代码

```cpp
class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums;

        for(int i = 0; i < N; i++) nums.push_back(i+1);
        product(nums, 0);
        return count;
    }
    void product(vector<int> &nums, int pos) {
        int i;
        if(pos == nums.size()) {
            /*
            for(i = 0; i < nums.size(); i++)
                if(nums[i]%(i+1) != 0 && (i+1)%nums[i] != 0) break;
            */
            //if(i == nums.size()) 
                count++;
        }
        for(i = pos; i < nums.size(); i++) {

            swap(nums[pos], nums[i]);

            // 满足要求的才继续递归
            if(nums[pos] % (pos+1) == 0 || (pos+1) % nums[pos] == 0)
                product(nums, pos+1);

            swap(nums[pos], nums[i]);
        }
    }
private:
    int count = 0;
};
```