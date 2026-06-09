### 解题思路
1.每移动1此数组就是将数组中n-1个元素加1，又因为要使数组中的所有元素相等，因此将n-1一个元素加1等效于1个元素减1，上述的元素指的是数组中最大的元素。
2.由此我们可以将题目转述为求每个元素与数组中最小元素差值之和。

### 代码

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        ios::sync_with_stdio(false);
        int a = *min_element(nums.begin(), nums.end());;
        int ans = 0;
        for(int i = 0;i<nums.size();++i){
            ans += (nums[i] - a);
        }
        return ans;
    }
};
```