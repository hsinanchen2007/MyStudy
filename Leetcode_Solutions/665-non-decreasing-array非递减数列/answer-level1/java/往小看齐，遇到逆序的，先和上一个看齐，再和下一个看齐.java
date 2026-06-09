![image.png](https://pic.leetcode-cn.com/4ca60412594aecb40fe95fae9f4177cf7f2e7107cd09934c5bb0a68f975fe08e-image.png)

```
    int cnt = 0;
    for(int i = 0; i < nums.length - 1; i++) {
        if(nums[i] > nums[i + 1]) {
            int tmp = nums[i];
            if(i >= 1) {
                nums[i] = nums[i - 1];
            } else {
                nums[i] = nums[i + 1];
            }
            if(nums[i] > nums[i + 1]) {
                nums[i] = tmp;
                nums[i + 1] = nums[i];
            }
            cnt++;
            if(cnt == 2) {
                return false;
            }
        }
    }
    return true;
```
