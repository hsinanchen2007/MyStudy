### 解题思路
求A、B俩数组的公共元素，注意重复元素结果中只出现一次；
将A、B元素排序，注意判断元素较少者中的每一元素是否在元素较多者中出现，用二分法判断；相同元素在结果中只出现一次。

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        auto n1 = nums1.size();
        auto n2 = nums2.size();
        vector<int>& big = (n1>n2 ? nums1 : nums2);
        vector<int>& small = (n1<n2 ? nums1 : nums2);
        sort(big.begin(), big.end());
        sort(small.begin(), small.end());

        vector<int> both;
        for(auto i : small)
        {
            if(has(big, i) && !has(both, i))
                both.push_back(i);
        }
        return both;
    }
private:
    bool has(vector<int>& nums, int x);
};

bool Solution::has(vector<int>& nums, int x)
{
    int left = 0;
    int right = nums.size()-1;
    while(left <= right)
    {
        int middle = (left+right)/2;
        if(nums[middle] == x)
            return 1;
        else if(x < nums[middle])
            right = middle-1;
        else
            left = middle+1;
    }
    return 0;
}
```