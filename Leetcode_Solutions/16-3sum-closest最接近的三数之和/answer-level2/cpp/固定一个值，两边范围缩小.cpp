```
int threeSumClosest(vector<int>& nums, int target) {
        //  先排序
        sort(nums.begin(), nums.end());
        //  固定一个位置两边范围缩小
        //  记录绝对值最小的插值
        int min = INT32_MAX, cur;
        for (int j = 1, i, k; j < nums.size() - 1; ++j) {
            i = 0;
            k = nums.size() - 1;
            while (i < j && j < k) {
                cur = nums[i] + nums[j] + nums[k] - target;
                min = abs(cur) < abs(min) ? cur : min;
                if (cur < 0) i++;
                if (cur > 0) k--;
                if (cur == 0) return target;
            }
        }
        return min + target;
    }
```