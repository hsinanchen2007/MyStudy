### 解题思路
其实就是比较简单的二分法，唯一区别在于当找到mid以后，延伸向两侧寻找有效数字的起始位(st)和结束位(end)

### 代码

```cpp
class Solution {
public:
   vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> count;
        int left = 0, right = nums.size() - 1;
        while (left <= right)   //这里为小于等于因为考虑输入nums的size为1
        {
            int mid = left + ((right - left) >> 1);
            if (nums[left] > target || nums[right] < target)
                break;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
            {
                int st = mid, end = mid;
                while (st >= left && target == nums[st])
                    st--;
                while (end <= right && target == nums[end] )
                    end++;
                count.push_back(++st);
                count.push_back(--end);
                return count;
            }
        }
        return vector<int>{-1, -1};
    }
};
```