![result.jpg](https://pic.leetcode-cn.com/9084e0231335f93b975b4a04fc07bd34830fd7f2f55035a9e09a4db51ff75d66-result.jpg)
思路比较常规，还望大佬多指点

```
        List<String> result = new ArrayList<>();
        if (nums.length == 0) {
            return result;
        }
        if (nums.length == 1) {
            result.add(String.valueOf(nums[0]));
            return result;
        }
        int start = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int cur = nums[i];
            if (cur == nums[i - 1] + 1) {
                if (i == nums.length - 1) {
                    result.add(start + "->" + cur);
                }
                continue;
            }
            if (start != nums[i - 1]) {
                result.add(start + "->" + nums[i - 1]);
            }else{
                result.add(String.valueOf(start));
            }
            start = cur;
            if (i == nums.length - 1) {
                if (cur == nums[i - 1] + 1) {
                    result.add(start + "->" + cur);
                }else{
                    result.add(String.valueOf(cur));
                }
            }
        }
        return result;
```

