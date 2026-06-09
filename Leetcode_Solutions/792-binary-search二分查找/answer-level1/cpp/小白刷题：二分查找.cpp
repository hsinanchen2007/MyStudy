送分题，二分查找

代码：
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int start = 0, finish = len - 1;
        while (finish - start > 1) {
            int middle = (start + finish) / 2;
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] > target)
                finish = middle;
            else
                start = middle;
        }
        if (nums[start] == target)
            return start;
        else if (nums[finish] == target)
            return finish;
        else
            return -1;
    }
};
```
