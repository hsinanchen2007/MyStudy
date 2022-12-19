```
int searchInsert(vector<int>& nums, int target) {
        int i = 0;

        while (i < nums.size() && nums[i] < target) ++i;

        return i;
    }
```

直接遍历，虽然耗时比较高，但好理解。
最重要的是不管超没超出边界，有没有，只要返回第一个比target大或者等于target的就行
