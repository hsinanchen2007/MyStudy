### 解题思路
首先进行排序 然后双指针 找

### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //首先排序
        sort(nums.begin(), nums.end());

        int start, end;
        int sum = 0;
        int ans = 65535;
        //每一个值
        for (auto i = 0; i < nums.size() - 2; i++)
        {
            //计算他的开始和结束
            start = i + 1;
            end = nums.size() - 1;

            while (start < end)
            {
                //计算值
                sum = nums[i] + nums[start] + nums[end];

                //相等返回
                int error = (sum - target);
                if (error == 0)
                    return sum;
                else if (error > 0)
                    end--;
                else
                    start++;

                //判断
                if (abs(ans - target) > abs(sum - target))
                    ans = sum;
            }
        }

        return ans;
    }
};
```