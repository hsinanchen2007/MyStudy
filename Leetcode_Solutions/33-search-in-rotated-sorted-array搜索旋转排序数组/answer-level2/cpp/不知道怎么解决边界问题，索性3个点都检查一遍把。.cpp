### 解题思路
不知道怎么解决边界问题，索性3个点都检查一遍把。

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, mid, pos = -1;//左，右，中间，结果
        while (i <= j)
        {
            mid = (i + j) / 2;
            //左中右检查一遍
            if (nums[mid] == target)
            {
                pos = mid;
                break;
            }
            if (nums[i] == target)
            {
                pos = i;
                break;
            }
            if (nums[j] == target)
            {
                pos = j;
                break;
            }
            //分4种情况找分界
            if (nums[i] < nums[mid])
            {
                if (nums[i] < target && target < nums[mid])
                {
                    j = mid - 1;
                }
                else
                {
                    i = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target < nums[j])
                {
                    i = mid + 1;
                }
                else 
                {
                    j = mid - 1;
                }
            }
        }
        return pos;
    }
};
```