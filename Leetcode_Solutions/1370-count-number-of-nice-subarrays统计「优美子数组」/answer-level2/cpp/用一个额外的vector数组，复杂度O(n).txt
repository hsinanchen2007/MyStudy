### 解题思路
观察可以发现，假设一个包含k个奇数的连续数组，它与上一个奇数的距离为left，与下一个奇数的距离为right，那么此连续数组的子数组有left*right个，因为左边有left种情况，右边有right种。利用一个额外的数组存储奇数的位置，一次遍历得到结果。
![image.png](https://pic.leetcode-cn.com/50e2ed64f29b9b08a59cad2557f41e6b6e0dca10549ec15a873e2ad5304b3587-image.png)

### 代码

```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 0)   //数组长度为0，直接返回0
        return 0;
        vector<int> odd;
        int ans = 0;
        for(int i = 0; i < len; i ++)
        if(nums[i] % 2 == 1)
          odd.push_back(i);
        if(odd.size() < k)  //如果奇数个数小于k，返回0
        return ans;
        for(int left = 0; left + k - 1 < odd.size(); left ++)
        {
            int lefts, rights, right;
            right = left + k - 1;
            if(left == 0)  //第1个奇数的情况单独讨论
            lefts = -1;
            else 
            lefts = odd[left - 1];
            if(right == odd.size() - 1)  //最后一个奇数的情况也要单独讨论
            rights = len;
            else
            rights = odd[right + 1];
            ans += (odd[left] - lefts)*(rights - odd[right]);
        }
    return ans;
    }
};
```