

![1573132143(1).png](https://pic.leetcode-cn.com/eeb93c0283e5235f6a60d947287661919637f2e9c2a348d47d8adf65d6e614f8-1573132143\(1\).png)

思路：如果存在跳不过去的点的话，那么数组中必然至少存在一个点的值为0，并且0之前的所有点都无法跳过这个点。所以这里遍历这个数组，找到值为0的点。找到值为0的点后，向前依次查找能跳过这个点的点，如果查找不到，那就证明这里无法跳过去。如果找到了，那么就继续向下查找下一个0。(最后一个点的值可以忽略)


```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] == 0){
                int max = 1, j = i - 1;
                for(; j >= 0 && nums[j] <= max; --j){
                    ++max;
                }
                if(j == -1) return false;
            }
        }
        return true;
    }
};
```

