```
public boolean canJump(int[] nums) {
    int j;
    for (int i = nums.length - 2; i >= 0; --i)
        if (nums[i] == 0) {
            j = -1;
            while (++j < i && nums[j] <= i - j);
            if (j == i)
                return false;
            else
                i = j;
        }
    return true;
}代码块
```
