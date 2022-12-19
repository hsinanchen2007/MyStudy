和上一个题一样，还是要逼近思想，但是由于不用记录三个数的位置，所以不需要去重，三个数不断逼近target，大了end指针左移，小了start指针右移。

```
    Arrays.sort(nums);
    int ans = nums[0] + nums[1] + nums[2];
    for(int i=0;i<nums.length;i++) {
        int start = i+1, end = nums.length - 1;
        while(start < end) {
            int sum = nums[start] + nums[end] + nums[i];
            if(Math.abs(target - sum) < Math.abs(target - ans))
                ans = sum;
            if(sum > target)
                end--;
            else if(sum < target)
                start++;
            else
                return ans;
        }
    }
    return ans;
```